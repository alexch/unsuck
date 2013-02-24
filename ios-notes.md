# iOS

http://stackoverflow.com/questions/1314299/iphone-toggle-button-implementation

UIKit class diagram: http://developer.apple.com/library/ios/documentation/uikit/reference/UIKit_Framework/Art/uikit_classes.jpg
Foundation classes: http://developer.apple.com/library/ios/#documentation/Cocoa/Reference/Foundation/ObjC_classic/Intro/IntroFoundation.html

HIG: http://disanji.net/iOS_Doc/#documentation/UserExperience/Conceptual/MobileHIG/UIElementGuidelines/UIElementGuidelines.html

UIDocument: https://developer.apple.com/library/ios/#documentation/DataManagement/Conceptual/DocumentBasedAppPGiOS/DocumentArchitectureiniOS/DocumentArchitectureiniOS.html

Cocoa Is My Girlfriend: http://www.cimgf.com/

app store review time metrics: http://reviewtimes.shinydevelopment.com/

http://stackoverflow.com/questions/5029267/is-there-any-way-of-asking-an-ios-view-which-of-its-children-has-first-responder

## Video

https://developer.apple.com/library/mac/#documentation/AudioVideo/Conceptual/AVFoundationPG/Articles/00_Introduction.html#//apple_ref/doc/uid/TP40010188

To record video when you need only minimal control over format, use the UIKit framework (UIImagePickerController). The UIImagePickerController class manages customizable, system-supplied user interfaces for taking pictures and movies on supported devices, and for choosing saved images and movies for use in your app.

http://stackoverflow.com/questions/5666778/capture-real-time-screen-video-from-iphone-and-ipad-including-audio-and-post-to

https://developers.everyplay.com/

http://www.cimgf.com/2008/09/10/core-animation-tutorial-rendering-quicktime-movies-in-a-caopengllayer/

http://stackoverflow.com/questions/12633080/ios6-and-mpmovieplayercontroller-black-view

MPMoviePlayerController, MPMoviePlayerViewController
AVAssetWriter


## XCode

http://stackoverflow.com/questions/146297/hidden-features-of-xcode

Make failed tests show up:

    Xcode > Preferences > Behaviors
      > Testing > Fails > Navigate to [current log]

In Xcode 4 short cut to display and hide console is (command-shift-Y) , this will show the console and debugger below text editor in the same window

https://github.com/tomaz/appledoc

SO many ways of hooking up widgets! Delegates, IBActions, addTarget:action: forControlEvents:, etc... Is there a scorecard?

http://stackoverflow.com/questions/9370518/xcode-4-2-how-include-one-project-into-another-one
http://stackoverflow.com/questions/5271026/two-projects-in-xcode4-workspaces-import-failure


# Objective C

http://projectmultiplexer.com/2011/03/31/the-beauty-of-objective-c/
http://lethain.com/filtering-arrays-in-objective-c/
http://benscheirman.com/2011/04/private-categories-in-objective-c
http://blog.carbonfive.com/2012/01/23/monkey-patching-ios-with-objective-c-categories-part-1-simple-extensions-and-overrides/

use objc_setAssociatedObject/objc_getAssociatedObject inside a category implementation to store a simulated instance variable http://stackoverflow.com/questions/2846218/how-do-i-use-objc-setassociatedobject-objc-getassociatedobject-inside-an-object http://stackoverflow.com/questions/1347779/how-to-navigate-through-textfields-next-done-buttons

## ARC and memory management

http://clang.llvm.org/docs/AutomaticReferenceCounting.html

http://developer.apple.com/library/ios/#releasenotes/ObjectiveC/RN-TransitioningToARC/Introduction/Introduction.html

A weak reference does not extend the lifetime of the object it points to, and automatically becomes nil when there are no strong references to the object.

Exceptions are unsafe: http://stackoverflow.com/questions/4648952/objective-c-exceptions (unless they make the whole program exit?)

## Misc

http://it.toolbox.com/blogs/macsploitation/extending-classes-in-objectivec-with-categories-27447

http://stackoverflow.com/questions/992901/how-do-i-iterate-over-an-nsarray

Blocks: http://pragmaticstudio.com/blog/2010/7/28/ios4-blocks-1

## Libraries that attempt to unsuck ObjC

 * https://github.com/mikeash/MACollectionUtilities - macros for creating, mapping, filtering, and matching arrays, sets and dicts
 * https://github.com/alexch/unsuck
 * https://github.com/progrmr/SDK_Utilities


## Testing

### SenTest

STAssert is macros

STAssertEqualObjects returns unhelpful "(" error when 2 arrays are unequal size -- I implemented [assertArray:equals:because] to work around this

NSLog output is hidden - http://agilewarrior.wordpress.com/2012/02/28/where-is-nslog-output-for-ocunit-tests/

"did not finish" - http://stackoverflow.com/questions/12308297/some-of-my-unit-tests-tests-are-not-finishing-in-xcode-4-4 :

    - (void)tearDown
    {
        [NSThread sleepForTimeInterval:0.0];
        [super tearDown];
    }

### KIF

* https://github.com/square/KIF
* http://rubymaverick.com/blog/2012/10/21/setting-up-kif-integration-tests-for-ios/

# RubyMotion

http://rubysource.com/getting-to-know-rubymotion-with-laurent-sansonetti/
http://rubysource.com/laurent-sansonetti-on-rubymotion-internals/
https://github.com/rubymotion/BubbleWrap

