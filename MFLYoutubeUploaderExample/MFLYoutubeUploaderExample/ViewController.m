//
//  ViewController.m
//  MFLYoutubeUploaderExample
//
//  Created by TJ Fallon on 5/29/15.
//  Copyright (c) 2015 TJ Fallon. All rights reserved.
//

#import "ViewController.h"
#import "MFLYoutubeUploader.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        NSURL *testVideoURL = [[NSBundle mainBundle] URLForResource:@"sample_iTunes"
                                                      withExtension:@"mov"];
        [[MFLYoutubeUploader sharedInstance] uploadURLToYoutube:testVideoURL
                                                      withTitle:@"Testing MFLYoutubeUploader"
                                                    description:@"This is only a test."
                                                           tags:nil
                                                 viewController:self
                                                       progress:nil
                                                     completion:^(BOOL success, NSString *videoId, NSError *err) {
                                                         if (success) {
                                                             [[[UIAlertView alloc] initWithTitle:@"Yissssss!"
                                                                                         message:@"It worked!"
                                                                                        delegate:nil cancelButtonTitle:@"Okay"
                                                                               otherButtonTitles:nil] show];
                                                         } else {
                                                             [[[UIAlertView alloc] initWithTitle:@"Error error"
                                                                                         message:err.localizedDescription
                                                                                        delegate:nil cancelButtonTitle:@"Okay"
                                                                               otherButtonTitles:nil] show];
                                                         }
                                                         
                                                     }];
    });
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
