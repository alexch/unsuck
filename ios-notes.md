# iOS

# Objective C


http://clang.llvm.org/docs/AutomaticReferenceCounting.html

Exceptions are unsafe: http://stackoverflow.com/questions/4648952/objective-c-exceptions

http://it.toolbox.com/blogs/macsploitation/extending-classes-in-objectivec-with-categories-27447

## Libraries that attempt to unsuck ObjC (make it less glossolalic)

 * https://github.com/mikeash/MACollectionUtilities - macros for creating, mapping, filtering, and matching arrays, sets and dicts
 * https://github.com/alexch/unsuck


## SenTest

STAssert is macros

STAssertEqualObjects returns unhelpful "(" error when 2 arrays are unequal size

NSLog output is hidden - http://agilewarrior.wordpress.com/2012/02/28/where-is-nslog-output-for-ocunit-tests/

"did not finish" - http://stackoverflow.com/questions/12308297/some-of-my-unit-tests-tests-are-not-finishing-in-xcode-4-4
    - (void)tearDown
    {
        [NSThread sleepForTimeInterval:0.0];
        [super tearDown];
    }


# XCode

http://stackoverflow.com/questions/146297/hidden-features-of-xcode

Xcode > Preferences > Behaviors
  > Testing > Starts > [Show] navigator [Log Navigator]
  > Testing > Fails > Navigate to [current log]

