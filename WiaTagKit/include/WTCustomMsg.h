//
//  WTCustomMsg.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 10/7/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTCustomMsg : WTBaseCommand

@property (nonatomic, copy) NSString *content;

@end

NS_ASSUME_NONNULL_END
