//
//  Randy.h
//  DrawingToy
//
//  Created by Alex Chaffee on 4/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Randy : NSObject

// returns random double between 0 <= n < 1.0
+(double)unit;

// returns random integer (unsigned long) between 0 < n < max
+(unsigned long)int: (unsigned long)max;

// returns random double between 0 < n < max
+(double)double: (double)max;


@end
