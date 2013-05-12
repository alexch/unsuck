//
//  Randy.m
//  DrawingToy
//
//  Created by Alex Chaffee on 4/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "Randy.h"

// todo: unit test

#define ARC4RANDOM_MAX      0x100000000

@implementation Randy

// returns random double between 0 <= n < 1.0
+(double)unit
{
    return (double)arc4random() / ARC4RANDOM_MAX;
}

// returns random integer (unsigned long) between 0 < n < max
+(unsigned long)int: (unsigned long)max
{
    return arc4random() % max;  // note: this is a *teensy* bit weighted towards lower numbers; could use floorf([self unit]*max instead
}

// returns random double between 0 < n < max
+(double)double:(double)max
{
    return [self unit] * max;
}

@end
