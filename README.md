# MFLYoutubeUploader
I wanted an incredibly simple class for uploading videos to Youtube. If you're like me, and all you want to do is upload a video to YT then YTDL is going to seem monolithic. No need to stress, Youtube uploading is actually incredibly simple.

####Account Setup and Integration
First you'll need to get registered with Google in order to make uploads. [Start here](https://console.developers.google.com/project)

(https://cloud.google.com/console#/flows/enableapi?apiid=youtube)

1) Create an Application.

  - If you haven't already registered your application with the Google, then set up an application. The system will guides you through the process of setting up your application

  - Once you've already registered your application with the Google, you'll need to get your Client ID, and Client Secret to provide to the manager.
  
      - Select project from your [console](https://console.developers.google.com/project).
      - Choose APIs & Auth
      - Choose Credentials
      - On the far right, you should see Client ID and Client Secret. Copy these into the corresponding constants in the MFLYoutubeUploader
      
      
2) Integrate the Google Client Library

  - This library is quite large, and may be one of the more complicated steps you have to deal with.
  - Download a read-only copy via SVN. (Recommended you checkout in the same directory as your .xcproj file, for ease of Search Path setting)
```  
  svn checkout http://google-api-objectivec-client.googlecode.com/svn/trunk/ google-api-objectivec-client-read-only
```

  - If you place the resulting directory next to your project file, you will want to use the following Header Search Paths:
    
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source"
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source/Services/YouTube/Generated"
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source/Utilities"
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source/OAuth2/Touch"
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source/OAuth2"
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source/Objects"
    - "$(SRCROOT)/google-api-objectivec-client-read-only/Source/HTTPFetcher"

3) You will then need to drag the following four files into your project:

    - GTMOAuth2ViewTouch.xib
    - GTLCommon_Sources.m (Mark as -fno-objc-arc in Build Phases)
    - GTLNetworking_Sources.m (Mark as -fno-objc-arc in Build Phases)
    - GTLYouTube_Sources.m
    
  These files can all be found inside the Google Client Library you've just checked out.  
  
    

4) Next, drag the MFLYouTubeUploader folder into your project, including the Upload Constants folder.

5) Using the values you obtained from the Google Developer Console earlier, set the values contained in MFLYoutubeConstants:
```  
  kYTClientID
  kYTClientSecret
```

###Uploading

Uploading is made with a single method call:

```
    [[MFLYoutubeUploader sharedInstance] uploadURLToYoutube:<File path URL to Video>
                                                  withTitle:<Title for Video>
                                                description:<Description to use for Video>
                                                       tags:<Tags to use for YouTube>
                                             viewController:<View Controller on which to present authorization flow>
                                                 completion:^(BOOL success, NSError *err) {
                                                 //Handle error or success here
                                                 }];
```

###Soon to be added:

- Loading Handler: Progress callback, and/or automatic progress indicator

  - TBD, there will be a progress callback, but there will also probably be automatic loading indicator management if you choose.
  
  
  
####Thanks
Thank you to [YouTube Direct Lite for iOS](https://github.com/youtube/yt-direct-lite-iOS) for getting me started on this.
