//
//  WTLocation+CoreLocation.h
//  SendWiaTagData
//
/*
 WiaTagKit (c) by Gurtam
 
 WiaTagKit is licensed under a
 Creative Commons Attribution-NoDerivatives 4.0 International License.
 
 You should have received a copy of the license along with this
 work. If not, see <http://creativecommons.org/licenses/by-nd/4.0/>.
 */

#import "WTLocation.h"
#import <CoreLocation/CoreLocation.h>

/**
* Initializer that allows init WTLocation with CLLocation object in a simple way.
*/
@interface WTLocation (CoreLocation)

- (instancetype)initWithLocation:(CLLocation *)location;

@end
