//
//  WTLocationCoordinate.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/4/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTBaseCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface WTLocationCoordinate : WTBaseCommand

@property (nonatomic, assign, readonly) double latitude;
@property (nonatomic, assign, readonly) double longitude;
@property (nonatomic, strong, readonly) NSString* title;
@property (nonatomic, strong, readonly) NSString* message;

@end

NS_ASSUME_NONNULL_END
