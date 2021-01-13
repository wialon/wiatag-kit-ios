//
//  WTSendable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/10/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTGlobalVariables.h"

@class WTMessage;

NS_ASSUME_NONNULL_BEGIN

@protocol WTSendable <NSObject>

/// Use this method for disconnecting
- (void)disconnect;

/// Use this method for restarting connection
- (void)restart;

/**
 * Use this method to send message.
 @param message is a WTMessage object.
 @param completion is a block to handle completion. If message was sended successfully, it will be executed with nil error, otherwise you can handle an error message.

 @code
 [sendableObj sendMessage:message completion:completion];
 @endcode
 */
- (void)sendMessage:(WTMessage *)message
         completion:(baseCompletion)completion;

/**
 * Use this method to send messages.
 @param messages is an array of WTMessage objects.
 @param completion is a block to handle completion. If message was sended successfully, it will be executed with nil error, otherwise you can handle an error message and unsended messages.

 @code
 [sendableObj sendMessages:messages completion:completion];
 @endcode
 */
- (void)sendMessages:(NSArray <WTMessage *> *)messages
          completion:(sendMessagesCompletion)completion;

/**
 * Use this method to send remote control configuration.
 @param serviceName is a bundle identifier.
 @param apnsToken is an APNS token.
 @param fcmToken is an FCM token
 @param deviceId is a unitId.
 @param password is a password.
 @param isChatEnabled is an flag for enabling or disabling chat.
 @param isRemoteControlEnabled is an flag for enabling or disabling remote control.
 @param completion is a block to handle completion. If message was sended successfully, it will be executed with nil error, otherwise you can handle an error message.

 @code
 [sendableObj sendRemoteControlWithServiceName:[[NSBundle mainBundle] bundleIdentifier] apnsToken:apnsToken fcmToken:fcmToken deviceId:@"unit_id" password:@"123" isChatEnabled:true isRemoteControlEnabled:true completion:completion];
 @endcode
 */
- (void)sendRemoteControlWithServiceName:(NSString *)serviceName
                               apnsToken:(NSString *)apnsToken
                                fcmToken:(NSString *)fcmToken
                                deviceId:(NSString *)deviceId
                                password:(NSString *)password
                           isChatEnabled:(BOOL)isChatEnabled
                  isRemoteControlEnabled:(BOOL)isRemoteControlEnabled
                              completion:(nullable baseCompletion)completion;

@end

NS_ASSUME_NONNULL_END
