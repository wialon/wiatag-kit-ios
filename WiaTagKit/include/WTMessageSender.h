//
//  WTMessageSender.h
//  SendWiaTagData
//
/*
 WiaTagKit (c) by Gurtam
 
 WiaTagKit is licensed under a
 Creative Commons Attribution-NoDerivatives 4.0 International License.
 
 You should have received a copy of the license along with this
 work. If not, see <http://creativecommons.org/licenses/by-nd/4.0/>.
 */

#import <Foundation/Foundation.h>
#import "WTMessage.h"

typedef void (^sendCompletion)(NSError * _Nullable);

NS_ASSUME_NONNULL_BEGIN
/**
 * WTMessageSender class provides API for sending data with protocol WiaTag.
 */
@interface WTMessageSender : NSObject
/**
 * Use this init method to setup WTMessageSender object.
 @param host is a host.
 @param port is a port.
 @param unitId is a unitId.
 @param password is a password.
 */
- (instancetype)initWithHost:(NSString *)host port:(NSUInteger)port unitId:(NSString *)unitId password:(NSString * _Nullable)password;
/**
 * Function that sends single message.
 @param message a WTMessage object.
 @param completion a block to handle completion. If message was sended successfully, it will be executed with nil error, otherwise you can handle an error message.
 */
- (void)sendMessage:(WTMessage *)message completion:(sendCompletion)completion;
/**
 * Function that sends multiple messages.
 @param messages an array of WTMessage objects.
 @param completion a block to handle completion. If message was sended successfully, it will be executed with nil error, otherwise you can handle an error message.
 */
- (void)sendMessages:(NSArray <WTMessage *> *)messages completion:(sendCompletion)completion;
/**
 * Function that stops sending and closes network sockets that WTMessageSender uses.
 * If some messages were not sent, their completion block will be executed with error.
 */
- (void)stop;

@end

NS_ASSUME_NONNULL_END
