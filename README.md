# unsuck

<https://github.com/alexch/unsuck>

by Alex Chaffee

a collection of methods and macros that make Objective C / Cocoa easier to use for humans

see [Humane Interface](http://martinfowler.com/bliki/HumaneInterface.html) (coined by [Jef Raskin](http://en.wikipedia.org/wiki/The_Humane_Interface))

## Examples

`NSRegularExpression`:

    [NSRegularExpression from: @"regexp?"]

    [[NSRegularExpression from: @"fo*"] allMatches: "foo bar fooooo"]

    for (NSString *string in [[NSRegularExpression from: @"fo*"] allMatches: @"foo bar fooooo"]) {
        NSLog(@"%@", string); // logs "foo" and then "fooooo"
    }


## Unit Tests

Yes, there are unit tests. [Read them](unsuckTests/) for more examples.

## Notes

I'm also using this repo to hold my [notes on learning IOS and Objective C](ios-notes.md). Contains many links to things that flabbergasted me.
