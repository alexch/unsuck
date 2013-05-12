//
//  NSString+Unsuck.m
//  DrawingToy
//
//  Created by Alex Chaffee on 4/14/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "NSString+Unsuck.h"

@implementation NSString (Unsuck)

// boo to Apple for redefining whitespace to not include newlines (they should have made a new inlineWhitespaceCharacterSet instead)
-(NSString*)trim
{
    return [self
     stringByTrimmingCharactersInSet:
     [NSCharacterSet whitespaceAndNewlineCharacterSet]];
}
@end
