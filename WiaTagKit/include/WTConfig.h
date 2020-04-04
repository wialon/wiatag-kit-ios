//
//  WTConfig.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/5/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTConfig : WTBaseCommand

@property (nonatomic, strong, readonly) NSDictionary *settings;

@end

NS_ASSUME_NONNULL_END
