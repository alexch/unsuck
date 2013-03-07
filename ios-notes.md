# iOS

http://stackoverflow.com/questions/1314299/iphone-toggle-button-implementation

UIKit class diagram: http://developer.apple.com/library/ios/documentation/uikit/reference/UIKit_Framework/Art/uikit_classes.jpg
Foundation classes: http://developer.apple.com/library/ios/#documentation/Cocoa/Reference/Foundation/ObjC_classic/Intro/IntroFoundation.html

HIG: http://disanji.net/iOS_Doc/#documentation/UserExperience/Conceptual/MobileHIG/UIElementGuidelines/UIElementGuidelines.html

UIDocument: https://developer.apple.com/library/ios/#documentation/DataManagement/Conceptual/DocumentBasedAppPGiOS/DocumentArchitectureiniOS/DocumentArchitectureiniOS.html

Cocoa Is My Girlfriend: http://www.cimgf.com/

app store review time metrics: http://reviewtimes.shinydevelopment.com/

http://stackoverflow.com/questions/5029267/is-there-any-way-of-asking-an-ios-view-which-of-its-children-has-first-responder

http://www.hongkiat.com/blog/ios-development-guide-part2-your-first-app/

## icons

http://glyphish.com/
fatcow

## .gitignore

http://www.makebetterthings.com/iphone/gitignore-for-ios-projects/
https://gist.github.com/adamgit/3786883

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

Open Quickly: Cmd-Shift-O (see also http://codepilot.cc/)

## Animation

https://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/CoreAnimation_guide/Introduction/Introduction.html
https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/CoreAnimation_Cookbook
https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/Animation_Overview/Introduction/Introduction.html
 "Implicit animations occur automatically in response to setting a new value for an animatable layer property. Core Animation assumes full responsibility for running the animation, at frame rate, in a separate thread, freeing your application to handle other events."

http://www.raywenderlich.com/2454/how-to-use-uiview-animation-tutorial
http://www.raywenderlich.com/5478/uiview-animation-tutorial-practical-recipes
http://maniacdev.com/2011/08/open-source-extensive-core-animation-techniques-demo/

http://robots.thoughtbot.com/post/36591648724/designing-for-ios-graphics-performance

http://khanlou.com/2012/08/skbounceanimation/
http://www.scoop.it/t/core-animation-1


animation with blocks: http://pragmaticstudio.com/blog/2010/7/28/ios4-blocks-1


## Core Graphics / Quartz 2D

https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/drawingwithquartz2d/Introduction/Introduction.html
  "Quartz 2D provides low-level, lightweight 2D rendering with unmatched output fidelity regardless of display or printing device. Quartz 2D is resolution- and device-independent; you don’t need to think about the final destination when you use the Quartz 2D application programming interface (API) for drawing. The Quartz 2D API is easy to use and provides access to powerful features such as transparency layers, path-based drawing, offscreen rendering, advanced color management, anti-aliased rendering, and PDF document creation, display, and parsing. The Quartz 2D API is part of the Core Graphics framework, so you may see Quartz referred to as Core Graphics or, simply, CG."

https://www.google.com/search?q=core+graphics+tutorial
http://www.raywenderlich.com/2033/core-graphics-101-lines-rectangles-and-gradients
http://stackoverflow.com/questions/3463256/what-are-some-great-quartz-2d-drawing-tutorials

"The Quartz 2D API is part of the Core Graphics framework, so you may see Quartz referred to as Core Graphics or, simply, CG"

https://developer.apple.com/library/ios/#samplecode/QuartzDemo/Listings/ReadMe_txt.html

http://idevhub.com/exploring-iphone-graphics-part-1/ (was from trailsinthesand.com but that site is dead)
http://idevhub.com/exploring-iphone-graphics-part-2/ - bouncing ball animation
http://idevhub.com/exploring-iphone-graphics-part-3/ - accelerometer



## Core Image

https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/CoreImaging/ci_intro/ci_intro.html
    "The Core Image framework provides: Access to built-in image processing filters; Feature detection capability; Support for automatic image enhancement; The ability to chain multiple filters together to create custom effects.
https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/CoreImaging/ci_tasks/ci_tasks.html
    more than 90 built-in filters on iOS and over 120 on OS X. You set up filters by supplying key-value pairs for a filter’s input parameters. The output of one filter can be the input of another

## Games

http://snej.github.com/2007/12/20/GeekGameBoard/
http://bitbucket.org/snej/geekgameboard/
https://github.com/cherifya/GeekGameBoard

http://maniacdev.com/2011/09/tutorials-core-animation-game-development-gems/
http://mysterycoconut.com/blog/2011/01/cag1/
http://mysterycoconut.com/blog/2011/01/cag2/
http://mysterycoconut.com/blog/2011/01/cag3/
http://mysterycoconut.com/blog/2011/09/cag4/

http://mysterycoconut.com/blog/2011/02/designing-casey-2/

http://developer.apple.com/library/ios/#documentation/QuartzCore/Reference/CADisplayLink_ClassRef/Reference/Reference.html
http://www.streamingcolour.com/blog/2009/08/27/texture-atlases-and-bitmap-fonts/

http://idevblogaday.com/

http://www.koboldtouch.com/
http://iphonegamekit.com/

http://www.cocos2d-iphone.org/
http://chipmunk-physics.net/  "For iOS development, Chipmunk Pro includes "Objective-Chipmunk", an Objective-C wrapper around all Chipmunk functionality. This provides greatly simplified memory management (especially when combined with automatic reference counting), an object oriented syntax, convenience classes for multi-touch input, and more." $249  "With the popular Chipmunk Indie license, you can have access to the C and Objective-C APIs (including ARC, object management, and utility classes!) at a very Indie-friendly price." $99
http://box2d.org/

http://www.raywenderlich.com/25736/how-to-make-a-simple-iphone-game-with-cocos2d-2-x-tutorial
Cocos2D works with points, not pixels. On Retina display devices, 1 point = 2 pixels, so 1136×640 pixels = 568×320 points. This is quite handy, because if you use points in your game, your coordinates can be the same for both retina and non-retina displays!
the position is relative to the center of the sprite you are adding
Cocos2D – it’s smart enough to substitute the high resolution graphics when you’re running on a Retina display! Just put in some artwork that is double the size and add an -hd extension. This is similar to the @2x behavior that UIKit supports.

Cocos2d collision detection:
 http://iphonedevsdk.com/forum/iphone-sdk-game-development/17082-cocos2d-collision-detection-between-sprites.html
 http://www.learn-cocos2d.com/2011/12/fast-pixelperfect-collision-detection-cocos2d-code-1of2/

Spine: http://esotericsoftware.com/ Spine is a 2D skeletal animation tool for game development and other animation projects.

Sprite Sheets aka Atlases: http://www.raywenderlich.com/1271/how-to-use-animations-and-sprite-sheets-in-cocos2d
Zwoptex from zwoptexapp.com makes sprite sheets (combines many images into one image + boundary file)
CCSpriteBatchNode used to be called CCSpriteSheet
Texture Packer http://sites.fastspring.com/codeandweb/product/all

http://www.raywenderlich.com/tutorials#cocos2d
http://www.raywenderlich.com/3611/how-to-make-a-space-shooter-iphone-game

http://www.71squared.com/particledesigner
http://www.vickiwenderlich.com/ - free game art, tutorials

## 3D

OpenGL for Embedded Systems (OpenGL ES)
http://iphonedevelopment.blogspot.nl/2009/04/opengl-es-from-ground-up-part-1-basic.html

http://wiki.blender.org/ "integrated application that enables the creation of a diverse range of 2D and 3D content. Blender provides a broad spectrum of modeling, texturing, lighting, animation and video post-processing functionality in one package."
http://wiki.blender.org/index.php/Doc:2.6/Manual/Materials/Properties/Specular_Shaders

## Audio

http://www.raywenderlich.com/204/audio-101-for-iphone-developers-file-and-data-formats
http://www.raywenderlich.com/233/audio-101-for-iphone-developers-converting-and-recording
http://www.raywenderlich.com/259/audio-101-for-iphone-developers-playing-audio-programmatically

http://thirdcog.eu/apps/cfxr

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
http://pragmaticstudio.com/blog/2010/9/15/ios4-blocks-2


## Libraries that attempt to unsuck ObjC

 * https://github.com/mikeash/MACollectionUtilities - macros for creating, mapping, filtering, and matching arrays, sets and dicts
 * https://github.com/alexch/unsuck
 * https://github.com/progrmr/SDK_Utilities
 * https://github.com/snej/MYUtilities

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

