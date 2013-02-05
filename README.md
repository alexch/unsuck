# unsuck

<https://github.com/alexch/unsuck>

by Alex Chaffee

a collection of methods and macros that make Objective C / Cocoa easier to use for humans

## Examples

    [NSRegularExpression from: @"regexp?"]

    [[NSRegularExpression from: @"fo*"] allMatches: "foo bar fooooo"]

    for (NSString *string in [[NSRegularExpression from: @"fo*"] allMatches: @"foo bar fooooo"]) {
        NSLog(@"%@", string); // logs "foo" and then "fooooo"
    }

## Unit Tests

Yes, there are unit tests. [Read them](unsuckTests/) for more examples.

