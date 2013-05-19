//
//  NSArray+UnsuckTests.m
//  unsuck
//
//  Created by Alex Chaffee on 5/19/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "NSArray+UnsuckTests.h"
#import "NSArray+Unsuck.h"

@implementation NSArray_UnsuckTests

-(void)testMinus
{
    NSArray * abc = @[@"a", @"b", @"c"];
    NSArray * bcd = @[@"b", @"c", @"d"];

    NSLog(@"responds: %i", [abc respondsToSelector:@selector(minus:)]);

    NSArray * after = [abc minus:bcd];
    STAssertEqualObjects(after, @[@"a"], @"minus makes an array with all elements in self that are not in other");
}

@end
