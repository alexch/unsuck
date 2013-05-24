//
//  SenTestCase+Unsuck.m
//  unsuck
//
//  Created by Alex Chaffee on 5/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "SenTestCase+Unsuck.h"

@implementation SenTestCase (Unsuck)

// I made my own assertArray:equals:because STAssertEquals gives a stupid error when the arrays are different sizes
-(void)assertArray:(NSArray *)a equals:(NSArray *)b because: (NSString *)reason
{
    STAssertEquals([a count], [b count], reason);
    STAssertEqualObjects(a, b, reason);
}

-(void)assertSet:(NSSet *)a equals:(NSSet *)b because: (NSString *)reason
{
    STAssertEquals([a count], [b count], reason);
    STAssertEqualObjects(a, b, reason);
}

// I made my own assertDate:closeTo:because:
-(void)assertDate:(NSDate *)a closeTo:(NSDate *)b because: (NSString *)reason
{
    NSTimeInterval interval = [a timeIntervalSinceDate:b];
    STAssertTrue(ABS(interval) < 1.0, reason);
}

-(void)sleep: (float)seconds
{
    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:seconds]];
}

// waits until the block returns true(ish) (non-zero), checking every .1 sec
-(void)waitUntil: (BOOL (^)(void))block because:(NSString *)reason
{
    NSDate *timeout = [NSDate dateWithTimeIntervalSinceNow:5];
    int result;
    while (!(result = block()) && ([[NSDate date] compare:(NSNumber*)timeout] == NSOrderedAscending)) {
        NSLog(@"result = %d", result);
        [self sleep: 0.10];
    }
    STAssertTrue(result, [@"timed out - " stringByAppendingString:reason]);
}

@end
