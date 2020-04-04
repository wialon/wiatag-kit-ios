//
//  WTBaseCommand.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/17/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTIdentifiable.h"
#import "WTDecodable.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTBaseCommand : NSObject <WTIdentifiable, WTDecodable>

@end

NS_ASSUME_NONNULL_END
