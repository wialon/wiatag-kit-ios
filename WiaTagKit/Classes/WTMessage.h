//
//  WTMessage.h
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
#import "WTMessageBuilder.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^builderBlock)(WTMessageBuilder * _Nonnull);
/**
* WTMessage is a class that represents messages to send with WiaTag protocol.
*/
@interface WTMessage : NSObject

/**
* Initializes message with builderBlock. You should setup a WTMessageBuilder inside this block.
*/
- (instancetype)initWithBlock:(builderBlock)block;

@end

NS_ASSUME_NONNULL_END
