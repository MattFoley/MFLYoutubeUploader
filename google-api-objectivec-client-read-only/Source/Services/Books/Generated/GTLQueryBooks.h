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
//  GTLQueryBooks.h
//

// ----------------------------------------------------------------------------
// NOTE: This file is generated from Google APIs Discovery Service.
// Service:
//   Books API (books/v1)
// Description:
//   Lets you search for books and manage your Google Books library.
// Documentation:
//   https://developers.google.com/books/docs/v1/getting_started
// Classes:
//   GTLQueryBooks (44 custom class methods, 70 custom properties)

#if GTL_BUILT_AS_FRAMEWORK
  #import "GTL/GTLQuery.h"
#else
  #import "GTLQuery.h"
#endif

@class GTLBooksAnnotation;
@class GTLBooksCloudloadingResource;
@class GTLBooksUsersettings;

@interface GTLQueryBooks : GTLQuery

//
// Parameters valid on all methods.
//

// Selector specifying which fields to include in a partial response.
@property (nonatomic, copy) NSString *fields;

//
// Method-specific parameters; see the comments below for more information.
//
@property (nonatomic, retain) NSArray *acquireMethod;  // of NSString
@property (nonatomic, copy) NSString *action;
@property (nonatomic, assign) BOOL allowWebDefinitions;
@property (nonatomic, copy) NSString *androidId;
// "annotationDataId" has different types for some query methods; see the
// documentation for the right type for each query method.
@property (nonatomic, retain) id annotationDataId;
@property (nonatomic, copy) NSString *annotationId;
@property (nonatomic, copy) NSString *association;
@property (nonatomic, retain) NSArray *categoryId;  // of NSString
@property (nonatomic, copy) NSString *contentVersion;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *cpksver;
@property (nonatomic, copy) NSString *device;
@property (nonatomic, copy) NSString *deviceCookie;
@property (nonatomic, copy) NSString *download;
@property (nonatomic, copy) NSString *driveDocumentId;
@property (nonatomic, copy) NSString *endOffset;
@property (nonatomic, copy) NSString *endPosition;
@property (nonatomic, retain) NSArray *features;  // of NSString
@property (nonatomic, copy) NSString *filter;
@property (nonatomic, assign) NSInteger h;
@property (nonatomic, copy) NSString *langRestrict;
@property (nonatomic, copy) NSString *layerId;
@property (nonatomic, retain) NSArray *layerIds;  // of NSString
@property (nonatomic, copy) NSString *libraryRestrict;
@property (nonatomic, copy) NSString *licenseTypes;
@property (nonatomic, copy) NSString *locale;
@property (nonatomic, copy) NSString *manufacturer;
@property (nonatomic, copy) NSString *maxAllowedMaturityRating;
@property (nonatomic, assign) NSUInteger maxResults;
@property (nonatomic, copy) NSString *mimeType;
@property (nonatomic, copy) NSString *model;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *nonce;
@property (nonatomic, copy) NSString *offerId;
@property (nonatomic, copy) NSString *orderBy;
@property (nonatomic, assign) NSUInteger pageSize;
@property (nonatomic, copy) NSString *pageToken;
@property (nonatomic, copy) NSString *partner;
@property (nonatomic, copy) NSString *position;
@property (nonatomic, copy) NSString *printType;
@property (nonatomic, retain) NSArray *processingState;  // of NSString
@property (nonatomic, copy) NSString *product;
@property (nonatomic, copy) NSString *projection;
@property (nonatomic, copy) NSString *q;
@property (nonatomic, copy) NSString *rating;
@property (nonatomic, copy) NSString *reason;
@property (nonatomic, assign) NSInteger scale;
@property (nonatomic, copy) NSString *serial;
@property (nonatomic, retain) GTLBooksUsersettings *settings;
@property (nonatomic, copy) NSString *shelf;
@property (nonatomic, assign) BOOL showDeleted;
@property (nonatomic, assign) BOOL showOnlySummaryInResponse;
@property (nonatomic, assign) BOOL showPreorders;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, assign) NSUInteger startIndex;
@property (nonatomic, copy) NSString *startOffset;
@property (nonatomic, copy) NSString *startPosition;
@property (nonatomic, copy) NSString *summaryId;
@property (nonatomic, copy) NSString *timestamp;
@property (nonatomic, copy) NSString *updatedMax;
@property (nonatomic, copy) NSString *updatedMin;
@property (nonatomic, copy) NSString *uploadClientToken;
@property (nonatomic, assign) BOOL userLibraryConsistentRead;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *volumeAnnotationsVersion;
// "volumeId" has different types for some query methods; see the documentation
// for the right type for each query method.
@property (nonatomic, retain) id volumeId;
@property (nonatomic, retain) NSArray *volumeIds;  // of NSString
@property (nonatomic, assign) NSInteger volumePosition;
@property (nonatomic, assign) NSInteger w;

#pragma mark -
#pragma mark "bookshelves" methods
// These create a GTLQueryBooks object.

// Method: books.bookshelves.get
// Retrieves metadata for a specific bookshelf for the specified user.
//  Required:
//   userId: ID of user for whom to retrieve bookshelves.
//   shelf: ID of bookshelf to retrieve.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelf.
+ (instancetype)queryForBookshelvesGetWithUserId:(NSString *)userId
                                           shelf:(NSString *)shelf;

// Method: books.bookshelves.list
// Retrieves a list of public bookshelves for the specified user.
//  Required:
//   userId: ID of user for whom to retrieve bookshelves.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelves.
+ (instancetype)queryForBookshelvesListWithUserId:(NSString *)userId;

#pragma mark -
#pragma mark "bookshelves.volumes" methods
// These create a GTLQueryBooks object.

// Method: books.bookshelves.volumes.list
// Retrieves volumes in a specific bookshelf for the specified user.
//  Required:
//   userId: ID of user for whom to retrieve bookshelf volumes.
//   shelf: ID of bookshelf to retrieve volumes.
//  Optional:
//   maxResults: Maximum number of results to return
//   showPreorders: Set to true to show pre-ordered books. Defaults to false.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first element to return (starts at 0)
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForBookshelvesVolumesListWithUserId:(NSString *)userId
                                                   shelf:(NSString *)shelf;

#pragma mark -
#pragma mark "cloudloading" methods
// These create a GTLQueryBooks object.

// Method: books.cloudloading.addBook

//  Optional:
//   driveDocumentId: A drive document id. The upload_client_token must not be
//     set.
//   mimeType: The document MIME type. It can be set only if the
//     drive_document_id is set.
//   name: The document name. It can be set only if the drive_document_id is
//     set.
//   uploadClientToken: NSString
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksCloudloadingResource.
+ (instancetype)queryForCloudloadingAddBook;

// Method: books.cloudloading.deleteBook
// Remove the book and its contents
//  Required:
//   volumeId: The id of the book to be removed.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForCloudloadingDeleteBookWithVolumeId:(NSString *)volumeId;

// Method: books.cloudloading.updateBook

//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksCloudloadingResource.
+ (instancetype)queryForCloudloadingUpdateBookWithObject:(GTLBooksCloudloadingResource *)object;

#pragma mark -
#pragma mark "dictionary" methods
// These create a GTLQueryBooks object.

// Method: books.dictionary.listOfflineMetadata
// Returns a list of offline dictionary meatadata available
//  Required:
//   cpksver: The device/version ID from which to request the data.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksMetadata.
+ (instancetype)queryForDictionaryListOfflineMetadataWithCpksver:(NSString *)cpksver;

#pragma mark -
#pragma mark "layers.annotationData" methods
// These create a GTLQueryBooks object.

// Method: books.layers.annotationData.get
// Gets the annotation data.
//  Required:
//   volumeId: The volume to retrieve annotations for.
//   layerId: The ID for the layer to get the annotations.
//   annotationDataId: The ID of the annotation data to retrieve.
//   contentVersion: The content version for the volume you are trying to
//     retrieve.
//  Optional:
//   allowWebDefinitions: For the dictionary layer. Whether or not to allow web
//     definitions.
//   h: The requested pixel height for any images. If height is provided width
//     must also be provided.
//   locale: The locale information for the data. ISO-639-1 language and
//     ISO-3166-1 country code. Ex: 'en_US'.
//   scale: The requested scale for the image.
//   source: String to identify the originator of this request.
//   w: The requested pixel width for any images. If width is provided height
//     must also be provided.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksAnnotationdata.
+ (instancetype)queryForLayersAnnotationDataGetWithVolumeId:(NSString *)volumeId
                                                    layerId:(NSString *)layerId
                                           annotationDataId:(NSString *)annotationDataId
                                             contentVersion:(NSString *)contentVersion;

// Method: books.layers.annotationData.list
// Gets the annotation data for a volume and layer.
//  Required:
//   volumeId: The volume to retrieve annotation data for.
//   layerId: The ID for the layer to get the annotation data.
//   contentVersion: The content version for the requested volume.
//  Optional:
//   annotationDataId: The list of Annotation Data Ids to retrieve. Pagination
//     is ignored if this is set.
//     Note: For this method, "annotationDataId" should be of type NSArray.
//   h: The requested pixel height for any images. If height is provided width
//     must also be provided.
//   locale: The locale information for the data. ISO-639-1 language and
//     ISO-3166-1 country code. Ex: 'en_US'.
//   maxResults: Maximum number of results to return (0..200)
//   pageToken: The value of the nextToken from the previous page.
//   scale: The requested scale for the image.
//   source: String to identify the originator of this request.
//   updatedMax: RFC 3339 timestamp to restrict to items updated prior to this
//     timestamp (exclusive).
//   updatedMin: RFC 3339 timestamp to restrict to items updated since this
//     timestamp (inclusive).
//   w: The requested pixel width for any images. If width is provided height
//     must also be provided.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksAnnotationsdata.
+ (instancetype)queryForLayersAnnotationDataListWithVolumeId:(NSString *)volumeId
                                                     layerId:(NSString *)layerId
                                              contentVersion:(NSString *)contentVersion;

#pragma mark -
#pragma mark "layers" methods
// These create a GTLQueryBooks object.

// Method: books.layers.get
// Gets the layer summary for a volume.
//  Required:
//   volumeId: The volume to retrieve layers for.
//   summaryId: The ID for the layer to get the summary for.
//  Optional:
//   contentVersion: The content version for the requested volume.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksLayersummary.
+ (instancetype)queryForLayersGetWithVolumeId:(NSString *)volumeId
                                    summaryId:(NSString *)summaryId;

// Method: books.layers.list
// List the layer summaries for a volume.
//  Required:
//   volumeId: The volume to retrieve layers for.
//  Optional:
//   contentVersion: The content version for the requested volume.
//   maxResults: Maximum number of results to return (0..200)
//   pageToken: The value of the nextToken from the previous page.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksLayersummaries.
+ (instancetype)queryForLayersListWithVolumeId:(NSString *)volumeId;

#pragma mark -
#pragma mark "layers.volumeAnnotations" methods
// These create a GTLQueryBooks object.

// Method: books.layers.volumeAnnotations.get
// Gets the volume annotation.
//  Required:
//   volumeId: The volume to retrieve annotations for.
//   layerId: The ID for the layer to get the annotations.
//   annotationId: The ID of the volume annotation to retrieve.
//  Optional:
//   locale: The locale information for the data. ISO-639-1 language and
//     ISO-3166-1 country code. Ex: 'en_US'.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumeannotation.
+ (instancetype)queryForLayersVolumeAnnotationsGetWithVolumeId:(NSString *)volumeId
                                                       layerId:(NSString *)layerId
                                                  annotationId:(NSString *)annotationId;

// Method: books.layers.volumeAnnotations.list
// Gets the volume annotations for a volume and layer.
//  Required:
//   volumeId: The volume to retrieve annotations for.
//   layerId: The ID for the layer to get the annotations.
//   contentVersion: The content version for the requested volume.
//  Optional:
//   endOffset: The end offset to end retrieving data from.
//   endPosition: The end position to end retrieving data from.
//   locale: The locale information for the data. ISO-639-1 language and
//     ISO-3166-1 country code. Ex: 'en_US'.
//   maxResults: Maximum number of results to return (0..200)
//   pageToken: The value of the nextToken from the previous page.
//   showDeleted: Set to true to return deleted annotations. updatedMin must be
//     in the request to use this. Defaults to false.
//   source: String to identify the originator of this request.
//   startOffset: The start offset to start retrieving data from.
//   startPosition: The start position to start retrieving data from.
//   updatedMax: RFC 3339 timestamp to restrict to items updated prior to this
//     timestamp (exclusive).
//   updatedMin: RFC 3339 timestamp to restrict to items updated since this
//     timestamp (inclusive).
//   volumeAnnotationsVersion: The version of the volume annotations that you
//     are requesting.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumeannotations.
+ (instancetype)queryForLayersVolumeAnnotationsListWithVolumeId:(NSString *)volumeId
                                                        layerId:(NSString *)layerId
                                                 contentVersion:(NSString *)contentVersion;

#pragma mark -
#pragma mark "myconfig" methods
// These create a GTLQueryBooks object.

// Method: books.myconfig.getUserSettings
// Gets the current settings for the user.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksUsersettings.
+ (instancetype)queryForMyconfigGetUserSettings;

// Method: books.myconfig.releaseDownloadAccess
// Release downloaded content access restriction.
//  Required:
//   volumeIds: The volume(s) to release restrictions for.
//   cpksver: The device/version ID from which to release the restriction.
//  Optional:
//   locale: ISO-639-1, ISO-3166-1 codes for message localization, i.e. en_US.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksDownloadAccesses.
+ (instancetype)queryForMyconfigReleaseDownloadAccessWithVolumeIds:(NSArray *)volumeIds
                                                           cpksver:(NSString *)cpksver;

// Method: books.myconfig.requestAccess
// Request concurrent and download access restrictions.
//  Required:
//   source: String to identify the originator of this request.
//   volumeId: The volume to request concurrent/download restrictions for.
//   nonce: The client nonce value.
//   cpksver: The device/version ID from which to request the restrictions.
//  Optional:
//   licenseTypes: The type of access license to request. If not specified, the
//     default is BOTH.
//      kGTLBooksLicenseTypesBoth: Both concurrent and download licenses.
//      kGTLBooksLicenseTypesConcurrent: Concurrent access license.
//      kGTLBooksLicenseTypesDownload: Offline download access license.
//   locale: ISO-639-1, ISO-3166-1 codes for message localization, i.e. en_US.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksRequestAccess.
+ (instancetype)queryForMyconfigRequestAccessWithSource:(NSString *)source
                                               volumeId:(NSString *)volumeId
                                                  nonce:(NSString *)nonce
                                                cpksver:(NSString *)cpksver;

// Method: books.myconfig.syncVolumeLicenses
// Request downloaded content access for specified volumes on the My eBooks
// shelf.
//  Required:
//   source: String to identify the originator of this request.
//   nonce: The client nonce value.
//   cpksver: The device/version ID from which to release the restriction.
//  Optional:
//   features: List of features supported by the client, i.e., 'RENTALS'
//      kGTLBooksFeaturesRentals: Client supports rentals.
//   locale: ISO-639-1, ISO-3166-1 codes for message localization, i.e. en_US.
//   showPreorders: Set to true to show pre-ordered books. Defaults to false.
//   volumeIds: The volume(s) to request download restrictions for.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForMyconfigSyncVolumeLicensesWithSource:(NSString *)source
                                                       nonce:(NSString *)nonce
                                                     cpksver:(NSString *)cpksver;

// Method: books.myconfig.updateUserSettings
// Sets the settings for the user. If a sub-object is specified, it will
// overwrite the existing sub-object stored in the server. Unspecified
// sub-objects will retain the existing value.
//  Optional:
//   settings: GTLBooksUsersettings
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksUsersettings.
+ (instancetype)queryForMyconfigUpdateUserSettings;

#pragma mark -
#pragma mark "mylibrary.annotations" methods
// These create a GTLQueryBooks object.

// Method: books.mylibrary.annotations.delete
// Deletes an annotation.
//  Required:
//   annotationId: The ID for the annotation to delete.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForMylibraryAnnotationsDeleteWithAnnotationId:(NSString *)annotationId;

// Method: books.mylibrary.annotations.insert
// Inserts a new annotation.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   showOnlySummaryInResponse: Requests that only the summary of the specified
//     layer be provided in the response.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksAnnotation.
+ (instancetype)queryForMylibraryAnnotationsInsertWithObject:(GTLBooksAnnotation *)object;

// Method: books.mylibrary.annotations.list
// Retrieves a list of annotations, possibly filtered.
//  Optional:
//   contentVersion: The content version for the requested volume.
//   layerId: The layer ID to limit annotation by.
//   layerIds: The layer ID(s) to limit annotation by.
//   maxResults: Maximum number of results to return (0..40)
//   pageToken: The value of the nextToken from the previous page.
//   showDeleted: Set to true to return deleted annotations. updatedMin must be
//     in the request to use this. Defaults to false.
//   source: String to identify the originator of this request.
//   updatedMax: RFC 3339 timestamp to restrict to items updated prior to this
//     timestamp (exclusive).
//   updatedMin: RFC 3339 timestamp to restrict to items updated since this
//     timestamp (inclusive).
//   volumeId: The volume to restrict annotations to.
//     Note: For this method, "volumeId" should be of type NSString.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksAnnotations.
+ (instancetype)queryForMylibraryAnnotationsList;

// Method: books.mylibrary.annotations.summary
// Gets the summary of specified layers.
//  Required:
//   layerIds: Array of layer IDs to get the summary for.
//   volumeId: Volume id to get the summary for.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksAnnotationsSummary.
+ (instancetype)queryForMylibraryAnnotationsSummaryWithLayerIds:(NSArray *)layerIds
                                                       volumeId:(NSString *)volumeId;

// Method: books.mylibrary.annotations.update
// Updates an existing annotation.
//  Required:
//   annotationId: The ID for the annotation to update.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksAnnotation.
+ (instancetype)queryForMylibraryAnnotationsUpdateWithObject:(GTLBooksAnnotation *)object
                                                annotationId:(NSString *)annotationId;

#pragma mark -
#pragma mark "mylibrary.bookshelves" methods
// These create a GTLQueryBooks object.

// Method: books.mylibrary.bookshelves.addVolume
// Adds a volume to a bookshelf.
//  Required:
//   shelf: ID of bookshelf to which to add a volume.
//   volumeId: ID of volume to add.
//  Optional:
//   reason: The reason for which the book is added to the library.
//      kGTLBooksReasonIosPrex: Volumes added from the PREX flow on iOS.
//      kGTLBooksReasonIosSearch: Volumes added from the Search flow on iOS.
//      kGTLBooksReasonOnboarding: Volumes added from the Onboarding flow.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForMylibraryBookshelvesAddVolumeWithShelf:(NSString *)shelf
                                                      volumeId:(NSString *)volumeId;

// Method: books.mylibrary.bookshelves.clearVolumes
// Clears all volumes from a bookshelf.
//  Required:
//   shelf: ID of bookshelf from which to remove a volume.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForMylibraryBookshelvesClearVolumesWithShelf:(NSString *)shelf;

// Method: books.mylibrary.bookshelves.get
// Retrieves metadata for a specific bookshelf belonging to the authenticated
// user.
//  Required:
//   shelf: ID of bookshelf to retrieve.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelf.
+ (instancetype)queryForMylibraryBookshelvesGetWithShelf:(NSString *)shelf;

// Method: books.mylibrary.bookshelves.list
// Retrieves a list of bookshelves belonging to the authenticated user.
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksBookshelves.
+ (instancetype)queryForMylibraryBookshelvesList;

// Method: books.mylibrary.bookshelves.moveVolume
// Moves a volume within a bookshelf.
//  Required:
//   shelf: ID of bookshelf with the volume.
//   volumeId: ID of volume to move.
//   volumePosition: Position on shelf to move the item (0 puts the item before
//     the current first item, 1 puts it between the first and the second and so
//     on.)
//  Optional:
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForMylibraryBookshelvesMoveVolumeWithShelf:(NSString *)shelf
                                                       volumeId:(NSString *)volumeId
                                                 volumePosition:(NSInteger)volumePosition;

// Method: books.mylibrary.bookshelves.removeVolume
// Removes a volume from a bookshelf.
//  Required:
//   shelf: ID of bookshelf from which to remove a volume.
//   volumeId: ID of volume to remove.
//  Optional:
//   reason: The reason for which the book is removed from the library.
//      kGTLBooksReasonOnboarding: Samples removed from the Onboarding flow.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForMylibraryBookshelvesRemoveVolumeWithShelf:(NSString *)shelf
                                                         volumeId:(NSString *)volumeId;

#pragma mark -
#pragma mark "mylibrary.bookshelves.volumes" methods
// These create a GTLQueryBooks object.

// Method: books.mylibrary.bookshelves.volumes.list
// Gets volume information for volumes on a bookshelf.
//  Required:
//   shelf: The bookshelf ID or name retrieve volumes for.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   maxResults: Maximum number of results to return
//   projection: Restrict information returned to a set of selected fields.
//      kGTLBooksProjectionFull: Includes all volume data.
//      kGTLBooksProjectionLite: Includes a subset of fields in volumeInfo and
//        accessInfo.
//   q: Full-text search query string in this bookshelf.
//   showPreorders: Set to true to show pre-ordered books. Defaults to false.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first element to return (starts at 0)
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForMylibraryBookshelvesVolumesListWithShelf:(NSString *)shelf;

#pragma mark -
#pragma mark "mylibrary.readingpositions" methods
// These create a GTLQueryBooks object.

// Method: books.mylibrary.readingpositions.get
// Retrieves my reading position information for a volume.
//  Required:
//   volumeId: ID of volume for which to retrieve a reading position.
//  Optional:
//   contentVersion: Volume content version for which this reading position is
//     requested.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksReadingPosition.
+ (instancetype)queryForMylibraryReadingpositionsGetWithVolumeId:(NSString *)volumeId;

// Method: books.mylibrary.readingpositions.setPosition
// Sets my reading position information for a volume.
//  Required:
//   volumeId: ID of volume for which to update the reading position.
//   timestamp: RFC 3339 UTC format timestamp associated with this reading
//     position.
//   position: Position string for the new volume reading position.
//  Optional:
//   action: Action that caused this reading position to be set.
//      kGTLBooksActionBookmark: User chose bookmark within volume.
//      kGTLBooksActionChapter: User selected chapter from list.
//      kGTLBooksActionNextPage: Next page event.
//      kGTLBooksActionPrevPage: Previous page event.
//      kGTLBooksActionScroll: User navigated to page.
//      kGTLBooksActionSearch: User chose search results within volume.
//   contentVersion: Volume content version for which this reading position
//     applies.
//   deviceCookie: Random persistent device cookie optional on set position.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForMylibraryReadingpositionsSetPositionWithVolumeId:(NSString *)volumeId
                                                               timestamp:(NSString *)timestamp
                                                                position:(NSString *)position;

#pragma mark -
#pragma mark "onboarding" methods
// These create a GTLQueryBooks object.

// Method: books.onboarding.listCategories
// List categories for onboarding experience.
//  Optional:
//   locale: ISO-639-1 language and ISO-3166-1 country code. Default is en-US if
//     unset.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksCategory.
+ (instancetype)queryForOnboardingListCategories;

// Method: books.onboarding.listCategoryVolumes
// List available volumes under categories for onboarding experience.
//  Optional:
//   categoryId: List of category ids requested.
//   locale: ISO-639-1 language and ISO-3166-1 country code. Default is en-US if
//     unset.
//   maxAllowedMaturityRating: The maximum allowed maturity rating of returned
//     volumes. Books with a higher maturity rating are filtered out.
//      kGTLBooksMaxAllowedMaturityRatingMature: Show books which are rated
//        mature or lower.
//      kGTLBooksMaxAllowedMaturityRatingNotMature: Show books which are rated
//        not mature.
//   pageSize: Number of maximum results per page to be included in the
//     response.
//   pageToken: The value of the nextToken from the previous page.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolume2.
+ (instancetype)queryForOnboardingListCategoryVolumes;

#pragma mark -
#pragma mark "promooffer" methods
// These create a GTLQueryBooks object.

// Method: books.promooffer.accept

//  Optional:
//   androidId: device android_id
//   device: device device
//   manufacturer: device manufacturer
//   model: device model
//   offerId: NSString
//   product: device product
//   serial: device serial
//   volumeId: Volume id to exercise the offer
//     Note: For this method, "volumeId" should be of type NSString.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForPromoofferAccept;

// Method: books.promooffer.dismiss

//  Optional:
//   androidId: device android_id
//   device: device device
//   manufacturer: device manufacturer
//   model: device model
//   offerId: Offer to dimiss
//   product: device product
//   serial: device serial
//  Authorization scope(s):
//   kGTLAuthScopeBooks
+ (instancetype)queryForPromoofferDismiss;

// Method: books.promooffer.get
// Returns a list of promo offers available to the user
//  Optional:
//   androidId: device android_id
//   device: device device
//   manufacturer: device manufacturer
//   model: device model
//   product: device product
//   serial: device serial
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksOffers.
+ (instancetype)queryForPromoofferGet;

#pragma mark -
#pragma mark "volumes.associated" methods
// These create a GTLQueryBooks object.

// Method: books.volumes.associated.list
// Return a list of associated books.
//  Required:
//   volumeId: ID of the source volume.
//  Optional:
//   association: Association type.
//      kGTLBooksAssociationEndOfSample: Recommendations for display
//        end-of-sample.
//      kGTLBooksAssociationEndOfVolume: Recommendations for display
//        end-of-volume.
//      kGTLBooksAssociationRelatedForPlay: Related volumes for Play Store.
//   locale: ISO-639-1 language and ISO-3166-1 country code. Ex: 'en_US'. Used
//     for generating recommendations.
//   maxAllowedMaturityRating: The maximum allowed maturity rating of returned
//     recommendations. Books with a higher maturity rating are filtered out.
//      kGTLBooksMaxAllowedMaturityRatingMature: Show books which are rated
//        mature or lower.
//      kGTLBooksMaxAllowedMaturityRatingNotMature: Show books which are rated
//        not mature.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForVolumesAssociatedListWithVolumeId:(NSString *)volumeId;

#pragma mark -
#pragma mark "volumes" methods
// These create a GTLQueryBooks object.

// Method: books.volumes.get
// Gets volume information for a single volume.
//  Required:
//   volumeId: ID of volume to retrieve.
//  Optional:
//   country: ISO-3166-1 code to override the IP-based location.
//   partner: Brand results for partner ID.
//   projection: Restrict information returned to a set of selected fields.
//      kGTLBooksProjectionFull: Includes all volume data.
//      kGTLBooksProjectionLite: Includes a subset of fields in volumeInfo and
//        accessInfo.
//   source: String to identify the originator of this request.
//   userLibraryConsistentRead: BOOL
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolume.
+ (instancetype)queryForVolumesGetWithVolumeId:(NSString *)volumeId;

// Method: books.volumes.list
// Performs a book search.
//  Required:
//   q: Full-text search query string.
//  Optional:
//   download: Restrict to volumes by download availability.
//      kGTLBooksDownloadEpub: All volumes with epub.
//   filter: Filter search results.
//      kGTLBooksFilterEbooks: All Google eBooks.
//      kGTLBooksFilterFreeEbooks: Google eBook with full volume text
//        viewability.
//      kGTLBooksFilterFull: Public can view entire volume text.
//      kGTLBooksFilterPaidEbooks: Google eBook with a price.
//      kGTLBooksFilterPartial: Public able to see parts of text.
//   langRestrict: Restrict results to books with this language code.
//   libraryRestrict: Restrict search to this user's library.
//      kGTLBooksLibraryRestrictMyLibrary: Restrict to the user's library, any
//        shelf.
//      kGTLBooksLibraryRestrictNoRestrict: Do not restrict based on user's
//        library.
//   maxResults: Maximum number of results to return. (0..40)
//   orderBy: Sort search results.
//      kGTLBooksOrderByNewest: Most recently published.
//      kGTLBooksOrderByRelevance: Relevance to search terms.
//   partner: Restrict and brand results for partner ID.
//   printType: Restrict to books or magazines.
//      kGTLBooksPrintTypeAll: All volume content types.
//      kGTLBooksPrintTypeBooks: Just books.
//      kGTLBooksPrintTypeMagazines: Just magazines.
//   projection: Restrict information returned to a set of selected fields.
//      kGTLBooksProjectionFull: Includes all volume data.
//      kGTLBooksProjectionLite: Includes a subset of fields in volumeInfo and
//        accessInfo.
//   showPreorders: Set to true to show books available for preorder. Defaults
//     to false.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first result to return (starts at 0)
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForVolumesListWithQ:(NSString *)q;

#pragma mark -
#pragma mark "volumes.mybooks" methods
// These create a GTLQueryBooks object.

// Method: books.volumes.mybooks.list
// Return a list of books in My Library.
//  Optional:
//   acquireMethod: How the book was aquired
//      kGTLBooksAcquireMethodPreordered: Preordered books (not yet available)
//      kGTLBooksAcquireMethodPreviouslyRented: User-rented books past their
//        expiration time
//      kGTLBooksAcquireMethodPublicDomain: Public domain books
//      kGTLBooksAcquireMethodPurchased: Purchased books
//      kGTLBooksAcquireMethodRented: User-rented books
//      kGTLBooksAcquireMethodSample: Sample books
//      kGTLBooksAcquireMethodUploaded: User uploaded books
//   locale: ISO-639-1 language and ISO-3166-1 country code. Ex:'en_US'. Used
//     for generating recommendations.
//   maxResults: Maximum number of results to return. (0..100)
//   processingState: The processing state of the user uploaded volumes to be
//     returned. Applicable only if the UPLOADED is specified in the
//     acquireMethod.
//      kGTLBooksProcessingStateCompletedFailed: The volume processing hase
//        failed.
//      kGTLBooksProcessingStateCompletedSuccess: The volume processing was
//        completed.
//      kGTLBooksProcessingStateRunning: The volume processing is not completed.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first result to return (starts at 0)
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForVolumesMybooksList;

#pragma mark -
#pragma mark "volumes.recommended" methods
// These create a GTLQueryBooks object.

// Method: books.volumes.recommended.list
// Return a list of recommended books for the current user.
//  Optional:
//   locale: ISO-639-1 language and ISO-3166-1 country code. Ex: 'en_US'. Used
//     for generating recommendations.
//   maxAllowedMaturityRating: The maximum allowed maturity rating of returned
//     recommendations. Books with a higher maturity rating are filtered out.
//      kGTLBooksMaxAllowedMaturityRatingMature: Show books which are rated
//        mature or lower.
//      kGTLBooksMaxAllowedMaturityRatingNotMature: Show books which are rated
//        not mature.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForVolumesRecommendedList;

// Method: books.volumes.recommended.rate
// Rate a recommended book for the current user.
//  Required:
//   rating: Rating to be given to the volume.
//      kGTLBooksRatingHaveIt: Rating indicating a dismissal due to ownership.
//      kGTLBooksRatingNotInterested: Rating indicating a negative dismissal of
//        a volume.
//   volumeId: ID of the source volume.
//  Optional:
//   locale: ISO-639-1 language and ISO-3166-1 country code. Ex: 'en_US'. Used
//     for generating recommendations.
//   source: String to identify the originator of this request.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumesRecommendedRateResponse.
+ (instancetype)queryForVolumesRecommendedRateWithRating:(NSString *)rating
                                                volumeId:(NSString *)volumeId;

#pragma mark -
#pragma mark "volumes.useruploaded" methods
// These create a GTLQueryBooks object.

// Method: books.volumes.useruploaded.list
// Return a list of books uploaded by the current user.
//  Optional:
//   locale: ISO-639-1 language and ISO-3166-1 country code. Ex: 'en_US'. Used
//     for generating recommendations.
//   maxResults: Maximum number of results to return. (0..40)
//   processingState: The processing state of the user uploaded volumes to be
//     returned.
//      kGTLBooksProcessingStateCompletedFailed: The volume processing hase
//        failed.
//      kGTLBooksProcessingStateCompletedSuccess: The volume processing was
//        completed.
//      kGTLBooksProcessingStateRunning: The volume processing is not completed.
//   source: String to identify the originator of this request.
//   startIndex: Index of the first result to return (starts at 0)
//   volumeId: The ids of the volumes to be returned. If not specified all that
//     match the processingState are returned.
//     Note: For this method, "volumeId" should be of type NSArray.
//  Authorization scope(s):
//   kGTLAuthScopeBooks
// Fetches a GTLBooksVolumes.
+ (instancetype)queryForVolumesUseruploadedList;

@end
