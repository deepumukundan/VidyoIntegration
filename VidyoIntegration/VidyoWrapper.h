//
//  Project - VidyoIntegration
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

@interface VidyoWrapper : NSObject

// Public properties
@property (nonatomic) BOOL isSigningIn;
@property (nonatomic) BOOL isJoiningConference;
@property (nonatomic) BOOL vidyoClientStarted;
@property (nonatomic, strong) NSString *dynamicNotification;
@property (nonatomic, strong) UIAlertView *userAlert;

// Public methods
+ (id)sharedInstance;
- (void)loginWithURL:(NSString *)url userName:(NSString *)userName password:(NSString *)password;
- (void)joinConferenceWithURL:(NSString *)url;

@end
