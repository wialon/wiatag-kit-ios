//
//  WTRequestLogFile.h
//  WiaTagSending
//
//  Created by Aliaksei Verameichyk on 10/5/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTRequestLogFile : WTBaseCommand

@property (nonatomic, strong, readonly) NSNumber *from;
@property (nonatomic, strong, readonly) NSNumber *to;

@end

NS_ASSUME_NONNULL_END
