//
//  WTService.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/5/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"
#import "WTServiceState.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTService : WTBaseCommand

@property (nonatomic, assign, readonly) WTServiceState state;
@property (nonatomic, strong, readonly) NSNumber *executionTime;

@end

NS_ASSUME_NONNULL_END
