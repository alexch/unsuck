//
//  UITextField+NextField.h
//  MedHack
//
//  Created by Alex Chaffee on 2/12/13.
//  Copyright (c) 2013 Alex Chaffee. All rights reserved.
//
// based on http://stackoverflow.com/a/8344851/190135
//
// Usage (on a text field, to go to the next field after the user hits the "return" key):
// 0. add this project to your workspace, and then do all this nonsense:
//    http://stackoverflow.com/questions/9370518/xcode-4-2-how-include-one-project-into-another-one
//    http://stackoverflow.com/questions/5271026/two-projects-in-xcode4-workspaces-import-failure
// 1. wire up each field to its nextField by control-dragging in IB
// 2. put this on your field's delegate:
//
// #import "unsuck/UITextField+NextField.h"
//
// - (BOOL)textFieldShouldReturn:(UITextField *)textField
// {
//     return [textField selectNextField];
// }
//
// todo: figure out if this really belongs on UIResponder, not just UITextField

#import <UIKit/UIKit.h>

@interface UITextField (NextField)

@property(retain, nonatomic) IBOutlet UIResponder* nextField;

-(BOOL)selectNextField;

@end
