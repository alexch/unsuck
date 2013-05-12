//
//  CGCanvas+Extras.h
//  DrawingToy
//
//  Created by Alex Chaffee on 4/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "CGCanvas.h"

@interface CGCanvas (Extras)

-(void)drawLineFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint;
-(void)fillPath:(UIBezierPath*)path;
-(void)strokePath:(UIBezierPath*)path;
-(float) textWidth:(NSString *)text;


@end
