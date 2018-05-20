//
//  SWYoutubeConstants.h
//  YouTube Direct Lite for iOS
//
//  Created by Tj on 5/23/15.
//  Copyright (c) 2015 Google. All rights reserved.
//

#import <Foundation/Foundation.h>

 
//In order to compile, uncomment these lines and insert your own values
// In order to compile, uncomment these lines and insert your own values from the Google Cloud Console.
// For the keychain item name, pick a value that will unqieuly identify your app inn the iOS keychain.

/*
 static NSString * const kYTClientID             = @"<Client ID>";
 
 // This value must match the value supplied for your custom URL scheme, without the ":oauthredirect".
 static NSString * const kYTRedirectURI          = @"<Reverse Client ID>:/oauthredirect";
 
 static NSString * const kYTKeychainItemName     = @"KeychainItemNameForStoringCredentials";
 */


//Currently not used.
static NSString * const UPLOAD_PLAYLIST         = @"Replace me with the playlist ID you want to upload into";

@interface MFLYoutubeConstants : NSObject

@end
