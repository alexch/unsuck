//
//  NSArray+Unsuck.h
//  Thumper
//
//  Created by Alex Chaffee on 5/19/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Unsuck)

// return a new array consisting of the elements of this array that are not in the other array
- (NSArray*)minus:(NSArray *)other;

@end
