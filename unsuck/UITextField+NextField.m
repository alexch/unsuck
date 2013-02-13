//
//  UITextField+NextField.m
//  MedHack
//
//  Created by Alex Chaffee on 2/12/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//
// based on http://stackoverflow.com/a/8344851/190135


#import "UITextField+NextField.h"
#import <objc/runtime.h>

static char nextField_KEY;

@implementation UITextField (NextField)

- (UIResponder*) nextField {
    return objc_getAssociatedObject(self, &nextField_KEY);
}

- (void) setNextField:(UIResponder *)field{
    objc_setAssociatedObject(self, &nextField_KEY, field, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

// call this from textFieldShouldReturn
-(BOOL) selectNextField
{
    BOOL didResign = [self resignFirstResponder];
    if (!didResign) return NO;

    if ([self nextField]) {
        dispatch_async(dispatch_get_main_queue(), ^{       // async to overcome the return key getting sent to the new field
            [[self nextField] becomeFirstResponder];
        });
    }
    return YES;
}

@end
