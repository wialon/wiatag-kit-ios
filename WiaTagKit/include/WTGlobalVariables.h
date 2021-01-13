//
//  WTGlobalVariables.h
//  SendWiaTagData
//
//  Created by Aliaksei Verameichyk on 3/10/20.
//  Copyright © 2020 gria. All rights reserved.
//

#ifndef WTGlobalVariables_h
#define WTGlobalVariables_h

@class WTMessage;

#define BLOCK_EXEC(block, ...)  if (block) { block(__VA_ARGS__); };
#define BLOCK_EXEC_WITH_RETURN(block, returnValue, ...)  if (block) { returnValue = block(__VA_ARGS__); };

typedef void (^baseCompletion)(NSError * _Nullable);
typedef void (^sendMessagesCompletion)(NSError * _Nullable,
                                       NSArray<WTMessage *> *_Nullable);

#endif /* WTGlobalVariables_h */
