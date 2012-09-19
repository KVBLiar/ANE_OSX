//
//  ANE_OSX.h
//  ANE_OSX
//
//  Created by Jeff Larcomb on 9/17/12.
//  Copyright (c) 2012 Jeff Larcomb. All rights reserved.
//

#import <Foundation/Foundation.h>

#include <Adobe AIR.h>

@interface ANE_OSX : NSObject

__declspec(dllexport) void initializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer);
__declspec(dllexport) void finalizer(void* extData);

@end


