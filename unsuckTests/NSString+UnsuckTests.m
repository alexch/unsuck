//
//  NSString+UnsuckTests.m
//  unsuck
//
//  Created by Alex Chaffee on 5/19/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "SenTestCase+Unsuck.h"
#import "NSString+UnsuckTests.h"
#import "NSString+Unsuck.h"

@implementation NSString_UnsuckTests

-(void)testTrim
{
    STAssertEqualObjects(@"foo", [@"  foo  " trim], @"trims spaces from both ends");
    STAssertEqualObjects(@"foo  bar", [@"  foo  bar  " trim], @"skips inner spaces");
    STAssertEqualObjects(@"foo", [@"\tfoo\n" trim], @"trims newlines and tabs too");
}

-(void)testLines
{
    NSString *s = @"my\ndog\nhas\nfleas";
    NSArray *a = @[@"my", @"dog", @"has", @"fleas"];
    [self assertArray:a equals:[s lines] because:@"splits a string into lines"];

    s = @"my\ndog\nhas\nfleas\n";
    a = @[@"my", @"dog", @"has", @"fleas", @""];
    [self assertArray:a equals:[s lines] because:@"includes an empty last line"]; // though maybe it shouldn't
}

-(void)testSplit
{
    [self assertArray:@[@"my", @"dog", @"", @"has", @"fleas"]  // Adjacent occurrences of the separator characters produce empty strings in the result.
               equals:[@"my dog\n has\tfleas" split]
              because:@"split with no args splits on whitespace including newline"];

    [self assertArray:@[@"my", @"dog", @"", @"has", @"fleas"]
               equals:[@"my,dog,,has;fleas" split: @",;"]
              because:@"split with a string arg splits on any chars in that string"];


}
@end
