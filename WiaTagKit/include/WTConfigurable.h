//
//  WTConfigurable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/11/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WTConfigurable <NSObject>

/**
 * Use this method to enable chat.
 @param completion is a block to handle completion.

 @code
 [remotableObj enableChatWithCompletion:completion];
 @endcode
 */
- (void)enableChatWithCompletion:(nullable baseCompletion)completion;

/**
 * Use this method to disable chat.
 @param completion is a block to handle completion.

 @code
 [remotableObj disableChatWithCompletion:completion];
 @endcode
 */
- (void)disableChatWithCompletion:(nullable baseCompletion)completion;

/**
 * Use this method to enable remote control.
 @param completion is a block to handle completion.

 @code
 [remotableObj enableRemoteControlWithCompletion:completion];
 @endcode
 */
- (void)enableRemoteControlWithCompletion:(nullable baseCompletion)completion;

/**
 * Use this method to disable remote control.
 @param completion is a block to handle completion.

 @code
 [remotableObj disableRemoteControlWithCompletion:completion];
 @endcode
 */
- (void)disableRemoteControlWithCompletion:(nullable baseCompletion)completion;

/**
 * Use this method to enable chat and remote control.
 @param completion is a block to handle completion.

 @code
 [remotableObj enableAllServicesWithCompletion:completion];
 @endcode
 */
- (void)enableAllServicesWithCompletion:(nullable baseCompletion)completion;

/**
 * Use this method to disable chat and remote control.
 @param completion is a block to handle completion.

 @code
 [remotableObj disableAllServicesWithCompletion:completion];
 @endcode
 */
- (void)disableAllServicesWithCompletion:(nullable baseCompletion)completion;

@end

NS_ASSUME_NONNULL_END
