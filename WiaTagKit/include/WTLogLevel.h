//
//  WTLogLevel.m
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/13/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WTLogLevel) {
    WTLogLevelOff,
    WTLogLevelInfo,
    WTLogLevelVerbose
};

typedef NS_ENUM(NSUInteger, WTLogType) {
    WTLogTypeError,
    WTLogTypeWarning,
    WTLogTypeInfo
};
