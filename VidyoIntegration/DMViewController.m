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

@interface DMViewController () <UITextViewDelegate>
@property (strong, nonatomic) VidyoWrapper *wrapper;
@property (weak, nonatomic) IBOutlet UITextView *textView;
@end

@implementation DMViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	self.textView.delegate = self;
	self.textView.scrollEnabled = YES;
}

- (IBAction)initPressed:(id)sender {
	self.wrapper = [VidyoWrapper sharedInstance];
	[self.wrapper addObserver:self
	               forKeyPath:kVidyoDynamicNotification
	                  options:NSKeyValueObservingOptionNew
	                  context:NULL];
	[self.wrapper addObserver:self
	               forKeyPath:kVidyoIsSigningIn
	                  options:NSKeyValueObservingOptionNew
	                  context:NULL];
    [self.wrapper setSuppressAlerts:YES];
	self.textView.text = @"Initialized Vidyo Library";
}

- (IBAction)loginPressed:(id)sender {
    [self.wrapper loginWithURL:@"http://dev20.vidyo.com"
                      userName:@"marina"
                      password:@"marina"];
}

- (IBAction)joinPressed:(id)sender {
	[self.wrapper initiateConference];
}

- (IBAction)guestPressed:(id)sender {
//	[self.wrapper joinRoomAsGuestWithURL:@"https://video.ust-global.com"
//                                 roomKey:@"LvJZe5NNlzrd"
//                               guestName:@"GreenBot"];
    [self.wrapper joinRoomAsGuestWithURL:@"http://dev20.vidyo.com"
                                 roomKey:@"svXhf7He5RQU"
                               guestName:@"YellowBot"];
}

- (IBAction)clearPressed:(id)sender {
	self.textView.text = @"";
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
	if ([keyPath isEqualToString:kVidyoDynamicNotification]) {
		__block NSString *newValue = [change objectForKey:NSKeyValueChangeNewKey];
		dispatch_async(dispatch_get_main_queue(), ^{
		    self.textView.text = [NSString stringWithFormat:@"%@\n\n%@", self.textView.text, newValue];
		    [self.textView scrollRangeToVisible:NSMakeRange([self.textView.text length], 0)];
		});
	}
	else if ([keyPath isEqualToString:kVidyoIsSigningIn]) {
		__block BOOL newValue = [[change objectForKey:NSKeyValueChangeNewKey] boolValue];
		dispatch_async(dispatch_get_main_queue(), ^{
		    self.textView.text = [NSString stringWithFormat:@"%@\n\n%@ - %@", self.textView.text, keyPath, newValue ? @"TRUE":@"FALSE"];
		    [self.textView scrollRangeToVisible:NSMakeRange([self.textView.text length], 0)];
		});
	}
}

- (void)dealloc {
	[self.wrapper removeObserver:self forKeyPath:kVidyoDynamicNotification];
	[self.wrapper removeObserver:self forKeyPath:kVidyoIsSigningIn];
}

@end
