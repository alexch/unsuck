//
//  SenTestCase+Unsuck.h
//  unsuck
//
//  Created by Alex Chaffee on 5/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import <SenTestingKit/SenTestCase.h>

@interface SenTestCase (Unsuck)

-(void)assertDate:(NSDate *)a closeTo:(NSDate *)b because: (NSString *)reason;
-(void)assertNumber:(double)a closeTo:(double)b by:(double)maxDelta because: (NSString *)reason;

// todo: move this out to a more general category (not just for tests)
-(void)sleep: (float)seconds;

// waits until the block returns true(ish) (non-zero), checking every .1 sec
-(void)waitUntil: (BOOL (^)(void))block because:(NSString *)reason;

// I made my own assertArray:equals:because STAssertEquals gives a stupid error when the arrays are different sizes
-(void)assertArray:(NSArray *)a equals:(NSArray *)b because: (NSString *)reason;
-(void)assertSet:(NSSet *)a equals:(NSSet *)b because: (NSString *)reason;

@end
