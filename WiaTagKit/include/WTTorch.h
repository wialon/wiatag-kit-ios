//
//  WTTorch.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/5/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"
#import "WTTorchState.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTTorch : WTBaseCommand

@property (nonatomic, assign, readonly) WTTorchState state;

@end

NS_ASSUME_NONNULL_END
