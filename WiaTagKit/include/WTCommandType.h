//
//  WTCommandType.m
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/5/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, WTCommandType) {
    WTCommandTypeText = 1,
    WTCommandTypeCoordinates,
    WTCommandTypeSendRoute,
    WTCommandTypeStartServiceV1,
    WTCommandTypeStopServiceV1,
    WTCommandTypeRequestLocation,
    WTCommandTypeRequestPhoto,
    WTCommandTypeSendAppSettings,
    WTCommandTypeRequestPhotoFromCertainCamera,
    WTCommandTypeStartServiceV2,
    WTCommandTypeStopServiceV2,
    WTCommandTypeTorchOn,
    WTCommandTypeTorchOff,
    WTCommandTypeRequestConfig
};
