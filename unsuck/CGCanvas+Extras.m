//
//  CGCanvas+Extras.m
//  DrawingToy
//
//  Created by Alex Chaffee on 4/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "CGCanvas+Extras.h"

@implementation CGCanvas (Extras)

-(void)drawLineFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint
{
    [self moveToPoint_x:fromPoint.x y:fromPoint.y];
    [self addLineToPoint_x:toPoint.x y:toPoint.y];
    [self drawPath: kCGPathFillStroke];
}

-(void)fillPath:(UIBezierPath*)path
{
    UIGraphicsPushContext(self.context);
    [path fill];
    UIGraphicsPopContext();
}

-(void)strokePath:(UIBezierPath*)path
{
    UIGraphicsPushContext(self.context);
    [path stroke];
    UIGraphicsPopContext();
}

// todo: remember current font and encoding
// maybe use UIFont

-(float) textWidth:(NSString *)text
{
    CGPoint startPosition, endPosition;

    startPosition = [self getTextPosition];
    [self setTextDrawingMode:kCGTextInvisible];
    [self showText_string:[text cStringUsingEncoding:NSUTF8StringEncoding] length:[text length]];
    endPosition = [self getTextPosition];
    [self setTextDrawingMode:kCGTextFill];

    return endPosition.x - startPosition.x;
}

@end
