//
//  SWYoutubeUploadManager.m
//  CrawlCreator2.0
//
//  Created by Tj on 5/23/15.
//  Copyright (c) 2015 Tj. All rights reserved.
//

#import "MFLYoutubeUploader.h"
#import "MFLYoutubeConstants.h"
#import "GTMOAuth2ViewControllerTouch.h"
#import "GTLYouTube.h"
#import "CrawlMessagesKeyboardView.h"
#import "UIAlertController+Blocks.h"

@interface MFLYoutubeUploader ()

@property NSString *title;
@property NSString *videoDescription;
@property NSArray *tags;
@property NSURL *url;
@property MFLFillableTextLoader *loader;

@property (nonatomic, copy) void (^completion)(BOOL success, NSString *videoId, NSError *err);

@end

@implementation MFLYoutubeUploader

+ (MFLYoutubeUploader *)sharedInstance
{
    static MFLYoutubeUploader *_sharedInstance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedInstance = [[self alloc] init];
    });

    return _sharedInstance;
}

- (instancetype)init
{
    self = [super init];

    if (self) {
        _youtubeService = [[GTLServiceYouTube alloc] init];
        _youtubeService.authorizer = [GTMOAuth2ViewControllerTouch authForGoogleFromKeychainForName:kYTKeychainItemName
                                                                                           clientID:kYTClientID
                                                                                       clientSecret:kYTClientSecret];
    }

    return self;
}

- (void)uploadURLToYoutube:(NSURL *)fileURL
                 withTitle:(NSString *)title
               description:(NSString *)description
                      tags:(NSArray *)tags
            viewController:(UIViewController *)vc
                    loader:(MFLFillableTextLoader *)loader
                completion:(void (^)(BOOL success, NSString *videoId, NSError *err))completion
{
    self.title = title;
    self.videoDescription = description;
    self.tags = tags;
    self.completion = completion;
    self.url = fileURL;
    self.loader = loader;
    
    if (![self isAuthorized]) {
        [vc presentViewController:[self createAuthController] animated:YES completion:nil];
    } else {
        [self beginUploadingToYoutube];
    }


    NSMutableParagraphStyle *para = [NSMutableParagraphStyle new];
    [para setAlignment:NSTextAlignmentCenter];
    NSAttributedString *details = [[NSAttributedString alloc] initWithString:@"Hyperdrives calibrating to YouTube..."
                                                                  attributes:@{NSFontAttributeName : [UIFont fontWithName:@"Franklin Gothic Book" size:22],
                                                                               NSForegroundColorAttributeName : UIColorFromRGB(0x4bd5ee),
                                                                               NSParagraphStyleAttributeName : para}];
    [self.loader setDetailText:details];

    [self.loader setProgress:0];
}

- (BOOL)isAuthorized
{
    return [((GTMOAuth2Authentication *)self.youtubeService.authorizer) canAuthorize];
}


- (GTMOAuth2ViewControllerTouch *)createAuthController
{
    GTMOAuth2ViewControllerTouch *authController;

    authController = [[GTMOAuth2ViewControllerTouch alloc] initWithScope:kGTLAuthScopeYouTube
                                                                clientID:kYTClientID
                                                            clientSecret:kYTClientSecret
                                                        keychainItemName:kYTKeychainItemName
                                                                delegate:self
                                                        finishedSelector:@selector(authViewController:finishedWithAuth:error:)];
    return authController;
}

- (void)authViewController:(GTMOAuth2ViewControllerTouch *)viewController
          finishedWithAuth:(GTMOAuth2Authentication *)authResult
                     error:(NSError *)error {
    [viewController dismissViewControllerAnimated:YES completion:^{
        if (error) {
#ifdef SW_MESSAGES
            UIViewController *topController = [CrawlMessagesKeyboardView rootController];
            while (topController.presentedViewController) {
                topController = topController.presentedViewController;
            }
#else
            UIViewController *topController = [[[UIApplication sharedApplication] keyWindow] rootViewController];
#endif
            [UIAlertController showAlertInViewController:topController
                                               withTitle:@"Error"
                                                 message:error.localizedDescription
                                       cancelButtonTitle:@"Okay"
                                  destructiveButtonTitle:nil
                                       otherButtonTitles:nil
                                                tapBlock:nil];

            self.youtubeService.authorizer = nil;
            self.completion(NO, nil, error);
        } else {
            self.youtubeService.authorizer = authResult;
            [self beginUploadingToYoutube];
        }
    }];
}

- (void)beginUploadingToYoutube
{
    GTLYouTubeVideoStatus *status = [GTLYouTubeVideoStatus alloc];
    status.privacyStatus = @"public";

    GTLYouTubeVideoSnippet *snippet = [GTLYouTubeVideoSnippet alloc];
    snippet.title = self.title;
    snippet.descriptionProperty = self.videoDescription;
    snippet.tags = self.tags;

    GTLYouTubeVideo *video = [GTLYouTubeVideo object];
    video.snippet = snippet;
    video.status = status;

//My original project worked fine with FileURL, but building this example project I found "GTL_USE_SESSION_FETCHER" was set to 0 for the current build of Google Dev Library.
#if GTL_USE_SESSION_FETCHER
    GTLUploadParameters *uploadParameters = [GTLUploadParameters uploadParametersWithFileURL:self.url
                                                                                    MIMEType:@"video/*"];
#else
    __autoreleasing NSError *err;
    NSFileHandle *handle = [NSFileHandle fileHandleForReadingFromURL:self.url error:&err];
    GTLUploadParameters *uploadParameters = [GTLUploadParameters uploadParametersWithFileHandle:handle
                                                                                       MIMEType:@"video/*"];
    if (err) {
        if (self.completion) {
            self.completion(NO, nil, err);
        }
        return;
    }
#endif

    GTLQueryYouTube *query = [GTLQueryYouTube queryForVideosInsertWithObject:video
                                                                        part:@"snippet,status"
                                                            uploadParameters:uploadParameters];
    GTLServiceTicket *ticket;
    ticket = [self.youtubeService executeQuery:query
                            completionHandler:^(GTLServiceTicket *ticket,
                                                GTLYouTubeVideo *insertedVideo, NSError *error)
             {
                 if (!error) {
                     NSLog(@"File ID: %@", insertedVideo.identifier);
                     self.completion(YES, insertedVideo.identifier, nil);
                     return;
                 } else {
                     NSLog(@"An error occurred: %@", error);
                     self.completion(NO, nil, error);
                     return;
                 }
             }];

    [ticket setUploadProgressBlock:^(GTLServiceTicket *ticket,
                                     unsigned long long totalBytesWritten,
                                     unsigned long long totalBytesExpectedToWrite) {
//TODO Update Loading Indicator here, or notify loading delegate
        [self.loader setProgress:((float)totalBytesWritten/(float)totalBytesExpectedToWrite)];
        NSLog(@"Percent Uploaded %.2f", ((float)totalBytesWritten/(float)totalBytesExpectedToWrite) * 100);
    }];
}

@end
