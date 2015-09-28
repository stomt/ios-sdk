//
//  STFeed.h
//  StomtiOS
//
//  Created by Leonardo Cascianelli on 24/09/15.
//  Copyright (c) 2015 Leonardo Cascianelli. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "declarations.h"

@class STSearchFilterKeywords;

/*!
 
 @brief Represents a filtered Stomt research.
 @discussion The @p STFeed class is used to represent a filtered Stomt research. Research filters are passed via the @p feedWithTerm initialization method, and the result is stored in the returned @p STFeed object.
 
 */
@interface STFeed : NSObject

/// A @p NSMutableArray containing filtered stomts.
@property (nonatomic,strong) NSMutableArray* stomts;

/// An @p NSMutableDictionary containing filters.
@property (nonatomic,strong) NSMutableDictionary* params;

/*!
 
 @brief Return a filtered STFeed research object.
 
 @param term Query for the stomt text.

 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWithTerm:(NSString*)term;

/*!
 
 @brief Return a filtered STFeed research object.
 
 @param belongsTargetID Filter stomts that belong to the given target.
 
 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWhichBelongsTo:(NSString*)belongsTargetID;

/*!
 
 @brief Return a filtered STFeed research object.

 @param directTargetIDs Filter stomts the targets have received directly.
 
 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWithStomtsDirectlyReceivedBy:(NSArray*)directTargetIDs;

/*!
 
 @brief Return a filtered STFeed research object.

 @param keywords Filter for stomts matching the criteria.

 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWithFilterKeywords:(NSArray*)keywords;

/*!
 
 @brief Return a filtered STFeed research object.

 @param likeOrWish Either filter for likes or wishes.
 
 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWithLikeOrWish:(kSTObjectQualifier)likeOrWish;

/*!
 
 @brief Return a filtered STFeed research object.
 
 @param labels Filter for stomts that contain all given labels.
 
 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWhichContainsLabels:(NSArray*)labels;

/*!
 
 @brief Return a filtered STFeed research object.
 @param term Query for the stomt text.
 @param belongsTargetID Filter stomts that belong to the given target.
 @param directTargetIDs Filter stomts the targets have received directly.
 @param fromTargetIDs Filter for stomts created by specific users.
 @param keywords Filter for stomts matching the criteria.
 @param likeOrWish Either filter for likes or wishes.
 @param labels Filter for stomts that contain all given labels.
 @return Returns an @p STFeed object on success. Returns @p nil on error.
 
 */
+ (instancetype)feedWithTerm:(NSString*)term
				   belongsTo:(NSString*)belongsTargetID
		  directlyReceivedBy:(NSArray*)directTargetIDs
					  sentBy:(NSArray*)fromTargetIDs
			  filterKeywords:(STSearchFilterKeywords *)keywords
				  likeOrWish:(kSTObjectQualifier)likeOrWish
			  containsLabels:(NSArray*)labels;

/*!
 
 @brief Creates a stomts list using a raw HTTP response, contained in the @p array param.
 @warning Internal function. Avoid.
 
 */
+ (instancetype)feedWithStomtsArray:(NSArray*)array;
@end
