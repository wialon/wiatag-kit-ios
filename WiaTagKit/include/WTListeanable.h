//
//  WTListeanable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/10/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTIdentifiable.h"

@class WTLocationCoordinate;
@class WTTextMessage;
@class WTTorch;
@class WTService;
@class WTRequestConfig;
@class WTConfig;
@class WTRequestLocation;

typedef void (^WTTextMessageHandler)(WTTextMessage *_Nullable);
typedef void (^WTLocationCoordinateHandler)(WTLocationCoordinate * _Nullable);
typedef void (^WTTorchHandler)(WTTorch * _Nullable);
typedef void (^WTServiceHandler)(WTService * _Nullable);
typedef void (^WTRequestConfigHandler)(WTRequestConfig * _Nullable);
typedef void (^WTConfigHandler)(WTConfig * _Nullable);
typedef void (^WTRequestLocationHandler)(WTRequestLocation * _Nullable);
typedef void (^WTAllCommandsHandler)(id<WTIdentifiable> _Nullable);

NS_ASSUME_NONNULL_BEGIN

@protocol WTListenable <NSObject>

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 @param locationCoordinateHandler is a location coordinate message handler block.
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler
locationCoordinateHandler:(nullable WTLocationCoordinateHandler)locationCoordinateHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 @param locationCoordinateHandler is a location coordinate message handler block.
 @param torchHandler is a torch message handler block.
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler
locationCoordinateHandler:(nullable WTLocationCoordinateHandler)locationCoordinateHandler
       torchHandler:(nullable WTTorchHandler)torchHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 @param locationCoordinateHandler is a location coordinate message handler block.
 @param torchHandler is a torch message handler block.
 @param serviceHandler is a service message handler block
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler
locationCoordinateHandler:(nullable WTLocationCoordinateHandler)locationCoordinateHandler
       torchHandler:(nullable WTTorchHandler)torchHandler
     serviceHandler:(nullable WTServiceHandler)serviceHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 @param locationCoordinateHandler is a location coordinate message handler block.
 @param torchHandler is a torch message handler block.
 @param serviceHandler is a service message handler block.
 @param requestConfigHandler is a request configuration handler block.
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler
locationCoordinateHandler:(nullable WTLocationCoordinateHandler)locationCoordinateHandler
       torchHandler:(nullable WTTorchHandler)torchHandler
     serviceHandler:(nullable WTServiceHandler)serviceHandler
requestConfigHandler:(nullable WTRequestConfigHandler)requestConfigHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 @param locationCoordinateHandler is a location coordinate message handler block.
 @param torchHandler is a torch message handler block.
 @param serviceHandler is a service message handler block.
 @param requestConfigHandler is a request configuration handler block.
 @param configHandler is a configuration handler block.
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler
locationCoordinateHandler:(nullable WTLocationCoordinateHandler)locationCoordinateHandler
       torchHandler:(nullable WTTorchHandler)torchHandler
     serviceHandler:(nullable WTServiceHandler)serviceHandler
requestConfigHandler:(nullable WTRequestConfigHandler)requestConfigHandler
      configHandler:(nullable WTConfigHandler)configHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param textMessageHandler is a text message handler block.
 @param locationCoordinateHandler is a location coordinate message handler block.
 @param torchHandler is a torch message handler block.
 @param serviceHandler is a service message handler block.
 @param requestConfigHandler is a request configuration handler block.
 @param configHandler is a configuration handler block.
 @param requestLocationHandler is a request location handler block.
 */
- (void)addListener:(nullable WTTextMessageHandler)textMessageHandler
locationCoordinateHandler:(nullable WTLocationCoordinateHandler)locationCoordinateHandler
       torchHandler:(nullable WTTorchHandler)torchHandler
     serviceHandler:(nullable WTServiceHandler)serviceHandler
requestConfigHandler:(nullable WTRequestConfigHandler)requestConfigHandler
      configHandler:(nullable WTConfigHandler)configHandler
requestLocationHandler:(nullable WTRequestLocationHandler)requestLocationHandler;

/**
 * Use this method to add listener for handle messages. Note: listener should be only one.
 @param handler is a all messages handler block.
 */
- (void)addListenerWithCompletion:(nullable WTAllCommandsHandler)handler;

/**
 * Use this method to remove listener.
 */
- (void)removeListener;

@end

NS_ASSUME_NONNULL_END
