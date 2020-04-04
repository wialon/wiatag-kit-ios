//
//  WTIdentifiable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/5/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WTIdentifiable <NSObject>

@property (nonatomic, strong, readonly) NSString *identifier;
@property (nonatomic, assign, readonly) NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END
