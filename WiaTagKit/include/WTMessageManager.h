//
//  WTMessageManager.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/6/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTMessageManagable.h"
#import "WTMessage.h"
#import "WTDuplicatable.h"
#import "WTLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTMessageManager : NSObject<WTMessageManagable>

@property (nonatomic, strong) id<WTDuplicatable> duplicationValidator;

- (instancetype) init __attribute__((unavailable("init not available, call initWithHost:port:deviceId:password instead")));
+ (instancetype) new __attribute__((unavailable("new not available, call initWithHost:port:deviceId:password instead")));

@end

NS_ASSUME_NONNULL_END
