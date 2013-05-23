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

http://speirs.org/blog/2012/1/2/misconceptions-about-ios-multitasking.html

No longer necessary or called: -[UIViewController viewDidUnload]

$ macerror -43
Mac OS error -43 (fnfErr): File not found

http://stackoverflow.com/questions/8100054/no-exception-stack-trace-in-console-under-xcode-4-2-ios-5

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


http://stackoverflow.com/questions/4979192/ios-using-uiviews-drawrect-vs-its-layers-delagate-drawlayerincontext "Always use drawRect:, and never use a UIView as the drawing delegate for any CALayer." and "While the use of drawRect is common, it's a practice that has been discouraged since at least 2002/2003, IIRC"

https://developer.apple.com/library/ios/#qa/qa1708/_index.html#//apple_ref/doc/uid/DTS40010245 Q:  What can I do to improve my image drawing performance (CGContextDrawImage, UIImage/-drawInRect:, etc)?
  * Every UIView is backed with a CALayer and images as layer contents remain in memory as long as the CALayer stays in the hierarchy.
  * One way to do it would be applying a rotation transform to the Current Transform Matrix (CGContextRotateCTM) and redrawing the image (CGContextDrawImage) in the UIView's -drawRect: method at every animation step. However, a much more efficient way is to set the image as the contents property of the backing CALayer, and then animate the layer's transform property to achieve the rotating animation.
  * If you can, adjust your resource art so that the image size (in pixels) is the same as its displayed size (in pixels), meaning you would provide different image sets for iPhone/iPod touch (image.png), iPhone 4 (image@2x.png), and iPad (image-iPad.png). Further, you could cache the images yourself by drawing into a bitmap context and caching the image you create from the context.


View/Layer frame/bounds/position shuffle: http://stackoverflow.com/questions/13976219/how-do-i-set-an-lldb-watchpoint-on-a-property-of-self-view/13980286#13980286
  The view controller references its view from its _view instance variable.
  The view doesn't store its frame directly. It just returns its layer's `frame'.
  The view references its layer from its _layer instance variable.
  The layer doesn't store the frame either. It computes its frame from its bounds, position, anchorPoint, and transform. The size is part of bounds.
  The layer doesn't store its bounds directly in an instance variable. Instead, its layer instance variable references an instance of a private C++ class, CA::Layer. The member layout of this class is undocumented.


http://adcdownload.apple.com//wwdc_2010/wwdc_2010_video_assets__pdfs/135__advanced_performance_optimization_on_iphone_os_part_1.pdf
http://adcdownload.apple.com//wwdc_2012/wwdc_2012_session_pdfs/session_238__ios_app_performance_graphics_and_animations.pdf (from https://developer.apple.com/videos/wwdc/2012/) -- THIS IS GREAT


http://robots.thoughtbot.com/post/36591648724/designing-for-ios-graphics-performance

http://khanlou.com/2012/08/skbounceanimation/
http://www.scoop.it/t/core-animation-1
http://khanlou.com/2012/01/cakeyframeanimation-make-it-bounce/
http://stackoverflow.com/questions/537425/halting-in-progress-cakeyframeanimation/537952#537952

animation with blocks: http://pragmaticstudio.com/blog/2010/7/28/ios4-blocks-1

http://iphonedevsdk.com/forum/iphone-sdk-tutorials/100982-caanimation-tutorial.html


http://ajourneywithios.blogspot.com/2011/03/simplified-use-of-nstimer-class-in-ios.html
force a UIView to re-render is [myView setNeedsDisplay]  - http://stackoverflow.com/questions/1503761/what-is-the-most-robust-way-to-force-a-uiview-to-redraw

the key in CALayer: (void)addAnimation:(CAAnimation *)anim forKey:(NSString *)key; is not necessarily the same as the one in CAPropertyAnimation: (id)animationWithKeyPath:(NSString *)path -- though if the latter is nil, it gets filled in if you pass it to the former

If you want animated properties to stick when the animation ends, you have to either
    animation.removedOnCompletion = NO;
    animation.fillMode = kCAFillModeForwards;
or have the presentation layer send the new values into the model layer (or model itself) in the setter.

The CAAnimation and CALayer classes are key-value coding compliant container classes, which means that you can set values for arbitrary keys. http://developer.apple.com/library/ios/#documentation/Cocoa/Conceptual/CoreAnimation_guide/Key-ValueCodingExtensions/Key-ValueCodingExtensions.html#//apple_ref/doc/uid/TP40004514-CH12-SW2

bounds vs. frame in layers: Layers have an implicit frame that is a function of the position, bounds, anchorPoint, and transform properties. Setting a new frame rectangle changes the layer's position and bounds properties appropriately, but the frame itself is not stored. When a new frame rectangle is specified the bounds origin is undisturbed, while the bounds size is set to the size of the frame. The layer's position is set to the proper location relative to the anchor point. When you get the frame property value, it is calculated relative to the position, bounds, and anchorPoint properties.

CAShapeLayer


Animation Timing:
http://developer.apple.com/library/ios/#documentation/Cocoa/Conceptual/Animation_Types_Timing/Articles/Timing.html#//apple_ref/doc/uid/TP40006670-SW1

A CADisplayLink object is a timer object that allows your application to synchronize its drawing to the refresh rate of the display.
https://zearfoss.wordpress.com/2011/03/09/drawing-with-cadisplaylink/
http://www.ananseproductions.com/game-loops-on-ios/


### Particle Effects

http://blog.argteam.com/tag/caemitterlayer/
https://developer.apple.com/library/mac/#samplecode/Fire/Listings/AppController_m.html#//apple_ref/doc/uid/DTS40009036-AppController_m-DontLinkElementID_4
http://www.vigorouscoding.com/mac-apps/particle-playground/
http://www.vigorouscoding.com/2013/02/particle-image-gets-mirrored-by-uikit-particle-system/


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

"The fundamental tool used to create paths is the Bézier curve... An application specifies the Bézier curves as a series of short curve segments. In the most common case, there are four points in user space that make up each segment. The curve is set up so that, once the numbers are crunched, the path passes through the first point and the last point. The curve is pulled away from a straight line by the two other points in a way that is both mathematically elegant and ultimately intuitive." http://macdevcenter.com/pub/a/mac/2004/09/28/quartz.html?page=2

http://maniacdev.com/2009/09/6-resources-for-learning-core-graphics/
http://blogs.oreilly.com/iphone/2008/12/converting-points-and-rectangl.html

http://blogs.oreilly.com/iphone/2008/12/useful-core-graphics-functions.html
https://github.com/mpw/MPWDrawingContext
http://www.natestedman.com/post/improving-cgcontext-with-blocks/
http://boredzo.org/blog/archives/2012-06-01/on-the-api-design-of-cgbitmapcontextcreate
http://developer.apple.com/library/ios/#documentation/GraphicsImaging/Reference/CGPath/Reference/reference.html
http://stackoverflow.com/questions/10842646/objective-c-wrapper-class-for-cgcontext

http://en.wikipedia.org/wiki/Kochanek-Bartels_spline

tendrils grass http://js1k.com/2013-spring/demo/1547
http://nodebox.net/code/index.php/Tendrils


## Core Image

https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/CoreImaging/ci_intro/ci_intro.html
    "The Core Image framework provides: Access to built-in image processing filters; Feature detection capability; Support for automatic image enhancement; The ability to chain multiple filters together to create custom effects.
https://developer.apple.com/library/mac/#documentation/GraphicsImaging/Conceptual/CoreImaging/ci_tasks/ci_tasks.html
    more than 90 built-in filters on iOS and over 120 on OS X. You set up filters by supplying key-value pairs for a filter’s input parameters. The output of one filter can be the input of another


https://github.com/BradLarson/GPUImage

http://stackoverflow.com/questions/4334233/how-to-capture-uiview-to-uiimage-without-loss-of-quality-on-retina-display?rq=1



## Games


Essential Game Technologies for iOS, Pt 1 & 2 at https://developer.apple.com/videos/wwdc/2011/
http://adcdownload.apple.com//wwdc_2011/adc_on_itunes__wwdc11_sessions__pdf/403_iosgamespart2_repeat.pdf

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

ShinyCocos - Ruby interpreter + Cocos2d bindings -
  http://www.cocos2d-iphone.org/wiki/doku.php/shinycocos%3Afaq
  https://github.com/funkaster/shinycocos

http://gamua.com/sparrow/
http://www.openframeworks.cc/

http://realtimecollisiondetection.net/
http://bulletphysics.org/wordpress/


## Physics
http://chipmunk-physics.net/  "For iOS development, Chipmunk Pro includes "Objective-Chipmunk", an Objective-C wrapper around all Chipmunk functionality. This provides greatly simplified memory management (especially when combined with automatic reference counting), an object oriented syntax, convenience classes for multi-touch input, and more." $249  "With the popular Chipmunk Indie license, you can have access to the C and Objective-C APIs (including ARC, object management, and utility classes!) at a very Indie-friendly price." $99
http://box2d.org/
https://developer.apple.com/library/mac/#samplecode/OpenCL_NBody_Simulation_Example/Introduction/Intro.html#//apple_ref/doc/uid/DTS40008471-Intro-DontLinkElementID_2


http://gafferongames.com/game-physics/  -- awesome tutorial, build a little physics engine one step at a time
http://gafferongames.com/game-physics/fix-your-timestep/
http://gafferongames.com/game-physics/spring-physics/

## 3D

OpenGL for Embedded Systems (OpenGL ES)
http://iphonedevelopment.blogspot.nl/2009/04/opengl-es-from-ground-up-part-1-basic.html

http://wiki.blender.org/ "integrated application that enables the creation of a diverse range of 2D and 3D content. Blender provides a broad spectrum of modeling, texturing, lighting, animation and video post-processing functionality in one package."
http://wiki.blender.org/index.php/Doc:2.6/Manual/Materials/Properties/Specular_Shaders

http://maniacdev.com/ios-5-sdk-tutorial-and-guide/glkit/ "GLKit was added in iOS 5 in order to simplify programming of OpenGL ES in iOS apps."
https://github.com/71squared/GLKit_TD3D

http://unity3d.com/


http://stackoverflow.com/questions/7128829/could-i-get-a-basic-explanation-of-catransform3didentity
http://chortle.ccsu.edu/vectorlessons/vectorIndex.html

## Text and Fonts

http://stackoverflow.com/questions/360751/can-i-embed-a-custom-font-in-an-iphone-application

http://stackoverflow.com/questions/4386367/drawing-text-with-core-graphics

https://developer.apple.com/library/mac/#documentation/graphicsimaging/conceptual/drawingwithquartz2d/dq_text/dq_text.html

http://stackoverflow.com/questions/1054558/vertically-align-text-within-a-uilabel/1054681

https://github.com/nicklockwood/FXLabel - FXLabel improves upon the standard UILabel by providing a subclass that supports soft shadows, inner shadow and gradient fill, and which can easily be used in place of any standard UILabel.
    also NSString method calculates the size of a rendered string

## Audio

http://www.raywenderlich.com/204/audio-101-for-iphone-developers-file-and-data-formats
http://www.raywenderlich.com/233/audio-101-for-iphone-developers-converting-and-recording
http://www.raywenderlich.com/259/audio-101-for-iphone-developers-playing-audio-programmatically

http://thirdcog.eu/apps/cfxr

http://stackoverflow.com/questions/1002838/audio-on-the-iphone

http://adcdownload.apple.com//wwdc_2010/wwdc_2010_video_assets__pdfs/412__audio_development_for_iphone_os_part_1.pdf

http://benbritten.com/2008/11/06/openal-sound-on-the-iphone/ :
    the quickest (and easiest) way to make the iPhone spit out some sound is to use the audio system services:

    NSString* path = [[NSBundle mainBundle] pathForResource:@"soundEffect1" ofType:@"caf"];
    NSURL * afUrl = [NSURL fileURLWithPath:path];
    UInt32 soundID;
    AudioServicesCreateSystemSoundID((CFURLRef)afUrl,&soundID);
    AudioServicesPlaySystemSound (soundID);

    this works well for making your interface buttons click and simple UI interaction stuff. However, it is absolutely shite for anything more complicated than that (think: a game)... For better control of the sound, you will require either openAL or audioUnits or the audioQueue.

http://stackoverflow.com/questions/2067267/where-to-start-with-audio-synthesis-on-iphone
http://atastypixel.com/blog/using-remoteio-audio-unit/

http://audacity.sourceforge.net/download/mac

Use an MPMusicPlayerController object, or music player, to play media items from the device iPod library.
To play multiple sounds with best performance, or to efficiently play sounds while the iPod is playing in the background, use linear PCM (uncompressed) or IMA4 (compressed) audio.

http://stackoverflow.com/questions/984729/how-can-i-determine-how-loud-a-wav-file-will-sound
http://stackoverflow.com/questions/9162509/how-to-calculate-dbr-from-the-volume-on-ios

http://stackoverflow.com/questions/632718/native-iphone-audio-format

http://stackoverflow.com/questions/8016765/avaudioplayer-not-playing-any-sound OMFG

http://www.mailinglistarchive.com/coreaudio-api@lists.apple.com/msg07024.html

http://supermegaultragroovy.com/2009/10/06/drawing-waveforms/

http://stackoverflow.com/questions/6594810/press-a-button-it-makes-a-sound-hit-button-fast-and-sound-playback-pops-and-cli

Here's some sample code which may help getting pcm data from a compressed file: cogs.susx.ac.uk/users/nc81/code.html

http://benbritten.com/2008/11/06/openal-sound-on-the-iphone/

http://lists.apple.com/archives/coreaudio-api/2008/Dec/msg00173.html -- generate a sin tone and stick it in a buffer using RemoteIO AudioUnit

The AUTimePitch unit can be used to speed up or slow down audio data without changing pitch to facilitate for example, the playing back of an audio book faster or slower than real-time. AUTimePitchTest demonstrates how to build an Audio Unit Graph connecting an AUConverter to a MultiChannel Mixer to the AUTimePitch audio unit then to the Default Output unit.

RemoteIO Audio Unit + the 3D Mixer Audio Unit + ExtAudioFile => mutliple sounds simultaneously
https://developer.apple.com/library/ios/#samplecode/iPhoneMultichannelMixerTest/Introduction/Intro.html

http://supermegaultragroovy.com/products/FuzzMeasure/

http://stackoverflow.com/questions/3326665/example-of-using-audio-queue-services

synthesizing - http://lists.apple.com/archives/coreaudio-api/2008/Dec/msg00173.html

https://developer.apple.com/library/ios/#samplecode/iPhoneMultichannelMixerTest/Introduction/Intro.html

http://developer.apple.com/library/ios/#DOCUMENTATION/AVFoundation/Reference/AVAudioPlayerClassReference/Reference/Reference.html

http://developer.apple.com/library/ios/#DOCUMENTATION/AudioVideo/Conceptual/MultimediaPG/UsingAudio/UsingAudio.html
  Use the Media Player framework to play songs, audio books, or audio podcasts from a user’s iPod library. For details, see Media Player Framework Reference, iPod Library Access Programming Guide, and the AddMusic sample code project.
  Use the AV Foundation framework to play and record audio using a simple Objective-C interface. For details, see AV Foundation Framework Reference and the avTouch sample code project.
  Use the Audio Toolbox framework to play audio with synchronization capabilities, access packets of incoming audio, parse audio streams, convert audio formats, and record audio with access to individual packets. For details, see Audio Toolbox Framework Reference and the SpeakHere sample code project.
  Use the Audio Unit framework to connect to and use audio processing plug-ins. For details, see Audio Unit Hosting Guide for iOS.
  Use the OpenAL framework to provide positional audio playback in games and other applications. iOS supports OpenAL 1.1. For information on OpenAL, see the OpenAL website, OpenAL FAQ for iPhone OS, and the oalTouch sample code project.

  The open-sourced OpenAL audio API, available in iOS in the OpenAL framework, provides an interface optimized for positioning sounds in a stereo field during playback. Playing, positioning, and moving sounds works just as it does on other platforms. OpenAL also lets you mix sounds. OpenAL uses the I/O unit for playback, resulting in the lowest latency.
  For all of these reasons, OpenAL is your best choice for playing sounds in game applications on iOS-based devices. However, OpenAL is also a good choice for general iOS application audio playback needs.




## GarageBand Instruments

http://mac.softpedia.com/get/Audio/Boldt-24-Pack.shtml
http://www.d.umn.edu/~bold0070/projects/instruments/
http://sonicamigos.com/polyphonticsgb/
http://www.hammersound.net/



### Core Audio

AudioToolbox
 - CoreAudioClock.h: Lets you designate a timing source for synchronizing applications or devices.

AVFoundation
 - available in iOS only
 - AVAudioPlayer.h: Defines an interface for playing audio from a file or from memory.

http://stackoverflow.com/questions/10329291/play-a-short-sound-in-ios

### OpenAL

http://benbritten.com/2008/11/06/openal-sound-on-the-iphone/

http://connect.creativelabs.com/openal/Documentation/OpenAL_Programmers_Guide.pdf

http://www.71squared.com/2009/05/iphone-game-programming-tutorial-9-sound-manager/


# Objective C

http://projectmultiplexer.com/2011/03/31/the-beauty-of-objective-c/
http://lethain.com/filtering-arrays-in-objective-c/
http://benscheirman.com/2011/04/private-categories-in-objective-c
http://blog.carbonfive.com/2012/01/23/monkey-patching-ios-with-objective-c-categories-part-1-simple-extensions-and-overrides/

use objc_setAssociatedObject/objc_getAssociatedObject inside a category implementation to store a simulated instance variable http://stackoverflow.com/questions/2846218/how-do-i-use-objc-setassociatedobject-objc-getassociatedobject-inside-an-object http://stackoverflow.com/questions/1347779/how-to-navigate-through-textfields-next-done-buttons

All memory for a newly allocated object is initialized to 0 (except for isa), so don't clutter up the init method by re-initializing variables to 0 or nil.

Apple's Coding Guidelines for Cocoa - http://developer.apple.com/library/mac/#documentation/Cocoa/Conceptual/CodingGuidelines/CodingGuidelines.html
Google's Objective-C Style Guide - http://google-styleguide.googlecode.com/svn/trunk/objcguide.xml

http://stackoverflow.com/questions/1043820/what-programming-skills-i-need-to-become-an-iphone-developer

CS 193P iPhone Application Development - http://www.stanford.edu/class/cs193p
https://itunes.apple.com/us/course/coding-together-developing/id593208016

When declaring instance variables, don't forget the braces!
    @implementation Sound
    {
        float _volume;  // instance var
    }
    float _volume;      // static var!!

http://www.davidhamrick.com/2012/02/12/Adding-Properties-to-an-Objective-C-Category.html

http://stackoverflow.com/questions/1063229/objective-c-static-class-level-variables

## ARC and memory management

http://clang.llvm.org/docs/AutomaticReferenceCounting.html

http://developer.apple.com/library/ios/#releasenotes/ObjectiveC/RN-TransitioningToARC/Introduction/Introduction.html

A weak reference does not extend the lifetime of the object it points to, and automatically becomes nil when there are no strong references to the object.

Exceptions are unsafe: http://stackoverflow.com/questions/4648952/objective-c-exceptions (unless they make the whole program exit?)

atomic/nonatomic: http://stackoverflow.com/questions/3227176/error-writable-atomic-property-cannot-pair-a-synthesized-setter-getter-with-a-u

http://stackoverflow.com/questions/12665292/objective-c-custom-setter
http://stackoverflow.com/questions/1306897/how-to-provide-additional-custom-implementation-of-accessor-methods-when-using

http://adcdownload.apple.com//wwdc_2012/wwdc_2012_session_pdfs/session_242__ios_app_performance_memory.pdf


## Misc

http://it.toolbox.com/blogs/macsploitation/extending-classes-in-objectivec-with-categories-27447

http://stackoverflow.com/questions/992901/how-do-i-iterate-over-an-nsarray

Blocks: http://pragmaticstudio.com/blog/2010/7/28/ios4-blocks-1
http://pragmaticstudio.com/blog/2010/9/15/ios4-blocks-2
http://www.eosgarden.com/en/articles/objc-blocks/


## Libraries that attempt to unsuck ObjC

 * https://github.com/mikeash/MACollectionUtilities - macros for creating, mapping, filtering, and matching arrays, sets and dicts
 * https://github.com/alexch/unsuck
 * https://github.com/progrmr/SDK_Utilities
 * https://github.com/snej/MYUtilities
 * http://sstoolk.it/documentation/index.html - SSToolkit is a collection of well-documented iOS classes for making life easier by solving common problems all iOS developers face. Some really handy classes are SSCollectionView, SSGradientView, and many more

http://vgable.com/blog/2010/08/19/the-most-useful-objective-c-code-ive-ever-written/comment-page-1/
http://jens.ayton.se/blag/almost-elegant-cave-man-debugging/

## Ads

## Files

http://stackoverflow.com/questions/10221290/how-to-delete-icloud-documents/15026829


# Testing

## SenTest

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

