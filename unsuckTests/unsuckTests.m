//
//  unsuckTests.m
//  unsuckTests
//
//  Created by Alex Chaffee on 2/5/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "unsuckTests.h"
#import "SenTestCase+Unsuck.h"

@implementation unsuckTests

- (void)setUp
{
    [super setUp];
}

- (void)tearDown
{
    // http://stackoverflow.com/questions/12308297/some-of-my-unit-tests-tests-are-not-finishing-in-xcode-4-4
    static int loaded = FALSE;
    if (!loaded) {
        [NSThread sleepForTimeInterval:2.0];
        loaded = TRUE;
    }
    [super tearDown];
}


@end
