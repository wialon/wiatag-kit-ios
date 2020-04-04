//
//  WTLocation.h
//  SendWiaTagData
//
/*
 WiaTagKit (c) by Gurtam
 
 WiaTagKit is licensed under a
 Creative Commons Attribution-NoDerivatives 4.0 International License.
 
 You should have received a copy of the license along with this
 work. If not, see <http://creativecommons.org/licenses/by-nd/4.0/>.
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * WTLocation is a class that stores location data for WTMessage.
 */
@interface WTLocation : NSObject

@property (nonatomic, assign) double latitude;
@property (nonatomic, assign) double longitude;
@property (nonatomic, assign) double altitude;
@property (nonatomic, assign) UInt16 speed;
@property (nonatomic, assign) UInt16 bearing;
@property (nonatomic, assign) UInt8 satellites;

- (instancetype)initWithLatitude:(double)latitude
                       longitude:(double)longitude
                        altitude:(double)altitude
                           speed:(UInt16)speed
                         bearing:(UInt16)bearing
                      satellites:(UInt8)satellites;

@end

NS_ASSUME_NONNULL_END
