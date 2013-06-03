//
//  CGCanvas+Extras.m
//  DrawingToy
//
//  Created by Alex Chaffee on 4/9/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//

#import "CGCanvas+Extras.h"

@implementation CGCanvas (Extras)

#pragma mark lines

-(void)drawLineFromPoint:(CGPoint)fromPoint toPoint:(CGPoint)toPoint
{
    [self moveToPoint_x:fromPoint.x y:fromPoint.y];
    [self addLineToPoint_x:toPoint.x y:toPoint.y];
    [self drawPath: kCGPathFillStroke];
}

#pragma mark rects

-(id)fillRect:(CGRect)rect withColor:(UIColor*)color
{
    [self setFillColorWithColor: color.CGColor];
    [self fillRect: rect];
    return self;
}

-(id)strokeRect:(CGRect)rect withColor:(UIColor*)color;
{
    [self setStrokeColorWithColor: color.CGColor];
    [self strokeRect: rect];
    return self;
}

-(id)strokeRect:(CGRect)rect withColor:(UIColor*)color andLineWidth:(CGFloat)lineWidth;
{
    [self setStrokeColorWithColor: color.CGColor];
    [self setLineWidth:lineWidth];
    [self strokeRect: rect];
    return self;
}

#pragma mark ellipses

-(id)fillEllipse:(CGRect)rect withColor:(UIColor*)color
{
    [self setFillColorWithColor: color.CGColor];
    [self fillEllipseInRect: rect];
    return self;
}

-(id)strokeEllipse:(CGRect)rect withColor:(UIColor*)color;
{
    [self setStrokeColorWithColor: color.CGColor];
    [self strokeEllipseInRect: rect];
    return self;
}

-(id)strokeEllipse:(CGRect)rect withColor:(UIColor*)color andLineWidth:(CGFloat)lineWidth;
{
    [self setStrokeColorWithColor: color.CGColor];
    [self setLineWidth:lineWidth];
    [self strokeEllipseInRect: rect];
    return self;
}

#pragma mark paths

-(void)fillPath:(UIBezierPath*)path
{
    // Silly UIBezierPath doesn't know how to stroke in a non-current context, so we have to push & pop it.
    UIGraphicsPushContext(self.context);
    [path fill];
    UIGraphicsPopContext();
}

-(void)fillPath:(UIBezierPath*)path withColor:(UIColor*)color;
{
    [self saveGState];
    {
        [self setFillColorWithColor:color.CGColor];
        [self fillPath:path];
    }
    [self restoreGState];
}

-(void)strokePath:(UIBezierPath*)path withColor:(UIColor*)color andLineWidth:(CGFloat)lineWidth
{
    // Silly UIBezierPath persists its lineWidth, so we have to remember and restore it.
    [self saveGState];
    {
        [self setStrokeColorWithColor:color.CGColor];
        CGFloat originalLineWidth = path.lineWidth;
        path.lineWidth = lineWidth;
        [self strokePath:path];
        path.lineWidth = originalLineWidth;
    }
    [self restoreGState];
}

-(void)strokePath:(UIBezierPath*)path
{
    UIGraphicsPushContext(self.context);
    [path stroke];
    UIGraphicsPopContext();
}

#pragma mark text

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
