//
//  SWYoutubeUploadManager.m
//  CrawlCreator2.0
//
//  Created by Tj on 5/23/15.
//  Copyright (c) 2015 Tj. All rights reserved.
//

#import "MFLYoutubeUploader.h"

#import "GTLRYouTube.h"
#import "GTMSessionFetcher.h"
#import "GTMSessionFetcherService.h"
#import <QuartzCore/QuartzCore.h>
#import <AppAuth/AppAuth.h>
#import <GTMAppAuth/GTMAppAuth.h>
#import "UIAlertController+Blocks.h"
#import <WebKit/WebKit.h>

/*! The OIDC issuer from which the configuration will be discovered. (Always this I think?)
 */
static NSString *const kIssuer = @"https://accounts.google.com";

@interface MFLYoutubeUploader () <WKNavigationDelegate>

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *videoDescription;
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, strong) NSURL *url;
@property (nonatomic, strong) WKWebView *channelCreationWebView;
@property (nonatomic, strong) GTLRYouTubeService *youTubeService;
@property (nonatomic, weak) UIViewController *presentingVC;

@property (nonatomic, copy) void (^completion)(BOOL success, NSString *videoId, NSError *err);
@property (nonatomic, copy) void (^progress)(unsigned long long numberOfBytesRead, unsigned long long dataLength);

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
        self.youTubeService = [[GTLRYouTubeService alloc] init];
        self.youTubeService.shouldFetchNextPages = YES;
        self.youTubeService.retryEnabled = YES;
        
        GTMAppAuthFetcherAuthorization *authorization = [GTMAppAuthFetcherAuthorization authorizationFromKeychainForName:kYTKeychainItemName];
        self.youTubeService.authorizer = authorization;
    }

    return self;
}

- (void)uploadURLToYoutube:(NSURL *_Nonnull)fileURL
                 withTitle:(NSString *_Nonnull)title
               description:(NSString *_Nullable)description
                      tags:(NSArray *_Nullable)tags
            viewController:(UIViewController *_Nonnull)vc
                  progress:(void (^_Nullable) (unsigned long long numberOfBytesRead, unsigned long long dataLength))progress
                completion:(void (^_Nonnull)(BOOL success, NSString * _Nonnull videoId, NSError * _Nonnull err))completion
{
    self.title = title;
    self.videoDescription = description;
    self.tags = tags;
    self.completion = completion;
    self.url = fileURL;
    self.presentingVC = vc;
    self.progress = progress;

    if (![self isAuthorized]) {
        //Login first
        [self loginToYoutube];
    } else {
        [self beginUploadingToYoutube];
    }

#ifdef CRAWL
    //Move into Progress Block in CrawlCreator
    NSMutableParagraphStyle *para = [NSMutableParagraphStyle new];
    [para setAlignment:NSTextAlignmentCenter];
    NSAttributedString *details = [[NSAttributedString alloc] initWithString:@"Hyperdrives calibrating to YouTube..."
                                                                  attributes:@{NSFontAttributeName : [UIFont fontWithName:@"Franklin Gothic Book" size:22],
                                                                               NSForegroundColorAttributeName : UIColorFromRGB(0x4bd5ee),
                                                                               NSParagraphStyleAttributeName : para}];
    [self.loader setDetailText:details];

    [self.loader setProgress:0];
#endif
}

- (BOOL)isAuthorized
{
    //return false;
    return self.youTubeService.authorizer.canAuthorize;
}

// AppAuth kit does not really support Extensions, it's using view controllers and app delegate/application references.
// Proposed fix: https://github.com/openid/AppAuth-iOS/pull/224
- (void)loginToYoutube
{
    NSLog(@"Initiate login flow");
    NSURL *issuer = [NSURL URLWithString:kIssuer];
    NSURL *redirectURI = [NSURL URLWithString:kYTRedirectURI];
    
    // discovers endpoints
    [OIDAuthorizationService
     discoverServiceConfigurationForIssuer:issuer
     completion:^(OIDServiceConfiguration *_Nullable configuration, NSError *_Nullable error) {
         NSLog(@"Login flow completed");
         if (!configuration || error) {
             NSLog(@"Login flow failed, abort");
             [GTMAppAuthFetcherAuthorization removeAuthorizationFromKeychainForName:kYTKeychainItemName];
             if (!error) {
                 error = [[NSError alloc] initWithDomain:NSCocoaErrorDomain
                                                    code:404
                                                userInfo:@{NSLocalizedDescriptionKey:@"Unable to setup authorization flow, check integration credentials"}];
             }
             self.completion(NO, nil, error);
             return;
         }
         
         // builds authentication request
         OIDAuthorizationRequest *request =
         [[OIDAuthorizationRequest alloc] initWithConfiguration:configuration
                                                       clientId:kYTClientID
                                                         scopes:@[OIDScopeOpenID, OIDScopeProfile, kGTLRAuthScopeYouTube, OIDScopeEmail]
                                                    redirectURL:redirectURI
                                                   responseType:OIDResponseTypeCode
                                           additionalParameters:nil];
         
         // performs authentication request
         
         self.currentAuthorizationFlow =
         [OIDAuthState authStateByPresentingAuthorizationRequest:request
                                        presentingViewController:self.presentingVC
                                                        callback:^(OIDAuthState *_Nullable authState,
                                                                   NSError *_Nullable error) {
                                                            if (authState) {
                                                                NSLog(@"Auth completed, store, set and begin uploading: %i", authState.isAuthorized);
                                                                GTMAppAuthFetcherAuthorization *authorization =
                                                                [[GTMAppAuthFetcherAuthorization alloc] initWithAuthState:authState];
                                                                [GTMAppAuthFetcherAuthorization saveAuthorization:authorization
                                                                                                toKeychainForName:kYTKeychainItemName];
                                                                self.youTubeService.authorizer = authorization;
                                                                [self beginUploadingToYoutube];
                                                            } else {
                                                                [GTMAppAuthFetcherAuthorization removeAuthorizationFromKeychainForName:kYTKeychainItemName];
                                                                NSLog(@"Failed to authorize");
                                                                if (!error) {
                                                                    error = [[NSError alloc] initWithDomain:NSCocoaErrorDomain
                                                                                                       code:404
                                                                                                   userInfo:@{NSLocalizedDescriptionKey:@"Unable to complete and/or present auth flow, please check integration"}];
                                                                }
                                                                self.completion(NO, nil, error);
                                                            }
                                                        }];
     }];
}

- (void)beginUploadingToYoutube
{
    NSLog(@"Begin uploading video");
    
    // Status.
    GTLRYouTube_VideoStatus *status = [GTLRYouTube_VideoStatus object];
    status.privacyStatus = @"public";
    
    // Snippet.
    GTLRYouTube_VideoSnippet *snippet = [GTLRYouTube_VideoSnippet object];
    snippet.title = self.title;
    snippet.descriptionProperty = self.videoDescription;
    snippet.tags = self.tags;
    
    GTLRYouTube_Video *video = [GTLRYouTube_Video object];
    video.status = status;
    video.snippet = snippet;
    
    [self uploadVideoWithVideoObject:video
             resumeUploadLocationURL:nil];
    
}

- (void)uploadVideoWithVideoObject:(GTLRYouTube_Video *)video
           resumeUploadLocationURL:(NSURL *)locationURL {
    NSURL *fileToUploadURL = self.url;
    NSError *fileError;
    if (![fileToUploadURL checkPromisedItemIsReachableAndReturnError:&fileError]) {
        NSLog(@"Failed to get file");
        self.completion(NO, nil, fileError);
        return;
    }
    
    // Get a file handle for the upload data.
    GTLRUploadParameters *uploadParameters =
    [GTLRUploadParameters uploadParametersWithFileURL:fileToUploadURL
                                             MIMEType:@"video/*"];
    uploadParameters.uploadLocationURL = locationURL;
    
    GTLRYouTubeQuery_VideosInsert *query =
    [GTLRYouTubeQuery_VideosInsert queryWithObject:video
                                              part:@"snippet,status"
                                  uploadParameters:uploadParameters];
    
    query.executionParameters.uploadProgressBlock = ^(GTLRServiceTicket *ticket,
                                                      unsigned long long numberOfBytesRead,
                                                      unsigned long long dataLength) {
        if (self.progress) {
            self.progress(numberOfBytesRead, dataLength);
        }
        NSLog(@"Percent Uploaded %.2f", ((float)numberOfBytesRead/(float)dataLength) * 100);
    };
    
    GTLRYouTubeService *service = self.youTubeService;
    [service executeQuery:query
                            completionHandler:^(GTLRServiceTicket *callbackTicket,
                                                GTLRYouTube_Video *uploadedVideo,
                                                NSError *callbackError) {
                                // Callback
                                //_uploadFileTicket = nil;
                                if (callbackError == nil) {
                                    NSLog(@"Upload Success File ID: %@", uploadedVideo.identifier);
                                    self.completion(YES, uploadedVideo.identifier, nil);
                                } else {
                                    if (callbackError.code == 401) {
                                        [UIAlertController showAlertInViewController:self.presentingVC withTitle:@"Youtube Error"
                                                                             message:@"Upload to Youtube failed, you may need to create a YouTube channel for yourself first. Tap \"Visit\" to be redirected."
                                                                   cancelButtonTitle:@"Visit"
                                                              destructiveButtonTitle:@"Cancel"
                                                                   otherButtonTitles:nil
                                                                            tapBlock:^(UIAlertController * _Nonnull controller, UIAlertAction * _Nonnull action, NSInteger buttonIndex) {
                                                                                if (buttonIndex == 1) {
                                                                                    [self beginChannelCreationFlow];
                                                                                }
                                            
                                        }]
                                        NSLog(@"Visit URL: https://developers.google.com/youtube/create-channel, User probably does not have a Youtube channel linked to this account: %@", callbackError);
                                    }
                                    self.youTubeService.authorizer = nil;
                                    [GTMAppAuthFetcherAuthorization removeAuthorizationFromKeychainForName:kYTKeychainItemName];
                                    NSLog(@"An error occurred: %@", callbackError);
                                    self.completion(NO, nil, callbackError);
                                }
                            }];
    
}

- (void)beginChannelCreationFlow
{
    self.channelCreationWebView = [[WKWebView alloc] initWithFrame:self.presentingVC.view.bounds];
    [self.presentingVC.view addSubview:self.channelCreationWebView];
    [self.channelCreationWebView setNavigationDelegate:self];
    [self.channelCreationWebView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"https://m.youtube.com/create_channel?chromeless=1&next=/channel_creation_done"]]];
}

- (void)webView:(WKWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(WKNavigation *)navigation
{
    
}




@end
