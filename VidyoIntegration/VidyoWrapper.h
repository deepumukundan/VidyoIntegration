//
//  Vidyo Integration from Kony
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

@interface VidyoWrapper : NSObject

#pragma mark - Private properties. Do not use unless really needed
@property (nonatomic, strong) UIAlertView *userAlert;
@property (nonatomic) BOOL isSigningIn;
@property (nonatomic) BOOL isJoiningConference;

#pragma mark - Public Properties
// Watch this property to get continuous logging messages back from the Vidyo subsystem
@property (nonatomic, strong) NSString *dynamicNotification;

#pragma mark - Public Method Calls
// Returns singleton instance of the class
+ (id)sharedInstance;
// Suppress all UI notifications
- (void)suppressAlerts:(BOOL)supress;
// Logs in a Vidyo member with password
- (void)loginWithURL:(NSString *)url userName:(NSString *)userName passWord:(NSString *)passWord;
// Starts conference for a logged in member
- (void)initiateConference;
// Enter a room as guest
- (void)joinRoomAsGuestWithURL:(NSString *)url roomKey:(NSString *)roomKey guestName:(NSString *)guestName;

@end
