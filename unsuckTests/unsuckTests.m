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
        [NSThread sleepForTimeInterval:2.0];
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

// I made my own assertArray:equals:because STAssertEquals gives a stupid error when the arrays are different sizes
-(void)assertArray:(NSArray *)a equals:(NSArray *)b because: (NSString *)reason
{
    STAssertEquals([a count], [b count], reason);
    STAssertEqualObjects(a, b, reason);
}

- (void)testAllMatches_NoMatch
{
    NSRegularExpression *number = [NSRegularExpression from: @"(\\d*\\.\\d*)"];
    NSArray *matches = [number allMatches:@"foo"];
    NSArray *expected = [NSArray arrayWithObjects:nil];

    [self assertArray: expected equals: matches because: @"no match"];
}

- (void)testAllMatches_OneMatch
{
    NSRegularExpression *number = [NSRegularExpression from: @"(\\d*\\.\\d*)"];
    NSArray *matches = [number allMatches:@"3.14"];
    NSArray *expected = [NSArray arrayWithObjects:@"3.14",nil];

    [self assertArray: expected equals: matches because: @"one match"];
}

- (void)testAllMatches_SeveralMatches
{
    NSRegularExpression *number = [NSRegularExpression from: @"(\\d*\\.\\d*)"];
    NSArray *matches = [number allMatches:@"3.14 1.23 45.67"];
    NSArray *expected = [NSArray arrayWithObjects:@"3.14",@"1.23",@"45.67",nil];

    [self assertArray: expected equals: matches because: @"several matches"];
}

-(void)testAllMatches_CaseSensitive
{
    NSRegularExpression *re = [NSRegularExpression from:@"foo"];
    NSArray *matches = [re allMatches:@"foo Foo"];
    [self assertArray:matches equals:[NSArray arrayWithObjects:@"foo",nil] because:@"case sensitive"];

}

-(void)testAllMatches_CaseInsensitive
{
    NSRegularExpression *re = [NSRegularExpression from:@"(?i)foo"];
    NSArray *matches = [re allMatches:@"foo Foo"];
    [self assertArray:matches equals:[NSArray arrayWithObjects:@"foo",@"Foo",nil] because:@"case insensitive"];

}

@end
