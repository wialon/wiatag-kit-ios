//
//  WTMessageManagable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/11/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTListeanable.h"
#import "WTRemotable.h"
#import "WTSendable.h"
#import "WTConfigurable.h"
#import "WTInitializable.h"
#import "WTLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WTMessageManagable <WTListenable, WTRemotable, WTSendable, WTConfigurable, WTInitializable>

- (void)setLogLevel:(WTLogLevel)logLevel;
- (void)checkUpdates;
- (void)authorize:(baseCompletion)completion;
- (void)requestConfig;

@end

NS_ASSUME_NONNULL_END
