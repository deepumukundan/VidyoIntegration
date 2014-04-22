//
//  Vidyo Integration 
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

@interface VidyoWrapper : NSObject

#pragma mark - Private properties & Methods. Do not use unless really needed
@property (nonatomic, strong) UIAlertView *userAlert;
@property (nonatomic) BOOL isSigningIn;
@property (nonatomic) BOOL isJoiningConference;
// Dismiss the alert dialogue box
- (void)dismissToastAlert;

#pragma mark - Public Properties
// Watch this property to get continuous logging messages back from the Vidyo subsystem. Tip: Use KVO from iOS or a timer based fetch from other systems
@property (nonatomic, strong) NSString *dynamicNotification;

#pragma mark - Public Method Calls
// ------------------ Initialization ------------------

// Returns singleton instance of the wrapper class
+ (id)sharedInstance;
// Sets up the Vidyo Window. Defaults to full screen if this method is not called
- (void)configureInitialWindowWithXCord:(NSUInteger)xCord yCord:(NSUInteger)yCord width:(NSUInteger)width height:(NSUInteger)height;

// ----------------- UI Configuration -----------------

// Suppress all UI notifications
- (void)suppressAlerts:(BOOL)suppress;
// Set the frame for the conference
- (void)resizeWindowWithXcord:(NSUInteger)xCord yCord:(NSUInteger)yCord width:(NSUInteger)width height:(NSUInteger)height;

// ----------------- Conferencing Methods -----------------

// Logs in a Vidyo member with password
- (void)loginWithURL:(NSString *)url userName:(NSString *)userName passWord:(NSString *)passWord;
// Starts conference for a logged in member
- (void)initiateConference;

// Enter a room as guest
- (void)joinRoomAsGuestWithURL:(NSString *)url roomKey:(NSString *)roomKey guestName:(NSString *)guestName;

@end
