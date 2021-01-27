//
//  WTDuplicatable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/11/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTIdentifiable.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WTDuplicatable <NSObject>

- (void)checkDuplicationWithCommand:(id<WTIdentifiable>)command
                         completion:(void(^)(BOOL))completion;

@end

NS_ASSUME_NONNULL_END
