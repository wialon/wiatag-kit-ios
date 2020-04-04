//
//  WTTextMessage.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/4/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTTextMessage : WTBaseCommand

@property (nonatomic, strong, readonly) NSString *body;

@end

NS_ASSUME_NONNULL_END
