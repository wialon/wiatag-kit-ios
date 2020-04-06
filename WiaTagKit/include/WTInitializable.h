//
//  WTInitializable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 4/6/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WTInitializable <NSObject>

/**
 * Use this method to setup WTInitializable object.
 @param host is a host.
 @param port is a port.
 @param deviceId is a unitId.
 @param password is a password.

 @code
 [sendableObj initWithHost:@"111.111.111.111" port:1111 deviceId:@"unit_id" password:@"123"];
 @endcode
 */
- (instancetype)initWithHost:(NSString *)host
                        port:(NSUInteger)port
                    deviceId:(NSString *)deviceId
                    password:(nullable NSString *)password;

@end

NS_ASSUME_NONNULL_END
