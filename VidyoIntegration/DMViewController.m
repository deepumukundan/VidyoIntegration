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

@end

@implementation DMViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib
    VidyoWrapper *wrapper = [VidyoWrapper sharedInstance];
    [wrapper joinConferenceWithURL:@"test"];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
