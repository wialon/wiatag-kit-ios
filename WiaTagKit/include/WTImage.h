//
//  WTImage.h
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

NS_ASSUME_NONNULL_BEGIN

/**
* WTImage is a class that stores image data for WTMessage.
*/
@interface WTImage : NSObject

@property (nonatomic, strong) NSData *imageData;
@property (nonatomic, strong) NSString *name;

- (instancetype)initWithImageData:(NSData *)imageData named:(nullable NSString *)name;

@end

NS_ASSUME_NONNULL_END
