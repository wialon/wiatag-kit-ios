//
//  CLLocation+Satellites.h
//  SendWiaTagData
//
/*
 WiaTagKit (c) by Gurtam
 
 WiaTagKit is licensed under a
 Creative Commons Attribution-NoDerivatives 4.0 International License.
 
 You should have received a copy of the license along with this
 work. If not, see <http://creativecommons.org/licenses/by-nd/4.0/>.
 */

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CLLocation (Satellites)

- (UInt8)wt_approximateCountOfSatellites;

@end

NS_ASSUME_NONNULL_END
