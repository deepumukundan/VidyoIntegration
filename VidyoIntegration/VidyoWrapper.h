//
//  Project - VidyoIntegration from Kony
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

@interface VidyoWrapper : NSObject

#pragma mark - Private properties. Do not use unless really needed
@property (nonatomic, strong) UIAlertView *userAlert;
@property (nonatomic) BOOL isSigningIn;
@property (nonatomic) BOOL isJoiningConference;

#pragma mark - Public Getters
// Watch this property to get continuous logging messages back from the Vidyo subsystem
@property (nonatomic, strong) NSString *dynamicNotification;

#pragma mark - Public Setters
// Suppress all UI notifications
@property (nonatomic) BOOL suppressAlerts;

#pragma mark - Public Method Calls
// Returns singleton instance of the class
+ (id)sharedInstance;
// Enter a room as guest
- (void)joinRoomAsGuestWithURL:(NSString *)url roomKey:(NSString *)roomKey guestName:(NSString *)guestName;
// Logs in a Vidyo member with password
- (void)loginWithURL:(NSString *)url userName:(NSString *)userName password:(NSString *)password;
// Starts conference for a logged in member
- (void)initiateConferenceWithURL:(NSString *)baseURL;
@end
