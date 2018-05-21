// **TODO**: These instructions are out of date. You now need to use a pod file to integrate the Google REST SDK, not SVN.
// Updates to AppAuth also means you can't use this in extensions anymore. This should probably be turned into a real Cocoapod, for now integration is kind of hacky, because you have to update your podfile to match the Example project here to pull in dependencies, but still copy the source files over manually for MFLYoutubeUploader.

# MFLYoutubeUploader
I wanted an incredibly simple class for uploading videos to Youtube. If you're like me, and all you want to do is upload a video to YT then YTDL is going to seem monolithic. No need to stress, Youtube uploading is actually incredibly simple.

### Account Setup and Integration
First you'll need to get registered with Google in order to make uploads. [Start here](https://console.developers.google.com/project)

(https://cloud.google.com/console#/flows/enableapi?apiid=youtube)



1) Create an Application.

  - If you haven't already registered your application with the Google, then set up an application. The system will guides you through the process of setting up your application

  - Once you've already registered your application with the Google, you'll need to get your Client ID, and Client Secret to provide to the manager.
  
      - Select project from your [console](https://console.developers.google.com/project).
      - Choose APIs & Auth
      - Choose Credentials
      - Create an OAuth Client ID, annd choose iOS Application.
      - Add in correct values from your project.
      - You should now be assigned a client id.
  **Note:** At this point, you can run the example project by running `pod install` in the root directory. It will walk you through signing in to Google and auto-uploading a video in the background on success. (requires CocoaPods setup locally)
  
2) Integrate the Google Client Library

  - Using CocoaPods, create a PodFile for your project, and copy over the values in the Podfile of this repo. You need these dependencies to compile the MFLYoutubeUploader files.
```
  pod 'GoogleAPIClientForREST/YouTube', '~> 1.3.4'
  pod 'GTMAppAuth'
```

4) Next, drag the MFLYouTubeUploader folder into your project, including the Upload Constants folder.

5) Using the values you obtained from the Google Developer Console earlier, set the values contained in MFLYoutubeConstants:
```  
  kYTClientID = <something>.apps.googleusercontent.com
  kYTRedirectURI = com.apps.googleusercontent.<something>.:/oauthredirect
  kYTKeychainItemName = <any NSString that uniquely identifies your app>
```

###Uploading

Uploading is made with a single method call:

```
    [[MFLYoutubeUploader sharedInstance] uploadURLToYoutube:<File path URL to Video>
                                                  withTitle:<Title for Video>
                                                description:<Description to use for Video>
                                                       tags:<Tags to use for YouTube>
                                             viewController:<View Controller on which to present authorization flow>
                                                   progress: nil
                                                 completion:^(BOOL success, NSError *err) {
                                                 //Handle error or success here
                                                 }];
```
  
####Thanks
Thank you to [YouTube Direct Lite for iOS](https://github.com/youtube/yt-direct-lite-iOS) for getting me started on this.
