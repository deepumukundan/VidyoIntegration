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
// Logs in a member with password
- (void)loginWithURL:(NSString *)url userName:(NSString *)userName password:(NSString *)password;
// Guest login to conference room
- (void)joinRoomWithURL:(NSString *)url roomKey:(NSString * )roomKey guestName:(NSString *)guestName;
// Temp
- (void)initiateConferenceWithURL:(NSString *)baseURL;
@end
