//
//  NSRegularExpression+Unsuck.m
//  unsuck
//
//  Created by Alex Chaffee on 2/5/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "NSRegularExpression+Unsuck.h"

// see http://it.toolbox.com/blogs/macsploitation/extending-classes-in-objectivec-with-categories-27447

@implementation NSRegularExpression (Unsuck)


+ (NSRegularExpression *) from: (NSString *)pattern
{
    NSError *error;
    NSRegularExpression *regex =
    [NSRegularExpression regularExpressionWithPattern:pattern
                                              options:0
                                                error:&error];
    if (regex == nil) {
        NSLog(@"%@", error);
    }
    return regex;
}


- (NSArray *) matches: (NSString *)target
{
    NSArray *matchingResults = [self matchesInString:target
                                      options:0
                                        range:NSMakeRange(0, [target length])];

    NSMutableArray *substrings = [[NSMutableArray alloc] initWithCapacity: [matchingResults count]];
    for (NSTextCheckingResult * match in matchingResults) {
        [substrings addObject: [target substringWithRange:[match range]]];
    }
    
    return substrings;
}

@end
