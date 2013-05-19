//
//  NSRegularExpression+UnsuckTests.m
//  unsuck
//
//  Created by Alex Chaffee on 5/19/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "SenTestCase+Unsuck.h"
#import "NSRegularExpression+UnsuckTests.h"
#import "NSRegularExpression+Unsuck.h"


@implementation NSRegularExpression_UnsuckTests

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
