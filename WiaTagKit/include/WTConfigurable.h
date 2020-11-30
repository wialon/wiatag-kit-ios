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
 @code
 [remotableObj enableRemoteControl:YES andEnableChat:NO completion:completion];
 @endcode
 */
- (void)enableRemoteControl:(BOOL)isRCEnabled
              andEnableChat:(BOOL)isChatEnabled
                 completion:(nullable baseCompletion)completion;

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
