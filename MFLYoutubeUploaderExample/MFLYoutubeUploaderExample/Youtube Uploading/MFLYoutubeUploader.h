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
#import "GTLYouTube.h"

@interface MFLYoutubeUploader : NSObject

@property (nonatomic, retain) GTLServiceYouTube *youtubeService;

/**
 *  Singleton, cause why not zoidberg?
 *
 *  @return Just use this for now, it'll be easier.
 */
+ (MFLYoutubeUploader *)sharedInstance;

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
- (void)uploadURLToYoutube:(NSURL *)fileURL
                 withTitle:(NSString *)title
               description:(NSString *)description
                      tags:(NSArray *)tags
            viewController:(UIViewController *)vc
                completion:(void (^)(BOOL success, NSError *err))completion;

@end
