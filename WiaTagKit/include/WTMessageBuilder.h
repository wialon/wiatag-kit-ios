//
//  WTMessageBuilder.h
//  SendWiaTagData
//
/*
 WiaTagKit (c) by Gurtam
 
 WiaTagKit is licensed under a
 Creative Commons Attribution-NoDerivatives 4.0 International License.
 
 You should have received a copy of the license along with this
 work. If not, see <http://creativecommons.org/licenses/by-nd/4.0/>.
 */

@import Foundation;
#import "WTLocation.h"
#import "WTLocation+CoreLocation.h"
#import "WTImage.h"

NS_ASSUME_NONNULL_BEGIN

/**
* WTMessageBuilder is a class to setup WTMessage that will be created.
* Don't init it yourself.
* Use WTLocation to pass CLLocation data and WTImage to pass data of image
*/
@interface WTMessageBuilder : NSObject

@property (nonatomic, strong, nullable) NSDate *time;
@property (nonatomic, strong, nullable) WTLocation *location;
@property (nonatomic, assign) BOOL isSos;
@property (nonatomic, strong, nullable) WTImage *image;
@property (nonatomic, strong, nullable) NSString *text;
@property (nonatomic, strong, nullable) NSNumber *batteryLevel;
@property (nonatomic, copy, nullable) NSURL *logFileURL;
@property (nonatomic, copy, nullable) NSURL *configFileURL;

- (void)addParam:(NSString *)key
        withText:(NSString *)text;
- (void)addParam:(NSString *)key
 withBinaryValue:(NSData *)value;
- (void)addParam:(NSString *)key
    withIntValue:(NSNumber *)value;
- (void)addParam:(NSString *)key
  withFloatValue:(NSNumber *)value;
- (void)addParam:(NSString *)key
   withLongValue:(NSNumber *)value;
- (void)addParam:(NSString *)key
 withDoubleValue:(NSNumber *)value;

@end

NS_ASSUME_NONNULL_END
