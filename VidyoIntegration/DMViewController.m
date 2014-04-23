//
//  DMViewController.m
//  VidyoIntegration
//
//  Created by Deepu Mukundan on 05/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#import "DMViewController.h"
#import "VidyoConstants.h"
#import "VidyoWrapper.h"

@interface DMViewController ()
@property (strong, nonatomic) VidyoWrapper *wrapper;
@property (weak, nonatomic) IBOutlet UITextView *textView;
@property (nonatomic) BOOL windowResized;
@end

@implementation DMViewController


- (IBAction)loginJoinPressed:(id)sender {
    [self.wrapper loginWithURL:@"http://dev20.vidyo.com"
                      userName:@"marina"
                      passWord:@"marina"];
    [self.wrapper initiateConference];
}


- (void)viewDidLoad {
	[super viewDidLoad];
    self.windowResized = NO;
	self.textView.scrollEnabled = YES;
    [self configure];
}

- (void)configure {
    // Get an instace of the Vidyo wrapper
    self.wrapper = [VidyoWrapper sharedInstance];
    // Configure the initial video window size
    [self.wrapper configureInitialWindowWithXCord:0 yCord:66 width:320 height:330];
    // Show progress dialogs
    [self.wrapper suppressAlerts:NO];
    
    // Observe interested properties
	[self.wrapper addObserver:self
	               forKeyPath:kVidyoDynamicNotification
	                  options:NSKeyValueObservingOptionNew
	                  context:NULL];
	[self.wrapper addObserver:self
	               forKeyPath:kVidyoIsSigningIn
	                  options:NSKeyValueObservingOptionNew
	                  context:NULL];
    [self.wrapper addObserver:self
	               forKeyPath:kVidyoIsJoiningConference
	                  options:NSKeyValueObservingOptionNew
	                  context:NULL];
    
	self.textView.text = @"Initialized Vidyo Library";
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

- (void)dealloc {
	[self.wrapper removeObserver:self forKeyPath:kVidyoDynamicNotification];
	[self.wrapper removeObserver:self forKeyPath:kVidyoIsSigningIn];
    [self.wrapper removeObserver:self forKeyPath:kVidyoIsJoiningConference];
}

#pragma mark - User Actions
- (IBAction)loginPressed:(id)sender {
    [self.wrapper loginWithURL:@"http://dev20.vidyo.com"
                      userName:@"marina"
                      passWord:@"marina"];
}

- (IBAction)joinPressed:(id)sender {
	[self.wrapper initiateConference];
}

- (IBAction)guestPressed:(id)sender {
    [self.wrapper joinRoomAsGuestWithURL:@"http://dev20.vidyo.com"
                                 roomKey:@"svXhf7He5RQU"
                               guestName:@"YellowBot"];
}

- (IBAction)resizePressed:(id)sender {
    if (!self.windowResized) {
        [self.wrapper resizeWindowWithXcord:60 yCord:66 width:200 height:150];
        self.windowResized = YES;
    } else {
        [self.wrapper resizeWindowWithXcord:0 yCord:66 width:320 height:330];
        self.windowResized = NO;
    }
}

- (IBAction)clearPressed:(id)sender {
	self.textView.text = @"";
}

#pragma mark - KVO
- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
	if ([keyPath isEqualToString:kVidyoDynamicNotification]) {
		__block NSString *newValue = [change objectForKey:NSKeyValueChangeNewKey];
		dispatch_async(dispatch_get_main_queue(), ^{
		    self.textView.text = [NSString stringWithFormat:@"%@\n\n%@", self.textView.text, newValue];
		    [self.textView scrollRangeToVisible:NSMakeRange([self.textView.text length], 0)];
		});
	}
	else if ([keyPath isEqualToString:kVidyoIsSigningIn] ||
             [keyPath isEqualToString:kVidyoIsJoiningConference]) {
		__block BOOL newValue = [[change objectForKey:NSKeyValueChangeNewKey] boolValue];
		dispatch_async(dispatch_get_main_queue(), ^{
		    self.textView.text = [NSString stringWithFormat:@"%@\n\n%@ - %@", self.textView.text, keyPath, newValue ? @"TRUE":@"FALSE"];
		    [self.textView scrollRangeToVisible:NSMakeRange([self.textView.text length], 0)];
		});
	}
}

@end
