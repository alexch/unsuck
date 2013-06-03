//
//  NSArray+Unsuck.m
//  Thumper
//
//  Created by Alex Chaffee on 5/19/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "NSArray+Unsuck.h"

@implementation NSArray (Unsuck)

// return a new array consisting of the elements of both arrays (no duplicates)
- (NSArray*)plus:(NSArray *)other;
{
    NSMutableArray *array = [self mutableCopy];
    for (id thing in other) {
        if (![self containsObject: thing]) {
            [array addObject:thing];
        }
    }
    return array;
}

// return a new array consisting of the elements of this array that are not in the other array
- (NSArray*)minus:(NSArray *)other;
{
    NSMutableArray *array = [NSMutableArray array];
    for (id thing in self) {
        if (![other containsObject: thing]) {
            [array addObject:thing];
        }
    }
    return array;
}
@end
