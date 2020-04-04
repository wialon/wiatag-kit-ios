//
//  WTRemotable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/10/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIApplication.h>
#import "WTGlobalVariables.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WTRemotable <NSObject>

/**
 * Use this method to register for remote notification.
 @param application is a shared application instance.

 @code
 [remotableObj registerForRemoteNotificationsWithApplication:[UIApplication sharedApplication]];
 @endcode
 */
- (void)registerForRemoteNotificationsWithApplication:(UIApplication *)application;

/**
 * Use this method to register for remote notification.
 @param application is a shared application instance.
 @param completion is a block to handle completion.

 @code
 [remotableObj registerForRemoteNotificationsWithApplication:[UIApplication sharedApplication] completion:nil];
 @endcode
 */
- (void)registerForRemoteNotificationsWithApplication:(UIApplication *)application
                                           completion:(nullable void (^) (void))completion;

/**
 * Use this method to register for remote notification after receiving device token.
 @param serviceName is a bundle identifier.
 @param deviceToken is an APNS token.
 @param completion is a block to handle completion. If registration was successfully, it will be executed with nil error, otherwise you can handle an error message

 @code
 [remotableObj registerForRemoteNotificationsWithServiceName:[[NSBundle mainBundle] bundleIdentifier] deviceToken:deviceToken completion:completion];
 @endcode
 */
- (void)registerForRemoteNotificationsWithServiceName:(NSString *)serviceName
                                          deviceToken:(NSData *)deviceToken
                                           completion:(nullable baseCompletion)completion;

/**
 * Use this method to register for remote notification after receiving device token.
 @param serviceName is a bundle identifier.
 @param deviceToken is an APNS token.
 @param completion is a block to handle completion. If registration was successfully, it will be executed with nil error, otherwise you can handle an error message

 @code
 [remotableObj registerForRemoteNotificationsWithServiceName:[[NSBundle mainBundle] bundleIdentifier] deviceTokenStringRepresentation:deviceToken completion:completion];
 @endcode
 */
- (void)registerForRemoteNotificationsWithServiceName:(NSString *)serviceName
                                          deviceTokenStringRepresentation:(NSString *)deviceToken
                                           completion:(nullable baseCompletion)completion;

/**
 * Use this method to unregister for remote notification.
 @param application is a shared application instance.

 @code
 [remotableObj unregisterForRemoteNotificationsWithApplication:[UIApplication sharedApplication]];
 @endcode
 */
- (void)unregisterForRemoteNotificationsWithApplication:(UIApplication *)application;

/**
 * Use this method to handle remote notification info.
 @param dict is a push notification info.
 @param completion is a block to handle completion. If info was parsed successfully, it will be executed with UIBackgroundFetchResultNewData or UIBackgroundFetchResultNoData, otherwise you can handle UIBackgroundFetchResultFailed.

 @code
 [remotableObj handleRemoteNotificationWithDict:info completion completion];
 @endcode
 */
- (void)handleRemoteNotificationWithDict:(NSDictionary<NSString *, id> *)dict
                              completion:(void (^) (UIBackgroundFetchResult))completion;

@end

NS_ASSUME_NONNULL_END
