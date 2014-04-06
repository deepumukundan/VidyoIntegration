//
//  DMViewController.m
//  VidyoIntegration
//
//  Created by Deepu Mukundan on 05/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#import "DMViewController.h"
#import "VidyoWrapper.h"

@interface DMViewController ()
@property (strong, nonatomic) VidyoWrapper *wrapper;
@property (weak, nonatomic) IBOutlet UITextView *textView;
@end

@implementation DMViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (IBAction)initPressed:(id)sender {
    self.wrapper = [VidyoWrapper sharedInstance];
    [self.wrapper addObserver:self
                   forKeyPath:@"dynamicNotification"
                      options:NSKeyValueObservingOptionNew
                      context:NULL];
    self.textView.text = @"Initialized Vidyo Library";
}

- (IBAction)loginPressed:(id)sender {
    [self.wrapper loginWithURL:@"" userName:@"" password:@""];
}

- (IBAction)joinPressed:(id)sender {
    [self.wrapper joinConferenceWithURL:@""];
}

- (IBAction)clearPressed:(id)sender {
    self.textView.text = @"";
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
    __block NSString *newValue = [change objectForKey:NSKeyValueChangeNewKey];
    dispatch_async(dispatch_get_main_queue(), ^{
        self.textView.text = [NSString stringWithFormat:@"%@\n\n%@",self.textView.text,newValue];
        [self.textView scrollRangeToVisible:NSMakeRange([self.textView.text length], 0)];
    });
}

-(void)dealloc {
    [self.wrapper removeObserver:self forKeyPath:@"dynamicNotification"];
}

@end
