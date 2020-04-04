//
//  WTDecodable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/4/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol WTDecodable <NSObject>

- (instancetype)initWithDict:(NSDictionary<NSString *, id> *)dict;

@end

NS_ASSUME_NONNULL_END
