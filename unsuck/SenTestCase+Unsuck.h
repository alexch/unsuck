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

// todo: move this out to a more general category (not just for tests)
-(void)sleep: (float)seconds;

// waits until the block returns true(ish) (non-zero), checking every .1 sec
-(void)waitUntil: (BOOL (^)(void))block because:(NSString *)reason;

@end