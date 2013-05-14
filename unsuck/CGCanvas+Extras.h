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

-(id)fillRect:(CGRect)rect withColor:(UIColor*)color;

-(void)fillPath:(UIBezierPath*)path;
-(void)strokePath:(UIBezierPath*)path;
-(void)strokePath:(UIBezierPath*)path withColor:(UIColor*)color andLineWidth:(CGFloat)lineWidth;

-(float) textWidth:(NSString *)text;


@end
