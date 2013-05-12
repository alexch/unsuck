# unsuck

<https://github.com/alexch/unsuck>

by Alex Chaffee

a collection of methods and macros that make Objective C / Cocoa easier to use for humans

see [Humane Interface](http://martinfowler.com/bliki/HumaneInterface.html) (coined by [Jef Raskin](http://en.wikipedia.org/wiki/The_Humane_Interface))

## Usage

### `NSRegularExpression`:

    [NSRegularExpression from: @"regexp?"]

    [[NSRegularExpression from: @"fo*"] allMatches: "foo bar fooooo"]

    for (NSString *string in [[NSRegularExpression from: @"fo*"] allMatches: @"foo bar fooooo"]) {
        NSLog(@"%@", string); // logs "foo" and then "fooooo"
    }

### `UITextField+NextField`:

Gives you an outlet to wire up a field to its nextField by control-dragging in IB; you can it to switch focus to the next field in sequence when the user hits return by putting this on your field's delegate:

   #import "unsuck/UITextField+NextField.h"

   - (BOOL)textFieldShouldReturn:(UITextField *)textField
   {
     return [textField selectNextField];
   }

### `CGCanvas`: a wrapper for `CGContext*` methods:

Before:

    CGContextRef context = UIGraphicsGetCurrentContext();
	CGContextSetRGBStrokeColor(context, 1.0, 1.0, 1.0, 1.0);
	CGContextSetRGBFillColor(context, 0.0, 0.0, 1.0, 1.0);
	CGContextSetLineWidth(context, 2.0);
	CGContextFillEllipseInRect(context, CGRectMake(30.0, 210.0, 60.0, 60.0));
	CGContextAddArc(context, 150.0, 60.0, 30.0, 0.0, M_PI/2.0, false);
	CGContextStrokePath(context);
	CGContextAddArc(context, 150.0, 60.0, 30.0, 3.0*M_PI/2.0, M_PI, true);
	CGContextStrokePath(context);

After:
    CGCanvas *canvas = [CGCanvas current];
	[canvas setRGBStrokeColor_red: 1.0 green: 1.0 blue: 1.0 alpha: 1.0];
    [canvas setRGBFillColor_red:0.0 green:0.0 blue:1.0 alpha:1.0];
    [canvas setLineWidth:2.0];
    [canvas fillEllipseInRect:CGRectMake(30.0, 210.0, 60.0, 60.0)];
    [canvas addArc_x:150.0 y:60.0 radius:30.0 startAngle:0.0 endAngle:M_PI/2.0 clockwise:false];
    [canvas strokePath];
    [canvas addArc_x:150.0 y:60.0 radius:30.0 startAngle:3.0*M_PI/2.0 endAngle:M_PI clockwise:true];
    [canvas strokePath];

(see <http://stackoverflow.com/questions/10842646/objective-c-wrapper-class-for-cgcontext> for discussion)

## Unit Tests

Yes, there are unit tests. [Read them](unsuckTests/) for more examples.

There are also unsucky extensions for you to use in *your* unit tests, like `SenTestCase+Unsuck`. Not quite sure how to name or use them yet, though.

## git submodule usage

XCode is really annoying about putting multiple projects in the same workspace. As an alternative you may want to use git submodules, which are also really annoying.

To add this as a submodule to your project:

    git submodule add git://github.com/alexch/unsuch.git unsuck

that will add a `.gitmodules` file which points to the git url and to the specific commit within that file.

When you clone a repo with submodules, in addition to `git clone` you also have to run

    git submodule init
    git submodule update

And if you pull a revision that includes a change to the submodule, in addition to `git pull` (or `git merge`) you must again run

    git submodule update

If you happen to see the error

    fatal: reference isn’t a tree

then it means someone changed the submodule reference but failed to push the new commit up to the public repo. In that case, in the words of Scott Chacon, "Then, you e-mail that guy and yell at him."


## iOS Notes

I'm also using this repo to hold my [notes on learning IOS and Objective C](ios-notes.md). Contains many links to things that flabbergasted me.
