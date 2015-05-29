/* Copyright (c) 2015 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//  GTLStorageRewriteResponse.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Cloud Storage API (storage/v1)
// Description:
//   Lets you store and retrieve potentially-large, immutable data objects.
// Documentation:
//   https://developers.google.com/storage/docs/json_api/
// Classes:
//   GTLStorageRewriteResponse (0 custom class methods, 6 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLObject.h"
#else
  #import "GTLObject.h"
#endif

@class GTLStorageObject;

// ----------------------------------------------------------------------------
//
//   GTLStorageRewriteResponse
//

// A Rewrite response.

@interface GTLStorageRewriteResponse : GTLObject
@property (nonatomic, retain) NSNumber *done;  // boolValue

// The kind of item this is.
@property (nonatomic, copy) NSString *kind;

@property (nonatomic, retain) NSNumber *objectSize;  // unsignedLongLongValue
@property (nonatomic, retain) GTLStorageObject *resource;
@property (nonatomic, copy) NSString *rewriteToken;
@property (nonatomic, retain) NSNumber *totalBytesRewritten;  // unsignedLongLongValue
@end
