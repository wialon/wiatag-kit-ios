# WiaTagKit

[![Version](https://img.shields.io/cocoapods/v/WiaTagKit.svg?style=flat)](https://cocoapods.org/pods/WiaTagKit)
[![Platform](https://img.shields.io/cocoapods/p/WiaTagKit.svg?style=flat)](https://cocoapods.org/pods/WiaTagKit)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

WiaTagKit is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'WiaTagKit'
```

1. Download the iOS Worldpay library

2. Open xcode, create a project and drag and drop WiaTagKit library folder (**wiatag-kit-ios/WiaTagKit**) into your Xcode project

3. Alternatively, you can rebuild the Worldpay library by running:
```
cd WiaTagKit
pod install --no-integrate
```
If you do this, make sure you drag and drop the WiaTagKit library folder after this (as explained on the previous step).

4. A pop up window will open in xcode. Please select the following options:

- Copy items into destination group's folder (if needed)
- Create groups for any added folders
- Add to targets. Select your project here

5. The WiaTagKit iOS library uses [CocoaAsyncSocket](https://github.com/robbiehanson/CocoaAsyncSocket). Please make sure that you install the framework into your project by installing the podfile (pod install):

```
pod "CocoaAsyncSocket", "~> 7.6"
```

6. **If your app is using Swift**, please make sure that you create a [Bridging Header file](https://developer.apple.com/library/ios/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html) on your app after having completed the previous steps. In order to do so,
just create a file named yourprojectname-Bridging-Header.h with the content:

```
#import "WiaTagSendingLib.h"
```
Once you have done this, please amend "Objective-C Bridging Header" on your Target Build Settings to point to the path of the file you just created.


## Installation using Cocoapods

WiaTagKit is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'WiaTagKit'
```

How To Use the Library
-------------
1. Create  a **WTMessageManager** object with **host**, **port**, **deviceId** and **password**.

```
/** OBJECTIVE-C **/
WTMessageManager *sender = [[WTMessageManager alloc] initWithHost:"your_host" port:your_port deviceId:"your_deviceId" password:"your_optional_password"];

/** SWIFT **/
let sender = WTMessageManager(host: "your_host", port: your_port, deviceId: "your_deviceId", password: "your_optional_password")

```

2. Create a **WTMessage** object and setup it inside builder block:
```
/** OBJECTIVE-C **/
WTMessage *msg = [[WTMessage alloc] initWithBlock:^(WTMessageBuilder * _Nonnull builder) {
    builder.time = yourDate;//If you don't specify time, a current date will be used.
    builder.location = [[WTLocation alloc] initWithLocation:yourCoreLocation];
    builder.isSos = YES;//If you don't need send SOS message, you can just skip this propery setting.
    NSData *imageData = UIImageJPEGRepresentation([UIImage imageNamed:imageName], 1);
    if (imageData) {
        builder.image = [[WTImage alloc] initWithImageData:imageData named:imageNameToSend];
    }
    builder.text = yourText;
    builder.batteryLevel = yourBatteryLevel;
    builder.logFileURL = logFileURL; //(json file with file extension .log)
    builder.configFileURL = configFileURL; //(json file with file extension .cfg)
    //If you specify different values with one param name, just one value will be sent. So avoid doing this. 
    [builder addParam:yourTextParamName withText:yourTextParamValue];
    [builder addParam:yourBinaryParamName withBinaryValue:yourBinaryParamValue];
    [builder addParam:yourIntParamName withIntValue:yourIntParamValue];
    [builder addParam:yourFloatParamName withFloatValue:yourFloatParamValue];
    [builder addParam:yourLongParamName withLongValue:yourLongParamValue];
    [builder addParam:yourDoubleParamName withDoubleValue:yourDoubleParamValue];
}];

/** SWIFT **/
let message = WTMessage { builder in
    builder.time = yourDate//If you don't specify time, a current date will be used.
    builder.location = WTLocation(location: yourCoreLocation)
    builder.isSos = true//If you don't need send SOS message, you can just skip this propery setting.
    if let image = UIImage(named: imageName), let imageData = UIImageJPEGRepresentation(image, 1) {
        builder.image = WTImage(imageData: imageData, named: imageNameToSend)
    }
    builder.text = yourText
    builder.batteryLevel = yourBatteryLevel
    builder.logFileURL = logFileURL //(json file with file extension .log)
    builder.configFileURL = configFileURL //(json file with file extension .cfg)
    //If you specify different values with one param name, just one value will be sent. So avoid doing this.
    builder.addParam(yourTextParamName, withText: yourTextParamValue)
    builder.addParam(yourBinaryParamName, withBinaryValue: yourBinaryParamValue)
    builder.addParam(yourIntParamName, withIntValue: yourIntParamValue)
    builder.addParam(yourFloatParamName, withFloatValue: yourFloatParamValue)
    builder.addParam(yourLongParamName, withLongValue: yourLongParamValue)
    builder.addParam(yourDoubleParamName, withDoubleValue: yourDoubleParamValue)    
}

```
All property/method calls in example above are optional. 

**Note:** you can also create WTLocation in advanced way with **latitude**, **longitude**, **altitude**, **speed**, **bearing** and **satellites**.

```
/** OBJECTIVE-C **/
WTLocation *location = [[WTLocation alloc] initWithLatitude:yourLatitude 
                            longitude:aLongitude 
                            altitude:yourAltitude 
                            speed:yourSpeed 
                            bearing:yourBearing 
                            satellites:yourSatellitesCount];

/** SWIFT **/
let location = WTLocation(latitude: yourLatitude, 
                            longitude: yourLongitude, 
                            altitude: yourAltitude, 
                            speed: yourSpeed, 
                            bearing: yourBearing, 
                            satellites: yourSatellitesCount)

```

3. Call a method to send your single message (**WTMessage**) or array of messages (**array of WTMessage**):
```
/** OBJECTIVE-C **/
//send single message
[sender sendMessage:yourMessage completion:^(NSError * _Nullable error) {
    //Error if nil if message sended with success.
    //Otherwise, you can send your message here.
}];
//send array of messages ([WTMessage])
[self.sender sendMessages:yourArrayOfMessages completion:^(NSError * _Nullable error) {
    //Error if nil if message sended with success.
    //Otherwise, you can send your message here.
}];

/** SWIFT **/
//send single message
sender.send(yourMessage) { error in
    //Error if nil if message sended with success.
    //Otherwise, you can send your message here.
}
//send array of messages ([WTMessage])
sender.send(yourArrayOfMessages) { error in
    //Error if nil if message sended with success.
    //Otherwise, you can send your message here.
}

```

4. If you want to receive messages from the platform you need to call this method:
```
/** OBJECTIVE-C **/
    [sender enableAllServicesWithCompletion:^(NSError * _Nullable error) {
        //handle error if it is necesary
    }];
    
/** SWIFT **/
    sender.enableAllServices { error in
        //handle error if it is necesary
    }
```
Than you should implement any kind of listeners for your purposes:
```
/** OBJECTIVE-C **/
    [sender addListenerWithCompletion:^(id<WTIdentifiable> _Nullable command) {
        //handle command
    }];

/** SWIFT **/
    sender.addListener { command in
        //handle command
    }
```
Finally you should check new commands from the platform manually or as feedback when you send any command:
```
/** OBJECTIVE-C **/
[sender checkUpdates];

/** SWIFT **/
sender.checkUpdates()
```

5. If you want to receive config from the configurator you need to call this method(if command was complited successfully you don't receive any kind of errors):
```
/** OBJECTIVE-C **/
    [sender requestConfig:^(NSError * _Nullable error) {
        //handle error if it is necesary
    }];
    
/** SWIFT **/
    sender.requestConfig { error in
        //handle error if it is necesary
    }
```
6. If you want to use push notifications you need to register for it:
```
/** OBJECTIVE-C **/
    [sender registerForRemoteNotificationsWithServiceName:[[NSBundle mainBundle] bundleIdentifier]
                                                apnsToken:apnsToken
                                                 fcmToken:fcmToken
                                               completion:nil];
/** SWIFT **/
        sender.registerForRemoteNotifications(withServiceName: serviceName,
                                              apnsTokenStringRepresentation: apnsToken,
                                              fcmTokenStringRepresentation: fcmToken,
                                              completion: nil)
```

And if you want to receive commands from listener you should handle notification payload in didReceiveRemoteNotification:
```
/** OBJECTIVE-C **/
    [sender handleRemoteNotificationWithDict:testPushUserInfo
                                  completion:completionHandler];
/** SWIFT **/
    sender.handleRemoteNotification(withDict: info,
                                    completion: completion)
```

7. If you use both channels(push notifications and tcp) for receiving messages from the platform you should create and set up duplication checker class into sender. For more detail see WTBaseCommandDuplicationValidator class.

## Author

Gurtam, development@gurtam.com

## License

WiaTagKit is available under the CC BY-ND 4.0 license. See the LICENSE file for more info.
