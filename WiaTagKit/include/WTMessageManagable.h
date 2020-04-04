//
//  WTMessageManagable.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/11/20.
//  Copyright © 2020 gria. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WTListeanable.h"
#import "WTRemotable.h"
#import "WTSendable.h"
#import "WTConfigurable.h"

NS_ASSUME_NONNULL_BEGIN

@protocol WTMessageManagable <WTListenable, WTRemotable, WTSendable, WTConfigurable>

@end

NS_ASSUME_NONNULL_END
