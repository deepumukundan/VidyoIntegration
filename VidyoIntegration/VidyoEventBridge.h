//
//  Project - VidyoIntegration from Kony
//
//  Created by Deepu Mukundan on 09/04/14.
//  Copyright (c) 2014 Deepu Mukundan. All rights reserved.
//

#ifndef VIDYOEVENTBRIDGE_H
#define VIDYOEVENTBRIDGE_H

#include "VidyoClient.h"

// Receive out event from VidyoClient
void vidyoClientWrapperOnVidyoClientEvent(VidyoClientOutEvent actionType,
                                          VidyoVoidPtr        param,
                                          VidyoUint           paramSize,
                                          VidyoVoidPtr        data);

// Multi Logging Adaptor
void logMsg(NSString *msg);

#endif // VIDYOEVENTBRIDGE_H
