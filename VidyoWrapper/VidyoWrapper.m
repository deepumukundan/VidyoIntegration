//
//  Vidyo Integration 
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#import "VidyoTypes.h"
#import "VidyoClient.h"
#import "NSString+Base64.h"
#import "VidyoWrapper.h"
#import "VidyoEventBridge.h"
#import "VidyoConstants.h"

#pragma mark - Private Interface
@interface VidyoWrapper () <NSXMLParserDelegate>

@property (nonatomic) BOOL vidyoClientStarted;
@property (nonatomic) BOOL didEverGoToBackground;
@property (nonatomic, assign) unsigned lastKnownOrientation;
@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, strong) UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) NSXMLParser *xmlParser;
@property (nonatomic, strong) NSMutableData *webData;
@property (nonatomic, strong) NSMutableURLRequest *webRequest;
@property (nonatomic, strong) NSURLConnection *webConnection;

@property (nonatomic, strong) NSString *baseURL;
@property (nonatomic, strong) NSString *currentUserName;
@property (nonatomic, strong) NSString *currentUserPassword;
@property (nonatomic) BOOL guestMode;
@property (nonatomic) BOOL alertSuppression;
@property (nonatomic) NSUInteger windowOriginalxCord;
@property (nonatomic) NSUInteger windowOriginalyCord;
@property (nonatomic) NSUInteger windowOriginalWidth;
@property (nonatomic) NSUInteger windowOriginalHeight;
@property (nonatomic) BOOL isWindowFrameSet;
@property (nonatomic) BOOL isAutoJoinConferenceEnabled;
@property (nonatomic, strong) NSString *currentXMLResponseString;
@property (nonatomic, strong) NSString *currentXMLElement;
@property (nonatomic, strong) NSMutableString *currentXMLElementContent;
@property (nonatomic, strong) NSMutableDictionary *soapResponseDict;
@property (nonatomic) NSUInteger guestLoginStep;
@property (nonatomic, strong) NSMutableString *errorMessage;
@property (nonatomic) BOOL errorMessageResult;

@end

#pragma mark - Implementation
@implementation VidyoWrapper

// Instance variables
VidyoRect screenRect;

#pragma mark - Lifecycle
+ (id)sharedInstance {
	static VidyoWrapper *sharedInstance = nil;
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
	    sharedInstance = [[self alloc] init];
	});
    logMsg(@"Initialized Vidyo Wrapper!");
	return sharedInstance;
}

- (id)init {
	if (self = [super init]) {
		self.didEverGoToBackground = NO;
		self.window = [[[UIApplication sharedApplication] delegate] window];
        
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

- (void)configureInitialWindowWithXCord:(NSUInteger)xCord yCord:(NSUInteger)yCord width:(NSUInteger)width height:(NSUInteger)height {
    
    // Save the dimentions for any reuse and reverting back to original size
    self.windowOriginalxCord = xCord;
    self.windowOriginalyCord = yCord;
    self.windowOriginalWidth = width;
    self.windowOriginalHeight = height;
    self.isWindowFrameSet = YES;
    
    // initialize Vidyo client library
    [self clientInit];
}

- (void)clientInit {
	VidyoBool ret;
	// Check if this method already previously entered and return out. Safeguard against multiple instanciation
	if (self.vidyoClientStarted)
		return;
    
	// Configure console logging
	VidyoClientConsoleLogConfigure(VIDYO_CLIENT_CONSOLE_LOG_CONFIGURATION_ALL);
    
    if (self.isWindowFrameSet) {
        // Determine video rectangle, from passed in configuration, assuming portrait right-side up orientation
        VidyoRect vidyoRect = {
            (VidyoInt)(self.windowOriginalxCord),
            (VidyoInt)(self.windowOriginalyCord),
            (VidyoUint)(self.windowOriginalWidth),
            (VidyoUint)(self.windowOriginalHeight) };
        screenRect = vidyoRect;
    } else {
        // No frame set initially. Assuming full screen layout
        VidyoRect vidyoRect = {
            (VidyoInt)(self.window.frame.origin.x),
            (VidyoInt)(self.window.frame.origin.y),
            (VidyoUint)(self.window.frame.size.width),
            (VidyoUint)(self.window.frame.size.height) };
        screenRect = vidyoRect;
    }
    
	// Determine path, default base filename, and levels and categories, used for logging
	NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
	NSString *documentsDirectory = [paths objectAtIndex:0];
	documentsDirectory = [documentsDirectory stringByAppendingString:@"/"];
	const char *pathToLogDir = [documentsDirectory cStringUsingEncoding:NSUTF8StringEncoding];
    
	VidyoClientLogParams logParams = { 0 };
    
	logParams.logBaseFileName = "VidyoLog_";
	logParams.pathToLogDir = pathToLogDir;
	logParams.logLevelsAndCategories = "warning info@AppGui info@App info@AppEmcpClient info@LmiApp";
    
	if (VidyoClientInitialize(vidyoClientWrapperOnVidyoClientEvent, (__bridge VidyoVoidPtr)(self), &logParams) == VIDYO_FALSE) {
		logMsg(@"VidyoClientInit() returned failure!");
		goto FAIL;
	}
    
	VidyoClientProfileParams profileParams = { 0 };
    
	// Startup VidyoClient library
	ret = VidyoClientStart(vidyoClientWrapperOnVidyoClientEvent,
	                       (__bridge VidyoVoidPtr)(self),
	                       &logParams,
	                       (__bridge VidyoWindowId)self.window,
	                       &screenRect,
	                       NULL,
	                       &profileParams,
	                       VIDYO_FALSE);
    
	if (!ret) {
		logMsg(@"VidyoClientStart() returned failure!");
		goto FAIL;
	}
	else {
		self.vidyoClientStarted = YES;
		logMsg(@"VidyoClientStart() returned success!");
	}
	[self bootstrap];
    
	logMsg(@"Initiliazed Vidyo Libraries!");
	return;
    
	// cleanup on failure, exiting program
FAIL:
	/* [[UIApplication sharedApplication] terminate:self] */;
}

// Startup configuration code.
- (void)bootstrap {
	VidyoClientRequestConfiguration conf = { 0 };
	VidyoUint error;
	if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CONFIGURATION, &conf, sizeof(VidyoClientRequestConfiguration))) != VIDYO_CLIENT_ERROR_OK) {
		logMsg([NSString stringWithFormat:@"Failed to request configuration with error %u", error]);
	}
	else {
		[[UIApplication sharedApplication] setStatusBarOrientation:(UIInterfaceOrientation)[[UIDevice currentDevice] orientation]];
		// Default configuration
		conf.enableShowConfParticipantName = VIDYO_TRUE;
		conf.enableHideCameraOnJoin = VIDYO_FALSE;
		conf.enableBackgrounding = VIDYO_TRUE;
        conf.enableEntryTone = VIDYO_TRUE;
        conf.enableLogWindow = VIDYO_FALSE;
        conf.enableEchoCancellation = VIDYO_TRUE;
		// Disable autologin
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

- (void)dealloc {
    // Call the method to do all cleanup
    [self appWillTerminate];
}

#pragma mark - Conferencing Methods
- (void)loginWithURL:(NSString *)url userName:(NSString *)userName passWord:(NSString *)passWord autoJoinConference:(BOOL)autoJoinFlag {
	// Reset for new operation
	[self resetState];
	[self resetCredentials];

	// Capture parameters for further operations
	self.baseURL = url;
	self.currentUserName = userName;
	self.currentUserPassword = passWord;
    self.isAutoJoinConferenceEnabled = autoJoinFlag;

	// If portal URL does not start with schema than put it there explicetly
	if (!([url hasPrefix:@"http://"] || [url hasPrefix:@"https://"])) {
		url = [NSString stringWithFormat:@"http://%@", url];
	}

	// Initaite the local sign in process
	VidyoClientInEventLogIn event = { 0 };
	strlcpy(event.portalUri, [self.baseURL UTF8String], sizeof(event.portalUri));
	strlcpy(event.userName, [self.currentUserName UTF8String], sizeof(event.userName));
	strlcpy(event.userPass, [self.currentUserPassword UTF8String], sizeof(event.userPass));

	// Create and show a wait alert
	[self createToastAlertWithMessage:@"Signing in\nPlease wait..."];

	// send login-event to VidyoClient
	if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_LOGIN, &event, sizeof(VidyoClientInEventLogIn)) != VIDYO_TRUE) {
		[self dismissToastAlert];
		[self createStandardAlertWithTitle:@"Failed to Sign in" andMessage:@""];
	}
	else {
		// Sign in in progress
		self.isSigningIn = TRUE;
	}
}

- (void)initiateConference {
	// Signin using credentials so turning off guest mode
	self.guestMode = NO;
	
    // Activate joining status flag
	self.isJoiningConference = TRUE;
	
    // Create and show a wait alert
	[self createToastAlertWithMessage:@"Joining conference\nPlease wait..."];
	
    // Create a web request and start it
	// Get the EntityId from VidyoPortal using WS User::myAccount
	NSString *soapMessage = @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/user/v1_1\">"
    "<env:Body>"
    "<ns1:MyAccountRequest/>"
    "</env:Body>"
    "</env:Envelope>";
	self.webRequest = [self createURLRequestWithURL:self.baseURL soapMessage:soapMessage soapAction:@"myAccount"];
	NSString *base64 = [[NSString stringWithFormat:@"%@:%@", self.currentUserName, self.currentUserPassword] base64];
	NSString *auth = [NSString stringWithFormat:@"Basic %@", base64];
	[self.webRequest addValue:auth forHTTPHeaderField:@"Authorization"];
	self.webConnection = [[NSURLConnection alloc] initWithRequest:self.webRequest delegate:self];
	if (!self.webConnection) logMsg(@"The Connection is NULL");
	logMsg(@"***Sent SOAP Request myAccount()***");
}

- (void)initiateConferenceStep2 {
	// Get the EntityId from VidyoPortal using WS User::myAccount
	NSString *soapMessage = [NSString stringWithFormat:
	                         @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
	                         "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/user/v1_1\">"
	                         "<env:Body>"
	                         "<ns1:JoinConferenceRequest>"
	                         "<ns1:conferenceID>%@</ns1:conferenceID>"
	                         "</ns1:JoinConferenceRequest>"
	                         "</env:Body>"
	                         "</env:Envelope>",[self.soapResponseDict valueForKey:kResponseElemententityID]];
	self.webRequest = [self createURLRequestWithURL:self.baseURL soapMessage:soapMessage soapAction:@"joinConference"];
	NSString *base64 = [[NSString stringWithFormat:@"%@:%@", self.currentUserName, self.currentUserPassword] base64];
	NSString *auth = [NSString stringWithFormat:@"Basic %@", base64];
	[self.webRequest addValue:auth forHTTPHeaderField:@"Authorization"];
	self.webConnection = [[NSURLConnection alloc] initWithRequest:self.webRequest delegate:self];
	if (!self.webConnection) logMsg(@"The Connection is NULL");
	logMsg(@"**Sent SOAP Request joinConference()**");
}

- (void)joinRoomAsGuestWithURL:(NSString *)url roomKey:(NSString *)roomKey guestName:(NSString *)guestName {
	// Reset for new operation
	[self resetState];
	[self resetCredentials];
    
	// Capture parameters for further operations
	self.baseURL = url;
	self.currentUserName = guestName;
    
	// Activate guest mode and set the step
	self.guestMode = YES;
    self.guestLoginStep = 0;
    
	// Activate joining status flag
	self.isJoiningConference = TRUE;
    
	// Create and show a wait alert
	[self createToastAlertWithMessage:@"Signing in as guest\nPlease wait..."];
    
	// Create a web request and start it
	NSString *soapMessage = [NSString stringWithFormat:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
	                         "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/guest\">"
	                         "<env:Body>"
	                         "<ns1:LogInAsGuestRequest>"
	                         "<ns1:roomKey>%@</ns1:roomKey>"
	                         "<ns1:guestName>%@</ns1:guestName>"
	                         "</ns1:LogInAsGuestRequest>"
	                         "</env:Body>"
	                         "</env:Envelope>", roomKey, guestName];
	self.webRequest = [self createURLRequestWithURL:url soapMessage:soapMessage soapAction:@"LogInAsGuest"];
	self.webConnection = [[NSURLConnection alloc] initWithRequest:self.webRequest delegate:self];
    
	if (!self.webConnection) logMsg(@"The Connection is NULL");
	logMsg(@"***Sent SOAP Request LogInAsGuestRequest()***");
}

- (void)joinRoomAsGuestStep1 {
    
    // Increment the step
    self.guestLoginStep = 1;
    
    // Get the EID from the Vidyo subsystem
    VidyoClientRequestGetEid eidRequest =  { 0 };
    VidyoUint error;
    if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_EID, &eidRequest, sizeof(VidyoClientRequestGetEid))) != VIDYO_CLIENT_ERROR_OK) {
        logMsg([NSString stringWithFormat:@"*** Request for EID Failed *** - %d",error]);
    };
    
    NSString *guestID = [self.soapResponseDict valueForKey:kResponseElementGuestID];
    
    // Create a web request and start it
	NSString *soapMessage = [NSString stringWithFormat:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                                 "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/guest\">"
                                 "<env:Body>"
                                 "<ns1:LinkEndpointToGuestRequest>"
                                 "<ns1:guestID>%@</ns1:guestID>"
                                 "<ns1:EID>%s</ns1:EID>"
                                 "</ns1:LinkEndpointToGuestRequest>"
                                 "</env:Body>"
                                 "</env:Envelope>",guestID,eidRequest.EID];
    self.webRequest = [self createURLRequestWithURL:self.baseURL soapMessage:soapMessage soapAction:@"LinkEndpointToGuest"];
	self.webConnection = [[NSURLConnection alloc] initWithRequest:self.webRequest delegate:self];
    
	if (!self.webConnection) logMsg(@"The Connection is NULL");
	logMsg(@"***Sent SOAP Request LinkEndpointToGuestRequest()***");
}

- (void)joinRoomAsGuestStep2 {
    // Increment the step
    self.guestLoginStep = 2;

    VidyoClientInEventSignIn event = {0};
    
    NSString *guestID = [self.soapResponseDict valueForKey:kResponseElementGuestID];
    NSString *vmAddress = [self.soapResponseDict valueForKey:kResponseElementvmaddress];
    NSArray *serverAddressComponents = [vmAddress componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"@:;"]];
    NSString *serverIdentity = serverAddressComponents[0];
    NSString *serverAddress = serverAddressComponents[1];
    NSString *serverPort = serverAddressComponents[2];
    NSString *userName = [self.soapResponseDict valueForKey:kResponseElementun];
    NSString *portalAccessKey = [self.soapResponseDict valueForKey:kResponseElementpak];
    NSString *portalAddress = [self.soapResponseDict valueForKey:kResponseElementportal];
    NSString *portalVersion = [self.soapResponseDict valueForKey:kResponseElementportalVersion];
    NSString *locationTag = [self.soapResponseDict valueForKey:kResponseElementloctag];
    NSString *proxy = [self.soapResponseDict valueForKey:kResponseElementproxyaddress];
    NSArray *proxyArray = [proxy componentsSeparatedByString:@":"];
    NSString *proxyAddress = proxyArray[0];
    NSString *proxyPort = proxyArray[1];
    
    strlcpy(event.serverAddress,[serverAddress UTF8String],sizeof(event.serverAddress));
    strlcpy(event.serverPort, [serverPort UTF8String], sizeof(event.serverPort));
    strlcpy(event.userName, [userName UTF8String], sizeof(event.userName));
    strlcpy(event.portalAccessKey, [portalAccessKey UTF8String], sizeof(event.portalAccessKey));
    strlcpy(event.portalAddress, [portalAddress UTF8String], sizeof(event.portalAddress));
    strlcpy(event.portalVersion, [portalVersion UTF8String], sizeof(event.portalVersion));
    strlcpy(event.vmIdentity,[serverIdentity UTF8String], sizeof(event.vmIdentity));
    strlcpy(event.locationTag, [locationTag UTF8String], sizeof(event.locationTag));
    if (proxyAddress) {
        strlcpy(event.vidyoProxyAddress[0], [proxyAddress UTF8String], sizeof(event.vidyoProxyAddress));
        strlcpy(event.vidyoProxyPort[0], [proxyPort UTF8String], sizeof(event.vidyoProxyPort));
        event.numberProxies = 1;
    } else {
        event.numberProxies = 0;
    }
    event.emcpSecured = VIDYO_TRUE;
    event.guestLogin = VIDYO_TRUE;
    
	// Send Sign in event to VidyoClient
	if (VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_SIGN_IN, &event, sizeof(VidyoClientInEventSignIn)) != VIDYO_TRUE) {
		[self dismissToastAlert];
		[self createStandardAlertWithTitle:@"Failed to Sign In" andMessage:@""];
	} else {
		// Sign in in progress
		self.isSigningIn = TRUE;
	}
    
    // Create a web request and start it
    NSString *soapMessage = [NSString stringWithFormat:@"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
    	                         "<env:Envelope xmlns:env=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:ns1=\"http://portal.vidyo.com/guest\">"
    	                         "<env:Body>" "<ns1:GuestJoinConferenceRequest>"
    	                         "<ns1:guestID>%@</ns1:guestID>"
    	                         "</ns1:GuestJoinConferenceRequest>"
                                 "</env:Body>"
                                 "</env:Envelope>", guestID];
    self.webRequest = [self createURLRequestWithURL:self.baseURL
                                        soapMessage:soapMessage
                                        soapAction:@"GuestJoinConference"];
    self.webConnection = [[NSURLConnection alloc] initWithRequest:self.webRequest delegate:self];
    if (!self.webConnection) logMsg(@"The Connection is NULL");
    logMsg(@"***Sent SOAP Request GuestJoinConference()***");
}

#pragma mark - Alert Display Methods
- (void)createToastAlertWithMessage:(NSString *)message {
	if (!self.alertSuppression) {
		dispatch_async(dispatch_get_main_queue(), ^{
		    self.userAlert = [[UIAlertView alloc] initWithTitle:message
		                                                message:nil
		                                               delegate:nil
		                                      cancelButtonTitle:nil
		                                      otherButtonTitles:nil];
            // Show the alert
		    [self.userAlert show];
		});
	}
}

- (void)createStandardAlertWithTitle:(NSString *)title andMessage:(NSString *)message {
	dispatch_async(dispatch_get_main_queue(), ^{
	    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title
	                                                    message:message
	                                                   delegate:nil
	                                          cancelButtonTitle:@"Ok"
	                                          otherButtonTitles:nil];
	    [alert show];
	});
}

- (void)dismissToastAlert {
	if (!self.alertSuppression) {
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
    
	if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_BACKGROUND, &request, sizeof(VidyoClientRequestSetBackground))) != VIDYO_CLIENT_ERROR_OK) {
		logMsg([NSString stringWithFormat:@"Problem going to Background: %d", error]);
	}
	sleep(3);
	self.didEverGoToBackground = YES;
}

- (void)appDidBecomeActive {
	if (self.didEverGoToBackground == YES) {
		// Restart any tasks that were paused (or not yet started) while the application was inactive.
		logMsg(@"Going to Foreground");

		VidyoUint error;
		VidyoClientRequestSetBackground request = { 0 };
		request.willBackground = VIDYO_FALSE;

		if ((error = VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_SET_BACKGROUND, &request, sizeof(VidyoClientRequestSetBackground))) != VIDYO_CLIENT_ERROR_OK) {
			logMsg([NSString stringWithFormat:@"Problem going to Foreground: %d", error]);
		}
	}
}

- (void)appWillTerminate {
	// Called when the application is about to terminate.
	logMsg(@"applicationWillTerminate called");

    // Dismiss any popups being displayed
    [self dismissToastAlert];
    
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
		VidyoClientSendRequest(VIDYO_CLIENT_REQUEST_GET_CALL_STATE, &callState, sizeof(VidyoClientRequestCallState));
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

#pragma mark - NSURLConnection Delegates
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
	if (!self.webData) {
		self.webData = [NSMutableData data];
	}
	[self.webData setLength:0];
}

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
	[self.webData appendData:data];
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
	logMsg([NSString stringWithFormat:@"Done. Received Bytes: %lu", (unsigned long)[self.webData length]]);

	self.currentXMLResponseString = [[NSString alloc] initWithBytes:[self.webData mutableBytes]
                                                            length:[self.webData length]
                                                          encoding:NSUTF8StringEncoding];
    logMsg(self.currentXMLResponseString);
    
    // Parse the data received
	self.xmlParser = [[NSXMLParser alloc] initWithData:self.webData];
	self.webData = nil;
	[self.xmlParser setDelegate:self];
	[self.xmlParser setShouldResolveExternalEntities:YES];
	[self.xmlParser parse];

    // Chain into the next sequence of steps for the action
	if (self.isJoiningConference && self.guestMode) {
		if (self.guestLoginStep == 0) {
            [self joinRoomAsGuestStep1];
            return;
        } else if (self.guestLoginStep == 1) {
            [self joinRoomAsGuestStep2];
            return;
        }
	}
	else if (self.isJoiningConference && !self.guestMode) {
		[self initiateConferenceStep2];
		return;
	}
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
	logMsg([NSString stringWithFormat:@"Error with connection: %@", error.localizedDescription]);
    // Do some cleanup
    [self resetState];
    [self resetCredentials];
    [self dismissToastAlert];
    [self createStandardAlertWithTitle:@"Error with connection" andMessage:error.localizedDescription];
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
    self.currentXMLElement = element;
    self.currentXMLElementContent = [[NSMutableString alloc] init];
	if (!element) return;
	// separate namespace from element name
    if ([element isEqualToString:kResponseTypeMyAccount]) {
            if (!self.soapResponseDict) self.soapResponseDict = [NSMutableDictionary dictionary];
	} else if ([element isEqualToString:kResponseTypeLoginAsGuest]) {
		if (!self.soapResponseDict) self.soapResponseDict = [NSMutableDictionary dictionary];
	} else if([elementName isEqualToString:kResponseTypeLinkEndpointToGuest]){
		if (!self.soapResponseDict) self.soapResponseDict = [NSMutableDictionary dictionary];
    } else if ([elementName isEqualToString:kResponseTypeErrorMessage]) {
        // Parsing encountered an element with name Fault. Capture the error message.
		if (!self.errorMessage) self.errorMessage = [[NSMutableString alloc] init];
        self.errorMessageResult = YES;
    }
}

- (NSString *)getElementFromElementName:(NSString *)elementName {
	NSArray *split = [elementName componentsSeparatedByString:@":"];
	if (!split || ([split count] != 2)) {
		logMsg([NSString stringWithFormat:@"Not a valid elementName : '%@'", elementName]);
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
    // Capture for later reuse
    [self.currentXMLElementContent appendString:string];
    
    if (self.errorMessageResult) {
        self.errorMessage = [string mutableCopy];
        [self dismissToastAlert];
        [self createStandardAlertWithTitle:@"Error" andMessage:self.errorMessage];
        self.errorMessageResult = NO;
    }
}

- (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName {
	NSString *element = [self getElementFromElementName:elementName];
	if (!element) return;
    
    // Save each response element into the reponse dictionary
    [self.soapResponseDict setObject:self.currentXMLElementContent forKey:self.currentXMLElement];
}

- (void)parserDidEndDocument:(NSXMLParser *)parser {
    NSLog(@"%@",self.soapResponseDict);
    if (![[self.soapResponseDict valueForKey:kResponseElementMemberStatus] isEqualToString:@"Online"]) {
        self.isJoiningConference = NO;
        // Show an alert if user is not online
        [self createStandardAlertWithTitle:@"User not Online. Make sure user is Logged In" andMessage:@""];
    }
}

- (void)parser:(NSXMLParser *)parser parseErrorOccurred:(NSError *)parseError {
    logMsg(parseError.description);
    // Do some cleanup
    [self resetState];
    [self resetCredentials];
    [self dismissToastAlert];
}

#pragma mark - Helper Methods
- (void)suppressAlerts:(BOOL)suppress {
	self.alertSuppression = suppress;
}

- (void)resizeWindowWithXcord:(NSUInteger)xCord yCord:(NSUInteger)yCord width:(NSUInteger)width height:(NSUInteger)height {
    
    // Create a resize event and capture the parameters
    VidyoClientInEventResize event = { 0 };
    event.x = (VidyoUint)xCord;
    event.y = (VidyoUint)yCord;
    event.width = (VidyoUint)width;
    event.height = (VidyoUint)height;
    
    // Send the resize window event
    if(VidyoClientSendEvent(VIDYO_CLIENT_IN_EVENT_RESIZE, &event, sizeof(VidyoClientInEventResize)) != VIDYO_TRUE) {
        logMsg(@"Failed to resize the Vidyo window!");
    };
}

- (void)logMsg:(NSString *)msg {
	self.dynamicNotification = msg;
	NSLog(@"%@", msg);
}

- (void)resetState {
	self.isSigningIn = NO;
	self.isJoiningConference = NO;
    self.isAutoJoinConferenceEnabled = NO;
	self.soapResponseDict = nil;
    self.guestLoginStep = 0;
}

- (void)resetCredentials {
	self.baseURL = nil;
	self.currentUserName = nil;
	self.currentUserPassword = nil;
}

- (NSMutableURLRequest *)createURLRequestWithURL:(NSString *)baseURL
                                     soapMessage:(NSString *)soapMessage
                                      soapAction:(NSString *)soapAction {
	// Suffix the path with different end points based on flag
	NSString *urlString;
	if (self.guestMode) {
		urlString = [NSString stringWithFormat:@"%@/services/VidyoPortalGuestService?wsdl", baseURL];
	}
	else {
        urlString = [NSString stringWithFormat:@"%@/services/v1_1/VidyoPortalUserService?wsdl", baseURL];
	}

	NSURL *url = [NSURL URLWithString:urlString];
	NSMutableURLRequest *urlRequest = [NSMutableURLRequest requestWithURL:url];

	// Add basic requirements for all requests
	NSString *msgLength = [NSString stringWithFormat:@"%lu", (unsigned long)[soapMessage length]];
	[urlRequest addValue:@"application/soap+xml; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
	[urlRequest addValue:soapAction forHTTPHeaderField:@"SOAPAction"];
	[urlRequest addValue:msgLength forHTTPHeaderField:@"Content-Length"];
	[urlRequest setHTTPMethod:@"POST"];
	[urlRequest setHTTPBody:[soapMessage dataUsingEncoding:NSUTF8StringEncoding]];

	return urlRequest;
}

- (void)executeMethodInMainThread:(NSString *)methodName {
    // If Autojoin is not enabled and initiateConference is called, don't do anything
    if (!self.isAutoJoinConferenceEnabled &&
        [methodName isEqualToString:NSStringFromSelector(@selector(initiateConference))]){
        return;
    }
    // Execute the passed in method in the main thread
    [self performSelectorOnMainThread:NSSelectorFromString(methodName)
                           withObject:self
                        waitUntilDone:NO];
}

@end
