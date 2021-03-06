//
//  NSRegularExpression+Unsuck.h
//  unsuck
//
//  Created by Alex Chaffee on 2/5/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSRegularExpression (Unsuck)

+ (NSRegularExpression *) from: (NSString *)pattern;
/** Creates a regular expression by calling [NSRegularExpression regularExpressionWithPattern:options:error]. Note that you can use (?ismwx-ismwx) to specify options inside the pattern string, e.g. @"(?i)foo" is case-insensitive.
 @returns regular expression, or nil if error
*/

- (NSArray *) allMatches: (NSString *)target;
/// @description returns an array containing all the substrings in target that match this regular expression

@end

@interface Foo : NSObject
- (NSArray *) allMatches: (NSString *)target;
/// @description returns an array containing all the substrings in target that match this regular expression

@end
