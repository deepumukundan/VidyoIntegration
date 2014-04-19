//
//  NSString+Base64.h
//  VidyoClientSample_iOS
//
//  Created by Mark Rubenchik on 7/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

@interface NSString (Base64)

+ (NSString *) base64FromData:(NSData *)data;
+ (NSString *) base64FromString:(NSString *)stringData;
- (NSString *) base64;

@end
