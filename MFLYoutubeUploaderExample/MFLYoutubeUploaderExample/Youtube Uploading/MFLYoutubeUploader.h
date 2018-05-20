//
//  SWYoutubeUploadManager.h
//  CrawlCreator2.0
//
//  Created by Tj on 5/23/15.
//  Copyright (c) 2015 Tj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>

#import "GTLRYouTube.h"
#import "AppAuth.h"

#ifdef CRAWL
#import "MFLFillableTextLoader.h"
#endif

@interface MFLYoutubeUploader : NSObject

/*! @brief The authorization flow session which receives the return URL from
 \SFSafariViewController.
 @discussion We need to store this in the app delegate as it's that delegate which receives the
 incoming URL on UIApplicationDelegate.application:openURL:options:. This property will be
 nil, except when an authorization flow is in progress.
 */
@property(nonatomic, strong, nullable) id<OIDAuthorizationFlowSession> currentAuthorizationFlow;


/**
 *  Singleton, cause why not zoidberg?
 *
 *  @return Just use this for now, it'll be easier.
 */
+ (MFLYoutubeUploader *_Nonnull)sharedInstance;

/**
 *  Use this method to upload a video file to YouTube
 *
 *  @param fileURL     Local URL of video
 *  @param title       Title of video for YouTube
 *  @param description Description of video for YouTube
 *  @param tags        Tags to be applied to video
 *  @param vc          View Controller on which to display authorization flow
 *  @param completion  Called when YouTube upload completes.
 */
- (void)uploadURLToYoutube:(NSURL *_Nonnull)fileURL
                 withTitle:(NSString *_Nonnull)title
               description:(NSString *_Nullable)description
                      tags:(NSArray *_Nullable)tags
            viewController:(UIViewController *_Nonnull)vc
                  progress:(void (^_Nullable) (unsigned long long numberOfBytesRead, unsigned long long dataLength))progress
                completion:(void (^_Nonnull)(BOOL success, NSString * _Nonnull videoId, NSError * _Nonnull err))completion;

@end
