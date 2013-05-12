#!/usr/bin/env ruby

input = File.read("/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk/System/Library/Frameworks/CoreGraphics.framework/Headers/CGContext.h")
output_dir = "#{File.dirname(__FILE__)/unsuck"

# split into sections delineated by /* comments
sections = input.split(/^\/\* /)

headers = []
impls = []

sections.each do |section|
    next unless section =~ /^(^CG_EXTERN)/m
    puts "----"

    pattern = /\A
    (?<comment>.*)\*\/    # comment
    \s*
    ^CG_EXTERN
    \s*
    (?<returns>\w*)\b       # return type
    \s*
    (?<name>\w*)\b          # function name
    \(
      (?<params>[^\)]*)    # all parameters
    \)
    /mx

    matches = pattern.match(section)
    matches.names.each do |name|
        puts "#{name}:\t#{matches[name]}"
    end

    next if ["CGContextDrawPDFDocument", "CGContextGetTypeID", "CGContextRetain", "CGContextRelease"].include? matches[:name]  # skip void/missing methods

    name = matches[:name].dup
    name["CGContext"] = ""  # lame, but minus doesn't work on strings
    name[0] = name[0].downcase

    params = matches[:params].split(',').map(&:strip)
    params.shift  # get rid of initial CGContextRef param

    params = params.map do |s|
        param_type = ""
        if s =~ /\[\]$/
            param_type = "[]"
            s["[]"] = ""
        end
        param_name = s.match(/\w*$/)[0]
        s[param_name] = ""
        param_type = s + param_type

        {type: param_type.strip, name: param_name}
    end

    signature = "-(#{matches[:returns]}) #{name}"
    if params.empty?
    elsif params.length == 1
        param = params.first
        signature += ": (#{param[:type]})#{param[:name]}"
    else
        skip_name = false
        if name =~ /#{params.first[:name]}$/i
            skip_name = true
        else
            signature += "_"  # should probably be "with"
        end
        signature += params.map do |param|
            param_name = param[:name] unless skip_name
            skip_name = false
            "#{param_name}:(#{param[:type]})#{param[:name]}"
        end.join(" ")
    end

    header = <<-CODE
/* #{matches[:comment]}
   Wraps #{matches[:name]}. */
#{signature};
    CODE
    headers << header

    call_params = [{type: "CGContextRef", name: "_context"}] + params;
    call = "#{matches[:name]}(" +
        call_params.map{|p|p[:name]}.join(", ") +
        ")"
    impl = <<-CODE
/* #{matches[:comment]} */
#{signature}
{
    #{"return " if matches[:returns] != 'void'}#{call};
}
    CODE
    impls << impl


end

header_file = "#{output_dir}/CGCanvas.h"
File.open(header_file, 'w') {|f| f.write(<<-CODE)}
/* Generated from CGContext.h */

#include <CoreGraphics/CGContext.h>

@interface CGCanvas : NSObject

+(CGCanvas *)current;

@property (nonatomic) CGContextRef context;

-(id)initWithContext: (CGContextRef)context;

#{headers.join("\n")}

@end
CODE

impl_file = "#{output_dir}/CGCanvas.m"
File.open(impl_file, 'w') {|f| f.write(<<-CODE)}
/* Generated from CGContext.h */

#import "CGCanvas.h"
#import <UIKit/UIGraphics.h>

@implementation CGCanvas

CGContextRef _context;

+(CGCanvas *)current
{
    return [[CGCanvas alloc] initWithContext:UIGraphicsGetCurrentContext()];
}

-(id)initWithContext: (CGContextRef)context
{
	if( (self=[super init]) ) {
        self.context = context;
    }
    return self;
}

#{impls.join("\n")}

@end
CODE
