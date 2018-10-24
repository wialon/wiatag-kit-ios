//
//  WTSenderErrors.h
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

extern NSString *const WTSenderErrorDomain;

typedef NS_ENUM(NSInteger, WTSenderErrorCode) {
    WTSenderErrorCodeSuccess = 0,
    WTSenderErrorCodeNoUnit,
    WTSenderErrorCodeInvalidPassword,
    WTSenderErrorCodeNoSession,
    WTSenderErrorCodeInvalidPacket,
    WTSenderErrorCodeDisconnected,
    WTSenderErrorCodeCantConnect,
    WTSenderErrorCodeUnrecognizedResponse,
    WTSenderErrorCodeWrongCountOfDeliveredMessages,
    WTSenderErrorCodeBigMessage,
    WTSenderErrorCodeUnknown
};
