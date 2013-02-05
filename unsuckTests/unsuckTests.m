//
//  unsuckTests.m
//  unsuckTests
//
//  Created by Alex Chaffee on 2/5/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "unsuckTests.h"
#import "NSRegularExpression+Unsuck.h"

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
        [NSThread sleepForTimeInterval:1.0];
        loaded = TRUE;
    }
    [super tearDown];
}

-(void)testIsEqual
{
    NSRegularExpression *foo = [NSRegularExpression from: @"foo"];
    STAssertTrue([foo isEqual: foo], @"object should be equal to itself");
    
    STAssertTrue([[NSRegularExpression from: @"foo"] isEqual: [NSRegularExpression from: @"foo"]], @"same pattern should be equal");
    STAssertFalse([[NSRegularExpression from: @"foo"] isEqual: [NSRegularExpression from: @"bar"]], @"different pattern should not be equal");
    
}

- (void)testSuccessfulCreation
{
    // sucky way
    NSError *error;
    NSRegularExpression *expected = [NSRegularExpression regularExpressionWithPattern:@"foo"
                                                     options:0
                                                       error:&error];

    // unsucky way
    NSRegularExpression *regex = [NSRegularExpression from:@"foo"];
    
    STAssertEqualObjects(expected, regex, @"simple creation");
}

- (void)testUnsuccessfulCreation
{
    NSRegularExpression *regex = [NSRegularExpression from:@"\\"];
    STAssertNil(regex, @"an invalid regex pattern returns nil");
}

- (void)testMatches
{
    NSRegularExpression *number = [NSRegularExpression from: @"(\\d*\\.\\d*)"];
    NSArray *matches = [number matches:@"3.14"];
    NSArray *expected = [NSArray arrayWithObjects:@"3.14",nil];

    STAssertEquals([expected count], [matches count], @"arrays should be same size");
    STAssertEqualObjects(expected, matches, @"one match");
    
}

@end
