//
//  Project - VidyoIntegration
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#import "VidyoTypes.h"
#import "VidyoClient.h"
#import "NSString+Base64.h"
#import "VidyoWrapper.h"
#import "VidyoEventBridge.h"

#pragma mark - Private Interface
@interface VidyoWrapper() <NSXMLParserDelegate, UIAlertViewDelegate>

@property (nonatomic) BOOL entityIDResult;
@property (nonatomic) BOOL memberStatusResult;
@property (nonatomic) BOOL didEverGoToBackground;
@property (nonatomic, assign) unsigned lastKnownOrientation;

@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) NSMutableString *vidyoEntityID;
@property (nonatomic, strong) NSMutableData *webData;
@property (nonatomic, strong) NSXMLParser *xmlParser;
@property (nonatomic, strong) NSMutableString *vidyoMemberStatus;
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;

@property (nonatomic, strong) NSString *serverURL;
@property (nonatomic, strong) NSString *serverName;
@property (nonatomic, strong) NSString *serverPass;

@end

#pragma mark - Implementation
@implementation VidyoWrapper

#pragma mark - Lifecycle
+ (id)sharedInstance {
    static VidyoWrapper *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (id)init {
    if(self = [super init]) {
        self.didEverGoToBackground = NO;
        
        self.serverURL = @"http://dev20.vidyo.com";
        self.serverName = @"marina";
        self.serverPass = @"marina";
        // self.suppressAlerts = YES;
        
        self.window = [[[UIApplication sharedApplication] delegate] window];
        
        // initialize Vidyo client
        [self clientInit];
        // Add subcription for orientation change notifications
        [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(orientationDidChange:)
                                                     name:@"UIDeviceOrientationDidChangeNotification"
                                                   object:nil];
        // Add subscription for application modes notifications
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(appDidBecomeActive)
                                                     name:@"UIApplicationDidBecomeActiveNotification"
                                                   object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(appWillResignActive)
                                                     name:@"UIApplicationWillResignActiveNotification"
                                                   object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(appWillTerminate)
                                                     name:@"UIApplicationWillTerminateNotification"
                                                   object:nil];
    }
	return self;
}

- (void)loginWithURL:(NSString *)url userName:(NSString *)userName password:(NSString *)password {

    self.entityIDResult = FALSE;
	self.memberStatusResult = FALSE;
	self.isJoiningConference = FALSE;
    self.vidyoMemberStatus = nil;
    
    /* If portal URL does not start with schema than put it there explicetly */
	if(!([url hasPrefix:@"http://"] || [url hasPrefix:@"https://"])) {
        url = [NSString stringWithFormat:@"http://%@",url];
    }
    
    // Initaite the local sign in process
    VidyoClientInEventLogIn event = {0};
    NSString *userVPortal = self.serverURL;
    NSString *userVName = self.serverName;
    NSString *userVPass = self.serverPass;
    
    strlcpy(event.portalUri, [userVPortal UTF8String], sizeof(event.portalUri));
    strlcpy(event.userName, [userVName UTF8String], sizeof(event.userName));
    strlcpy(event.userPass, [userVPass UTF8String], sizeof(event.userPass));
    
    /* Create and show a wait alert */
    [self createToastAlertWithMessage:@"Signing in\nPlease Wait..."];
    
    // send login-event to VidyoClient
    self.webData = [NSMutableData data];
    if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_LOGIN, &event, sizeof(VidyoClientInEventLogIn)) == false) {
        [self dismissToastAlert];
        [self createStandardAlertWithTitle:@"Failed to Sign In" andMessage:@""];
    } else {
        // Sign in in progress
        self.isSigningIn = TRUE;
    }
}

- (void)joinConferenceWithURL:(NSString *)baseURL {
	/* The joinConference is broken into 2 steps
	 * Step1: get the entityID from VidyoPortal using WS User::myAccount() API
	 * Step2: if entityID is successfully retrieved and the entity is 'online', do WS User::joinConference
	 */
    
    self.entityIDResult = FALSE;
	self.memberStatusResult = FALSE;
	self.isJoiningConference = FALSE;
    
    NSString *urlString = [NSString stringWithFormat:@"%@/services/v1_1/VidyoPortalUserService?wsdl",self.serverURL];
    NSURL *url = [NSURL URLWithString:urlString];
	NSMutableURLRequest *theRequest = [NSMutableURLRequest requestWithURL:url];
    
	// Get the EntityId from VidyoPortal using WS User::myAccount
	NSString *soapMessage = [NSString stringWithFormat:
	                         @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
	                         "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/user/v1_1\">"
	                         "<env:Body>"
	                         "<ns1:MyAccountRequest/>"
	                         "</env:Body>"
	                         "</env:Envelope>"];
    
	NSString *msgLength = [NSString stringWithFormat:@"%d", [soapMessage length]];
	[theRequest addValue:@"application/soap+xml; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
	[theRequest addValue:@"myAccount" forHTTPHeaderField:@"SOAPAction"];
	[theRequest addValue:msgLength forHTTPHeaderField:@"Content-Length"];
    NSString *base64 = [[NSString stringWithFormat:@"%@:%@",_serverName,_serverPass] base64];
    NSString *auth = [NSString stringWithFormat:@"Basic %@", base64];
    [theRequest addValue: auth forHTTPHeaderField:@"Authorization"];
	[theRequest setHTTPMethod:@"POST"];
	[theRequest setHTTPBody:[soapMessage dataUsingEncoding:NSUTF8StringEncoding]];
    
    self.isJoiningConference = TRUE;
    [self createToastAlertWithMessage:@"Joining Conference\nPlease Wait..."];
    
	NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:theRequest delegate:self];
	if (theConnection) {
		self.webData = [NSMutableData data];
	} else {
		logMsg(@"The Connection is NULL");
	}
	logMsg(@"****SENT SOAP Request myAccount()****");
}

#pragma mark - Alert Display Methods
- (void)createToastAlertWithMessage:(NSString *)message {
    if (!self.suppressAlerts) {
        dispatch_async(dispatch_get_main_queue(), ^{
            self.userAlert = [[UIAlertView alloc] initWithTitle:message
                                                        message:nil
                                                       delegate:self
                                              cancelButtonTitle:nil
                                              otherButtonTitles: nil];
            // Add an activity indicator view to show progress
            self.activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
            // Adjust the indicator so it is up a few pixels from the bottom of the alert
            self.activityIndicator.center = CGPointMake(self.userAlert.bounds.size.width / 2,
                                                        self.userAlert.bounds.size.height / 2);
            self.activityIndicator.tintColor = [UIColor redColor];
            [self.userAlert addSubview:self.activityIndicator];
            [self.activityIndicator startAnimating];
            // Show the alert
            [self.userAlert show];
        });
    }
}

- (void)createStandardAlertWithTitle:(NSString *)title andMessage:(NSString *)message {
    if (!self.suppressAlerts) {
        dispatch_async(dispatch_get_main_queue(), ^{
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
                                                            message:message
                                                           delegate:nil
                                                  cancelButtonTitle:@"Ok"
                                                  otherButtonTitles:nil];
            [alert show];
        });
    }
}

- (void)dismissToastAlert {
    if (!self.suppressAlerts) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.userAlert dismissWithClickedButtonIndex:0 animated:YES];
        });
    }
}

#pragma mark - Notification Receivers
- (void)appWillResignActive {
	logMsg(@"Going to Background");
	VidyoUint error;
	VidyoClientRequestSetBackground request = { 0 };
	request.willBackground = VIDYO_TRUE;

	if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_BACKGROUND, &request, sizeof(request))) != VIDYO_CLIENT_ERROR_OK) {
		logMsg([NSString stringWithFormat:@"Problem going to Background: %d", error]);
	}
	sleep(3);
	self.didEverGoToBackground = YES;
}

- (void)appDidBecomeActive {
	if (self.didEverGoToBackground == YES) {
		/*
		   Restart any tasks that were paused (or not yet started) while the application was inactive.
		 */
		logMsg(@"Going to Foreground");

		VidyoUint error;
		VidyoClientRequestSetBackground request = { 0 };
		request.willBackground = VIDYO_FALSE;

		if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_BACKGROUND, &request, sizeof(request))) != VIDYO_CLIENT_ERROR_OK) {
            logMsg([NSString stringWithFormat:@"Problem going to Foreground: %d", error]);
		}
	}
}

- (void)appWillTerminate {
	/*
	   Called when the application is about to terminate.
	 */
	logMsg(@"applicationWillTerminate called");

	// try to shutdown VidyoClient library
	if (!self.vidyoClientStarted) {
		return;
	}

	if (VidyoClientStop() != VIDYO_TRUE) {
		// not expected condition
		logMsg(@"VidyoClientStop() returned error!");
		return;
	}

	VidyoClientUninitialize();
	[[NSNotificationCenter defaultCenter] removeObserver:self];
	[[UIDevice currentDevice] endGeneratingDeviceOrientationNotifications];
}

- (void)orientationDidChange:(NSNotification *)notification {
	NSLog(@"Orientation changed %@", notification);
    
	// determine device orientation
	VidyoClientInEventSetOrientation event = { 0 };
	event.orientation = (VidyoClientOrientation)self.lastKnownOrientation;
	event.control = VIDYO_CLIENT_ORIENTATION_CONTROL_BOTH;
	BOOL willSetOrientation = NO;
	switch ([[UIDevice currentDevice] orientation]) {
		case UIDeviceOrientationUnknown:
			VIDYO_CLIENT_LOG_DEBUG("Unknown");
			VIDYO_CLIENT_CONSOLE_LOG("Unknown\n");
			break;
            
		case UIDeviceOrientationPortrait:
			VIDYO_CLIENT_LOG_DEBUG("Portrait");
			VIDYO_CLIENT_CONSOLE_LOG("Portrait\n");
			event.orientation = VIDYO_CLIENT_ORIENTATION_UP;
			willSetOrientation = YES;
			break;
            
		case UIDeviceOrientationPortraitUpsideDown:
			VIDYO_CLIENT_LOG_DEBUG("PortraitUpsideDown");
			VIDYO_CLIENT_CONSOLE_LOG("PortraitUpsideDown\n");
			event.orientation = VIDYO_CLIENT_ORIENTATION_DOWN;
			willSetOrientation = YES;
			break;
            
		case UIDeviceOrientationLandscapeLeft:
			VIDYO_CLIENT_LOG_DEBUG("LandscapeLeft");
			VIDYO_CLIENT_CONSOLE_LOG("LandscapeLeft\n");
			event.orientation = VIDYO_CLIENT_ORIENTATION_RIGHT;
			willSetOrientation = YES;
			break;
            
		case UIDeviceOrientationLandscapeRight:
			VIDYO_CLIENT_LOG_DEBUG("LandscapeRight");
			VIDYO_CLIENT_CONSOLE_LOG("LandscapeRight\n");
			event.orientation = VIDYO_CLIENT_ORIENTATION_LEFT;
			willSetOrientation = YES;
			break;
            
		case UIDeviceOrientationFaceUp:
			VIDYO_CLIENT_LOG_DEBUG("FaceUp");
			VIDYO_CLIENT_CONSOLE_LOG("FaceUp\n");
			break;
            
		case UIDeviceOrientationFaceDown:
			VIDYO_CLIENT_LOG_DEBUG("FaceDown");
			VIDYO_CLIENT_CONSOLE_LOG("FaceDown\n");
			break;
	}
    
	// cache orientation if needed
	if (willSetOrientation) {
		VidyoClientRequestCallState callState = { 0 };
		VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CALL_STATE, &callState, sizeof(callState));
		// new orientation becomes known, set as last known orientation
		self.lastKnownOrientation = (unsigned)(event.orientation);
		if (callState.callState == VIDYO_CLIENT_CALL_STATE_IN_CONFERENCE) {
			[UIView animateWithDuration:1.0 delay:0.0 options:UIViewAnimationOptionCurveLinear
			                 animations: ^{
                                 [[UIApplication sharedApplication] setStatusBarOrientation:(UIInterfaceOrientation)[[UIDevice currentDevice] orientation]];
                             }
			                 completion: ^(BOOL finished) {
                             }];
		}
	}
    
	// always send event to VidyoClient to set orientation, whether new or cached,
	// in case AppFramework objects were not created in time for first orientation change/poll
	(void)VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SET_ORIENTATION,
	                           &event, sizeof(VidyoClientInEventSetOrientation));
}

#pragma mark - Vidyo Initialization
- (void)clientInit {
	VidyoBool ret;
	// check if this method already previously entered
	if (self.vidyoClientStarted)
		return;

	// configure console logging
	VidyoClientConsoleLogConfigure(VIDYO_CLIENT_CONSOLE_LOG_CONFIGURATION_ALL);

	// determine video rectangle, from geometry of main window, assuming portrait right-side up orientation
	VidyoRect videoRect
	    = { (VidyoInt)(self.window.frame.origin.x), (VidyoInt)(self.window.frame.origin.y),
		    (VidyoUint)(self.window.frame.size.width), (VidyoUint)(self.window.frame.size.height) };

	// determine path, default base filename, and levels and categories, used for logging
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documentsDirectory = [paths objectAtIndex:0];
	documentsDirectory = [documentsDirectory stringByAppendingString:@"/"];
	const char *pathToLogDir = [documentsDirectory cStringUsingEncoding:NSUTF8StringEncoding];

	VidyoClientLogParams logParams = { 0 };

	logParams.logBaseFileName = "VidyoSample_";
	logParams.pathToLogDir = pathToLogDir;
	logParams.logLevelsAndCategories = "warning info@AppGui info@App info@AppEmcpClient info@LmiApp";


	if (VidyoClientInitialize(vidyoClientWrapperOnVidyoClientEvent, (__bridge VidyoVoidPtr)(self), &logParams) == VIDYO_FALSE) {
		logMsg(@"VidyoClientInit() returned failure!\n");
		goto FAIL;
	}

	VidyoClientProfileParams profileParams = { 0 };

	// startup VidyoClient library
	ret = VidyoClientStart(vidyoClientWrapperOnVidyoClientEvent,
	                       (__bridge VidyoVoidPtr)(self),
	                       &logParams,
	                       (__bridge VidyoWindowId)self.window,
	                       &videoRect,
	                       NULL,
	                       &profileParams,
	                       VIDYO_FALSE);

	if (!ret) {
		logMsg(@"VidyoClientStart() returned failure!\n");
		goto FAIL;
	}
	else {
        self.vidyoClientStarted = YES;
		logMsg(@"VidyoClientStart() returned success!\n");
	}
	[self bootstrap];
    
    logMsg(@"Initiliazed Vidyo Libraries");
	return;

	// cleanup on failure, exiting program
FAIL:
    /* [[UIApplication sharedApplication] terminate:self] */;
}

/* Startup configuration code. */
- (void)bootstrap {
	VidyoClientRequestConfiguration conf = { 0 };
	VidyoUint error;
	if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
		logMsg([NSString stringWithFormat:@"Failed to request configuration with error %u", error]);
	}
	else {
		[[UIApplication sharedApplication] setStatusBarOrientation:(UIInterfaceOrientation)[[UIDevice currentDevice] orientation]];
		/* Default configuration */
		conf.enableShowConfParticipantName = VIDYO_TRUE;
		conf.enableHideCameraOnJoin = VIDYO_FALSE;
		conf.enableBackgrounding = VIDYO_TRUE;
		/* Disable autologin */
		conf.userID[0] = '\0';
		conf.portalAddress[0] = '\0';
		conf.serverAddress[0] = '\0';
		conf.password[0] = '\0';
		conf.selfViewLoopbackPolicy = 2;
		if (VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration)) != VIDYO_CLIENT_ERROR_OK) {
			logMsg(@"Failed to set configuration");
		}
	}
}

#pragma mark - NSURLConnection Delegates
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
	[self.webData setLength:0];
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
	[self.webData appendData:data];
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
	logMsg([NSString stringWithFormat:@"Error with Connection: %@",error.description]);
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
	logMsg([NSString stringWithFormat:@"DONE. Received Bytes: %d", [self.webData length]]);
//	NSString *theXML = [[NSString alloc] initWithBytes:[self.webData mutableBytes] length:[self.webData length] encoding:NSUTF8StringEncoding];
//	logMsg(theXML);

	self.xmlParser = [[NSXMLParser alloc] initWithData:self.webData];
	[self.xmlParser setDelegate:self];
	[self.xmlParser setShouldResolveExternalEntities:YES];
	[self.xmlParser parse];

	/* Step2: Send the joinConference if the status is online */
	if (self.isJoiningConference) {
        
        NSString *urlString = [NSString stringWithFormat:@"%@/services/v1_1/VidyoPortalUserService?wsdl",_serverURL];
        NSMutableURLRequest *theJoinRequest = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:urlString]];

		// Get the EntityId from VidyoPortal using WS User::myAccount
		NSString *soapJoinMessage = [NSString stringWithFormat:
		                             @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
		                             "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/user/v1_1\">"
		                             "<env:Body>"
		                             "<ns1:JoinConferenceRequest>"
		                             "<ns1:conferenceID>%@</ns1:conferenceID>"
		                             "</ns1:JoinConferenceRequest>"
		                             "</env:Body>"
		                             "</env:Envelope>", self.vidyoEntityID];

		NSString *msgLength = [NSString stringWithFormat:@"%d", [soapJoinMessage length]];
		[theJoinRequest addValue:@"application/soap+xml; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
		[theJoinRequest addValue:@"joinConference" forHTTPHeaderField:@"SOAPAction"];
		[theJoinRequest addValue:msgLength forHTTPHeaderField:@"Content-Length"];
        NSString *base64 = [[NSString stringWithFormat:@"%@:%@",_serverName,_serverPass] base64];
		NSString *auth = [NSString stringWithFormat:@"Basic %@", base64];
		[theJoinRequest addValue:auth forHTTPHeaderField:@"Authorization"];
		[theJoinRequest setHTTPMethod:@"POST"];
		[theJoinRequest setHTTPBody:[soapJoinMessage dataUsingEncoding:NSUTF8StringEncoding]];

		NSURLConnection *theJoinConnection = [[NSURLConnection alloc] initWithRequest:theJoinRequest delegate:self];
		if (theJoinConnection) {
			self.webData = [NSMutableData data];
		}
		else {
			logMsg(@"The Connection is NULL");
		}
		logMsg(@"**SENT SOAP Request joinConference()**");
        [self dismissToastAlert];
    }
}

- (BOOL)connection:(NSURLConnection *)connection canAuthenticateAgainstProtectionSpace:(NSURLProtectionSpace *)protectionSpace {
    return [protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust];
}

- (void)connection:(NSURLConnection *)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge {
    if ([challenge.protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust]) {
        [challenge.sender useCredential:[NSURLCredential credentialForTrust:challenge.protectionSpace.serverTrust] forAuthenticationChallenge:challenge];
    }
    [challenge.sender continueWithoutCredentialForAuthenticationChallenge:challenge];
}

- (void)connection:(NSURLConnection *)connection willSendRequestForAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge {
    if ([challenge.protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust]) {
        [challenge.sender useCredential:[NSURLCredential credentialForTrust:challenge.protectionSpace.serverTrust] forAuthenticationChallenge:challenge];
    }
    [challenge.sender continueWithoutCredentialForAuthenticationChallenge:challenge];
}

#pragma mark - NSXMLParser Delegate Methods
- (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
    attributes:(NSDictionary *)attributeDict {
	NSString *element = [self getElementFromElementName:elementName];
	if (!element) {
		return;
	}
	/* separate namespace from element name */
	if ([element isEqualToString:@"entityID"]) {
		if (!self.vidyoEntityID) {
			self.vidyoEntityID = [[NSMutableString alloc] initWithCapacity:256];
		}
		self.entityIDResult = TRUE;
	}
	else if ([element isEqualToString:@"MemberStatus"]) {
		if (!self.vidyoMemberStatus) {
			self.vidyoMemberStatus = [[NSMutableString alloc] initWithCapacity:256];
		}
		self.memberStatusResult = TRUE;
	}
}

- (NSString *)getElementFromElementName:(NSString *)elementName {
	NSArray *split = [elementName componentsSeparatedByString:@":"];
	if (!split || ([split count] != 2)) {
		logMsg([NSString stringWithFormat:@"Not a valid elementName: '%@'", elementName]);
		return NULL;
	}
	NSString *element = [split objectAtIndex:1];
	if (!element) {
		logMsg(@"Element is null");
		return NULL;
	}
	return [NSString stringWithString:element];
}

- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string {
	if (self.entityIDResult) {
		[self.vidyoEntityID appendString:string];
		self.entityIDResult = FALSE;
	}
	else if (self.memberStatusResult) {
		[self.vidyoMemberStatus appendString:string];
		self.memberStatusResult = FALSE;
		if (![self.vidyoMemberStatus isEqualToString:@"Online"]) {
			self.isJoiningConference = FALSE;
			// Show an alert if user is not online
			[self createStandardAlertWithTitle:@"User not online. Make sure user is Logged In" andMessage:@""];
		}
	}
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName {
	NSString *element = [self getElementFromElementName:elementName];
	if (!element) {
		return;
	}
	if ([element isEqualToString:@"MyAccountResponse"]) {
		self.entityIDResult = FALSE;
	}
}

- (void)logMsg:(NSString *)msg {
    self.dynamicNotification = msg;
    NSLog(@"%@",msg);
}

@end