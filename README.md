# unsuck

<https://github.com/alexch/unsuck>

by Alex Chaffee

a collection of methods and macros that make Objective C / Cocoa easier to use for humans

see [Humane Interface](http://martinfowler.com/bliki/HumaneInterface.html) (coined by [Jef Raskin](http://en.wikipedia.org/wiki/The_Humane_Interface))

## Usage

### `Randy`

Simple routines for getting random numbers:

    #import "Randy.h"

    [Randy unit]         // returns random double between 0 <= n < 1.0
    [Randy int: 10]      // returns random integer (unsigned long) between 0 < n < max
    [Randy double: 2.75] // returns random double between 0 < n < max

### `NSRegularExpression`:

    #import "NSRegularExpression+Unsuck.h"

    [NSRegularExpression from: @"regexp?"]

    [[NSRegularExpression from: @"fo*"] allMatches: "foo bar fooooo"]

    for (NSString *string in [[NSRegularExpression from: @"fo*"] allMatches: @"foo bar fooooo"]) {
        NSLog(@"%@", string); // logs "foo" and then "fooooo"
    }

### `NSString` and `NSArray`

    #import "NSString+Unsuck.h"

    NSArray *lines = [@"my\ndog\nhas\nfleas" lines];     // @[@"my", @"dog", @"has", @"fleas"]

    NSArray *words = [@"my dog has fleas" split];        // @[@"my", @"dog", @"has", @"fleas"]
    NSArray *words = [@"my,dog,has,fleas" split: @","];  // @[@"my", @"dog", @"has", @"fleas"]

    NSString *s = [@"  foo  " trim];   // @"foo"


    #import "NSArray+Unsuck.h"

    NSArray * abc = @[@"a", @"b", @"c"];
    NSArray * bcd = @[@"b", @"c", @"d"];
    NSArray * after = [abc minus:bcd];   // @[@"a"]


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

	CGContextSetRGBFillColor(context, 0.0, 0.0, 1.0, 1.0);
	CGContextSetLineWidth(context, 2.0);
	CGContextFillEllipseInRect(context, CGRectMake(30.0, 210.0, 60.0, 60.0));

	CGContextSetRGBStrokeColor(context, 1.0, 1.0, 1.0, 1.0);
	CGContextAddArc(context, 150.0, 60.0, 30.0, 0.0, M_PI/2.0, false);
	CGContextStrokePath(context);
	CGContextAddArc(context, 150.0, 60.0, 30.0, 3.0*M_PI/2.0, M_PI, true);
	CGContextStrokePath(context);

After:

    #import "CGCanvas+Extras.h"

    CGCanvas *canvas = [CGCanvas current];

    // high level
    [canvas fillEllipse:rect withColor:[UIColor blueColor] andLineWidth:2.0];

    // low level
	[canvas setRGBStrokeColor_red: 1.0 green: 1.0 blue: 1.0 alpha: 1.0];
    [canvas setLineWidth:2.0];
    [canvas addArc_x:150.0 y:60.0 radius:30.0 startAngle:0.0 endAngle:M_PI/2.0 clockwise:false];
    [canvas strokePath];
    [canvas addArc_x:150.0 y:60.0 radius:30.0 startAngle:3.0*M_PI/2.0 endAngle:M_PI clockwise:true];
    [canvas strokePath];

* See <http://stackoverflow.com/questions/10842646/objective-c-wrapper-class-for-cgcontext> for discussion.
* See also <https://github.com/mpw/MPWDrawingContext> which is more fleshed-out and maybe we should merge.

## Unit Tests

Yes, there are unit tests. [Read them](unsuckTests/) for more usage examples.

There are also unsucky extensions for you to use in *your* unit tests, like `SenTestCase+Unsuck`. They're in a subdirectory called unsuck-testing -- XCode doesn't like it when regular code references the SenTestingKit library, so putting them in a subdirectory may make it easier to exclude them from your deploy target(s).

## git submodule usage

XCode is really annoying about putting multiple projects in the same workspace. As an alternative you may want to use git submodules, which are also really annoying.

To add this as a submodule to your project:

    git submodule add https://github.com/alexch/unsuck.git unsuck

that will add a `.gitmodules` file which points to the git url and to the specific commit within that file.

When you clone a repo with submodules, in addition to `git clone` you also have to run

    git submodule init
    git submodule update

And if you pull a revision that includes a change to the submodule, in addition to `git pull` (or `git merge`) you must again run

    git submodule update

If you happen to see the error

    fatal: reference isn’t a tree

then it means someone changed the submodule reference but failed to push the new commit up to the public repo. In that case, in the words of Scott Chacon, "Then, you e-mail that guy and yell at him."

And when you (I) make a change inside the submodule repo, to push it, use

    git push https://github.com/alexch/unsuck.git

it seems to go to master alright.

Once the submodule is in your repo, I suggest adding ("Add Files To 'Project'...") the subfolders named "`unsuck`" and "`unsuck-testing`" rather than adding the entire top-level "`unsuck`" directory. Otherwise XCode may get confused by the included project file and test files. You can open the `unsuck.xcodeproj` file in a separate window if you want to read this readme or run the unsuck unit tests.

## iOS Notes

I'm also using this repo to hold my [notes on learning IOS and Objective C](ios-notes.md). Contains many links to things that flabbergasted me.
