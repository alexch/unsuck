/* Generated from CGContext.h */

#include <CoreGraphics/CGContext.h>

@interface CGCanvas : NSObject

+(CGCanvas *)current;
@property (nonatomic) CGContextRef context;

-(id)initWithContext: (CGContextRef)context;

/* Push a copy of the current graphics state onto the graphics state stack.
   Note that the path is not considered part of the graphics state, and is
   not saved.
   Wraps CGContextSaveGState. */
-(void) saveGState;

/* Restore the current graphics state from the one on the top of the
   graphics state stack, popping the graphics state stack in the process.
   Wraps CGContextRestoreGState. */
-(void) restoreGState;

/* Scale the current graphics state's transformation matrix (the CTM) by
   `(sx, sy)'.
   Wraps CGContextScaleCTM. */
-(void) scaleCTM_sx:(CGFloat)sx sy:(CGFloat)sy;

/* Translate the current graphics state's transformation matrix (the CTM) by
   `(tx, ty)'.
   Wraps CGContextTranslateCTM. */
-(void) translateCTM_tx:(CGFloat)tx ty:(CGFloat)ty;

/* Rotate the current graphics state's transformation matrix (the CTM) by
   `angle' radians.
   Wraps CGContextRotateCTM. */
-(void) rotateCTM: (CGFloat)angle;

/* Concatenate the current graphics state's transformation matrix (the CTM)
   with the affine transform `transform'.
   Wraps CGContextConcatCTM. */
-(void) concatCTM: (CGAffineTransform)transform;

/* Return the current graphics state's transformation matrix.
   Wraps CGContextGetCTM. */
-(CGAffineTransform) getCTM;

/* Set the line width in the current graphics state to `width'.
   Wraps CGContextSetLineWidth. */
-(void) setLineWidth: (CGFloat)width;

/* Set the line cap in the current graphics state to `cap'.
   Wraps CGContextSetLineCap. */
-(void) setLineCap: (CGLineCap)cap;

/* Set the line join in the current graphics state to `join'.
   Wraps CGContextSetLineJoin. */
-(void) setLineJoin: (CGLineJoin)join;

/* Set the miter limit in the current graphics state to `limit'.
   Wraps CGContextSetMiterLimit. */
-(void) setMiterLimit: (CGFloat)limit;

/* Set the line dash patttern in the current graphics state of `c'.
   Wraps CGContextSetLineDash. */
-(void) setLineDash_phase:(CGFloat)phase lengths:(const CGFloat [])lengths count:(size_t)count;

/* Set the path flatness parameter in the current graphics state of `c' to
   `flatness'.
   Wraps CGContextSetFlatness. */
-(void) setFlatness: (CGFloat)flatness;

/* Set the alpha value in the current graphics state of `c' to `alpha'.
   Wraps CGContextSetAlpha. */
-(void) setAlpha: (CGFloat)alpha;

/* Set the blend mode of `context' to `mode'.
   Wraps CGContextSetBlendMode. */
-(void) setBlendMode: (CGBlendMode)mode;

/* Begin a new path. The old path is discarded.
   Wraps CGContextBeginPath. */
-(void) beginPath;

/* Start a new subpath at point `(x, y)' in the context's path.
   Wraps CGContextMoveToPoint. */
-(void) moveToPoint_x:(CGFloat)x y:(CGFloat)y;

/* Append a straight line segment from the current point to `(x, y)'.
   Wraps CGContextAddLineToPoint. */
-(void) addLineToPoint_x:(CGFloat)x y:(CGFloat)y;

/* Append a cubic Bezier curve from the current point to `(x,y)', with
   control points `(cp1x, cp1y)' and `(cp2x, cp2y)'.
   Wraps CGContextAddCurveToPoint. */
-(void) addCurveToPoint_cp1x:(CGFloat)cp1x cp1y:(CGFloat)cp1y cp2x:(CGFloat)cp2x cp2y:(CGFloat)cp2y x:(CGFloat)x y:(CGFloat)y;

/* Append a quadratic curve from the current point to `(x, y)', with control
   point `(cpx, cpy)'.
   Wraps CGContextAddQuadCurveToPoint. */
-(void) addQuadCurveToPoint_cpx:(CGFloat)cpx cpy:(CGFloat)cpy x:(CGFloat)x y:(CGFloat)y;

/* Close the current subpath of the context's path.
   Wraps CGContextClosePath. */
-(void) closePath;

/* Add a single rect to the context's path.
   Wraps CGContextAddRect. */
-(void) addRect: (CGRect)rect;

/* Add a set of rects to the context's path.
   Wraps CGContextAddRects. */
-(void) addRects:(const CGRect [])rects count:(size_t)count;

/* Add a set of lines to the context's path.
   Wraps CGContextAddLines. */
-(void) addLines_points:(const CGPoint [])points count:(size_t)count;

/* Add an ellipse inside `rect' to the current path of `context'. See the
   function `CGPathAddEllipseInRect' for more information on how the path
   for the ellipse is constructed.
   Wraps CGContextAddEllipseInRect. */
-(void) addEllipseInRect: (CGRect)rect;

/* Add an arc of a circle to the context's path, possibly preceded by a
   straight line segment. `(x, y)' is the center of the arc; `radius' is its
   radius; `startAngle' is the angle to the first endpoint of the arc;
   `endAngle' is the angle to the second endpoint of the arc; and
   `clockwise' is 1 if the arc is to be drawn clockwise, 0 otherwise.
   `startAngle' and `endAngle' are measured in radians.
   Wraps CGContextAddArc. */
-(void) addArc_x:(CGFloat)x y:(CGFloat)y radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(int)clockwise;

/* Add an arc of a circle to the context's path, possibly preceded by a
   straight line segment. `radius' is the radius of the arc. The arc is
   tangent to the line from the current point to `(x1, y1)', and the line
   from `(x1, y1)' to `(x2, y2)'.
   Wraps CGContextAddArcToPoint. */
-(void) addArcToPoint_x1:(CGFloat)x1 y1:(CGFloat)y1 x2:(CGFloat)x2 y2:(CGFloat)y2 radius:(CGFloat)radius;

/* Add `path' to the path of context. The points in `path' are transformed
   by the CTM of context before they are added.
   Wraps CGContextAddPath. */
-(void) addPath: (CGPathRef)path;

/* Replace the path in `context' with the stroked version of the path, using
   the parameters of `context' to calculate the stroked path. The resulting
   path is created such that filling it with the appropriate color will
   produce the same results as stroking the original path. You can use this
   path in the same way you can use the path of any context; for example,
   you can clip to the stroked version of a path by calling this function
   followed by a call to "CGContextClip".
   Wraps CGContextReplacePathWithStrokedPath. */
-(void) replacePathWithStrokedPath;

/* Return true if the path of `context' contains no elements, false
   otherwise.
   Wraps CGContextIsPathEmpty. */
-(bool) isPathEmpty;

/* Return the current point of the current subpath of the path of
   `context'.
   Wraps CGContextGetPathCurrentPoint. */
-(CGPoint) getPathCurrentPoint;

/* Return the bounding box of the path of `context'. The bounding box is the
   smallest rectangle completely enclosing all points in the path, including
   control points for Bezier and quadratic curves.
   Wraps CGContextGetPathBoundingBox. */
-(CGRect) getPathBoundingBox;

/* Return a copy of the path of `context'. The returned path is specified in
   the current user space of `context'.
   Wraps CGContextCopyPath. */
-(CGPathRef) copyPath;

/* Return true if `point' is contained in the current path of `context'. A
   point is contained within a context's path if it is inside the painted
   region when the path is stroked or filled with opaque colors using the
   path drawing mode `mode'. `point' is specified is user space.
   Wraps CGContextPathContainsPoint. */
-(bool) pathContainsPoint:(CGPoint)point mode:(CGPathDrawingMode)mode;

/* Draw the context's path using drawing mode `mode'.
   Wraps CGContextDrawPath. */
-(void) drawPath: (CGPathDrawingMode)mode;

/* Fill the context's path using the winding-number fill rule. Any open
   subpath of the path is implicitly closed.
   Wraps CGContextFillPath. */
-(void) fillPath;

/* Fill the context's path using the even-odd fill rule. Any open subpath of
   the path is implicitly closed.
   Wraps CGContextEOFillPath. */
-(void) eOFillPath;

/* Stroke the context's path.
   Wraps CGContextStrokePath. */
-(void) strokePath;

/* Fill `rect' with the current fill color.
   Wraps CGContextFillRect. */
-(void) fillRect: (CGRect)rect;

/* Fill `rects', an array of `count' CGRects, with the current fill
   color.
   Wraps CGContextFillRects. */
-(void) fillRects:(const CGRect [])rects count:(size_t)count;

/* Stroke `rect' with the current stroke color and the current linewidth.
   Wraps CGContextStrokeRect. */
-(void) strokeRect: (CGRect)rect;

/* Stroke `rect' with the current stroke color, using `width' as the the
   line width.
   Wraps CGContextStrokeRectWithWidth. */
-(void) strokeRectWithWidth_rect:(CGRect)rect width:(CGFloat)width;

/* Clear `rect' (that is, set the region within the rect to transparent).
   Wraps CGContextClearRect. */
-(void) clearRect: (CGRect)rect;

/* Fill an ellipse (an oval) inside `rect'.
   Wraps CGContextFillEllipseInRect. */
-(void) fillEllipseInRect: (CGRect)rect;

/* Stroke an ellipse (an oval) inside `rect'.
   Wraps CGContextStrokeEllipseInRect. */
-(void) strokeEllipseInRect: (CGRect)rect;

/* Stroke a sequence of line segments one after another in `context'. The
   line segments are specified by `points', an array of `count' CGPoints.
   This function is equivalent to

     CGContextBeginPath(context);
     for (k = 0; k < count; k += 2) {
       CGContextMoveToPoint(context, s[k].x, s[k].y);
       CGContextAddLineToPoint(context, s[k+1].x, s[k+1].y);
     }
     CGContextStrokePath(context);
   Wraps CGContextStrokeLineSegments. */
-(void) strokeLineSegments_points:(const CGPoint [])points count:(size_t)count;

/* Intersect the context's path with the current clip path and use the
   resulting path as the clip path for subsequent rendering operations. Use
   the winding-number fill rule for deciding what's inside the path.
   Wraps CGContextClip. */
-(void) clip;

/* Intersect the context's path with the current clip path and use the
   resulting path as the clip path for subsequent rendering operations. Use
   the even-odd fill rule for deciding what's inside the path.
   Wraps CGContextEOClip. */
-(void) eOClip;

/* Add `mask' transformed to `rect' to the clipping area of `context'. The
   mask, which may be either an image mask or an image, is mapped into the
   specified rectangle and intersected with the current clipping area of the
   context.

   If `mask' is an image mask, then it clips in a manner identical to the
   behavior if it were used with "CGContextDrawImage": it indicates an area
   to be masked out (left unchanged) when drawing. The source samples of the
   image mask determine which points of the clipping area are changed,
   acting as an "inverse alpha": if the value of a source sample in the
   image mask is S, then the corresponding point in the current clipping
   area will be multiplied by an alpha of (1-S). (For example, if S is 1,
   then the point in the clipping area becomes clear, while if S is 0, the
   point in the clipping area is unchanged.

   If `mask' is an image, then it serves as alpha mask and is blended with
   the current clipping area. The source samples of mask determine which
   points of the clipping area are changed: if the value of the source
   sample in mask is S, then the corresponding point in the current clipping
   area will be multiplied by an alpha of S. (For example, if S is 0, then
   the point in the clipping area becomes clear, while if S is 1, the point
   in the clipping area is unchanged.

   If `mask' is an image, then it must be in the DeviceGray color space, may
   not have alpha, and may not be masked by an image mask or masking
   color.
   Wraps CGContextClipToMask. */
-(void) clipToMask_rect:(CGRect)rect mask:(CGImageRef)mask;

/* Return the bounding box of the clip path of `c' in user space. The
   bounding box is the smallest rectangle completely enclosing all points in
   the clip.
   Wraps CGContextGetClipBoundingBox. */
-(CGRect) getClipBoundingBox;

/* Intersect the current clipping path with `rect'. Note that this function
   resets the context's path to the empty path.
   Wraps CGContextClipToRect. */
-(void) clipToRect: (CGRect)rect;

/* Intersect the current clipping path with the clipping region formed by
   creating a path consisting of all rects in `rects'. Note that this
   function resets the context's path to the empty path.
   Wraps CGContextClipToRects. */
-(void) clipToRects:(const CGRect [])rects count:(size_t)count;

/* Set the current fill color in the context `c' to `color'.
   Wraps CGContextSetFillColorWithColor. */
-(void) setFillColorWithColor: (CGColorRef)color;

/* Set the current stroke color in the context `c' to `color'.
   Wraps CGContextSetStrokeColorWithColor. */
-(void) setStrokeColorWithColor: (CGColorRef)color;

/* Set the current fill color space in `context' to `space'. As a
   side-effect, set the fill color to a default value appropriate for the
   color space.
   Wraps CGContextSetFillColorSpace. */
-(void) setFillColorSpace: (CGColorSpaceRef)space;

/* Set the current stroke color space in `context' to `space'. As a
   side-effect, set the stroke color to a default value appropriate for the
   color space.
   Wraps CGContextSetStrokeColorSpace. */
-(void) setStrokeColorSpace: (CGColorSpaceRef)space;

/* Set the components of the current fill color in `context' to the values
   specifed by `components'. The number of elements in `components' must be
   one greater than the number of components in the current fill color space
   (N color components + 1 alpha component). The current fill color space
   must not be a pattern color space.
   Wraps CGContextSetFillColor. */
-(void) setFillColor: (const CGFloat [])components;

/* Set the components of the current stroke color in `context' to the values
   specifed by `components'. The number of elements in `components' must be
   one greater than the number of components in the current stroke color
   space (N color components + 1 alpha component). The current stroke color
   space must not be a pattern color space.
   Wraps CGContextSetStrokeColor. */
-(void) setStrokeColor: (const CGFloat [])components;

/* Set the components of the current fill color in `context' to the values
   specifed by `components', and set the current fill pattern to `pattern'.
   The number of elements in `components' must be one greater than the
   number of components in the current fill color space (N color components
   + 1 alpha component). The current fill color space must be a pattern
   color space.
   Wraps CGContextSetFillPattern. */
-(void) setFillPattern:(CGPatternRef)pattern components:(const CGFloat [])components;

/* Set the components of the current stroke color in `context' to the values
   specifed by `components', and set the current stroke pattern to
   `pattern'. The number of elements in `components' must be one greater
   than the number of components in the current stroke color space (N color
   components + 1 alpha component). The current stroke color space must be a
   pattern color space.
   Wraps CGContextSetStrokePattern. */
-(void) setStrokePattern:(CGPatternRef)pattern components:(const CGFloat [])components;

/* Set the pattern phase in the current graphics state of `context' to
   `phase'.
   Wraps CGContextSetPatternPhase. */
-(void) setPatternPhase: (CGSize)phase;

/* Set the current fill color space in `context' to `DeviceGray' and set the
   components of the current fill color to `(gray, alpha)'.
   Wraps CGContextSetGrayFillColor. */
-(void) setGrayFillColor_gray:(CGFloat)gray alpha:(CGFloat)alpha;

/* Set the current stroke color space in `context' to `DeviceGray' and set
   the components of the current stroke color to `(gray, alpha)'.
   Wraps CGContextSetGrayStrokeColor. */
-(void) setGrayStrokeColor_gray:(CGFloat)gray alpha:(CGFloat)alpha;

/* Set the current fill color space in `context' to `DeviceRGB' and set the
   components of the current fill color to `(red, green, blue, alpha)'.
   Wraps CGContextSetRGBFillColor. */
-(void) setRGBFillColor_red:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

/* Set the current stroke color space in `context' to `DeviceRGB' and set
   the components of the current stroke color to `(red, green, blue,
   alpha)'.
   Wraps CGContextSetRGBStrokeColor. */
-(void) setRGBStrokeColor_red:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

/* Set the current fill color space in `context' to `DeviceCMYK' and set the
   components of the current fill color to `(cyan, magenta, yellow, black,
   alpha)'.
   Wraps CGContextSetCMYKFillColor. */
-(void) setCMYKFillColor_cyan:(CGFloat)cyan magenta:(CGFloat)magenta yellow:(CGFloat)yellow black:(CGFloat)black alpha:(CGFloat)alpha;

/* Set the current stroke color space in `context' to `DeviceCMYK' and set
   the components of the current stroke color to `(cyan, magenta, yellow,
   black, alpha)'.
   Wraps CGContextSetCMYKStrokeColor. */
-(void) setCMYKStrokeColor_cyan:(CGFloat)cyan magenta:(CGFloat)magenta yellow:(CGFloat)yellow black:(CGFloat)black alpha:(CGFloat)alpha;

/* Set the rendering intent in the current graphics state of `context' to
   `intent'.
   Wraps CGContextSetRenderingIntent. */
-(void) setRenderingIntent: (CGColorRenderingIntent)intent;

/* Draw `image' in the rectangular area specified by `rect' in the context
   `c'. The image is scaled, if necessary, to fit into `rect'.
   Wraps CGContextDrawImage. */
-(void) drawImage_rect:(CGRect)rect image:(CGImageRef)image;

/* Draw `image' tiled in the context `c'. The image is scaled to the size
   specified by `rect' in user space, positioned at the origin of `rect' in
   user space, then replicated, stepping the width of `rect' horizontally
   and the height of `rect' vertically, to fill the current clip region.
   Unlike patterns, the image is tiled in user space, so transformations
   applied to the CTM affect the final result.
   Wraps CGContextDrawTiledImage. */
-(void) drawTiledImage_rect:(CGRect)rect image:(CGImageRef)image;

/* Return the interpolation quality for image rendering of `context'. The
   interpolation quality is a gstate parameter which controls the level of
   interpolation performed when an image is interpolated (for example, when
   scaling the image). Note that it is merely a hint to the context: not all
   contexts support all interpolation quality levels.
   Wraps CGContextGetInterpolationQuality. */
-(CGInterpolationQuality) getInterpolationQuality;

/* Set the interpolation quality of `context' to `quality'.
   Wraps CGContextSetInterpolationQuality. */
-(void) setInterpolationQuality: (CGInterpolationQuality)quality;

/* Set the shadow parameters in `context'. `offset' specifies a translation
   in base-space; `blur' is a non-negative number specifying the amount of
   blur; `color' specifies the color of the shadow, which may contain a
   non-opaque alpha value. If `color' is NULL, it's equivalent to specifying
   a fully transparent color. The shadow is a gstate parameter. After a
   shadow is specified, all objects drawn subsequently will be shadowed. To
   turn off shadowing, set the shadow color to a fully transparent color (or
   pass NULL as the color), or use the standard gsave/grestore mechanism.
   Wraps CGContextSetShadowWithColor. */
-(void) setShadowWithColor_offset:(CGSize)offset blur:(CGFloat)blur color:(CGColorRef)color;

/* Equivalent to calling
     CGContextSetShadowWithColor(context, offset, blur, color)
   where color is black with 1/3 alpha (i.e., RGBA = {0, 0, 0, 1.0/3.0}) in
   the DeviceRGB color space.
   Wraps CGContextSetShadow. */
-(void) setShadow_offset:(CGSize)offset blur:(CGFloat)blur;

/* Fill the current clipping region of `context' with a linear gradient from
   `startPoint' to `endPoint'. The location 0 of `gradient' corresponds to
   `startPoint'; the location 1 of `gradient' corresponds to `endPoint';
   colors are linearly interpolated between these two points based on the
   values of the gradient's locations. The option flags control whether the
   gradient is drawn before the start point or after the end point.
   Wraps CGContextDrawLinearGradient. */
-(void) drawLinearGradient:(CGGradientRef)gradient startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint options:(CGGradientDrawingOptions)options;

/* Fill the current clipping region of `context' with a radial gradient
   between two circles defined by the center point and radius of each
   circle. The location 0 of `gradient' corresponds to a circle centered at
   `startCenter' with radius `startRadius'; the location 1 of `gradient'
   corresponds to a circle centered at `endCenter' with radius `endRadius';
   colors are linearly interpolated between these two circles based on the
   values of the gradient's locations. The option flags control whether the
   gradient is drawn before the start circle or after the end circle.
   Wraps CGContextDrawRadialGradient. */
-(void) drawRadialGradient:(CGGradientRef)gradient startCenter:(CGPoint)startCenter startRadius:(CGFloat)startRadius endCenter:(CGPoint)endCenter endRadius:(CGFloat)endRadius options:(CGGradientDrawingOptions)options;

/* Fill the current clipping region of `context' with `shading'.
   Wraps CGContextDrawShading. */
-(void) drawShading: (CGShadingRef)shading;

/* Set the current character spacing in `context' to `spacing'. The
   character spacing is added to the displacement between the origin of one
   character and the origin of the next.
   Wraps CGContextSetCharacterSpacing. */
-(void) setCharacterSpacing: (CGFloat)spacing;

/* Set the user-space point at which text will be drawn in the context `c'
   to `(x, y)'.
   Wraps CGContextSetTextPosition. */
-(void) setTextPosition_x:(CGFloat)x y:(CGFloat)y;

/* Return the user-space point at which text will be drawn in `context'.
   Wraps CGContextGetTextPosition. */
-(CGPoint) getTextPosition;

/* Set the text matrix in the context `c' to `t'.
   Wraps CGContextSetTextMatrix. */
-(void) setTextMatrix: (CGAffineTransform)t;

/* Return the text matrix in the context `c'.
   Wraps CGContextGetTextMatrix. */
-(CGAffineTransform) getTextMatrix;

/* Set the text drawing mode in the current graphics state of the context
   `c' to `mode'.
   Wraps CGContextSetTextDrawingMode. */
-(void) setTextDrawingMode: (CGTextDrawingMode)mode;

/* Set the font in the current graphics state of the context `c' to
   `font'.
   Wraps CGContextSetFont. */
-(void) setFont: (CGFontRef)font;

/* Set the font size in the current graphics state of the context `c' to
   `size'.
   Wraps CGContextSetFontSize. */
-(void) setFontSize: (CGFloat)size;

/* Attempts to find the font named `name' and, if successful, sets it as the
   font in the current graphics state of `c' and sets the font size in the
   current graphics state to `size'. `textEncoding' specifies how to
   translate from bytes to glyphs when displaying text.
   Wraps CGContextSelectFont. */
-(void) selectFont_name:(const char *)name size:(CGFloat)size textEncoding:(CGTextEncoding)textEncoding;

/* Draw `glyphs', an array of `count' CGGlyphs, at the points specified by
   `positions'. Each element of `positions' specifies the position from the
   associated glyph; the positions are specified in user space.
   Wraps CGContextShowGlyphsAtPositions. */
-(void) showGlyphsAtPositions_glyphs:(const CGGlyph [])glyphs positions:(const CGPoint [])positions count:(size_t)count;

/* Draw `string', a string of `length' bytes, at the point specified by the
   text matrix in the context `c'. Each byte of the string is mapped through
   the encoding vector of the current font to obtain the glyph to
   display.
   Wraps CGContextShowText. */
-(void) showText_string:(const char *)string length:(size_t)length;

/* Draw `string', a string of `length' bytes, at the point `(x, y)',
   specified in user space, in the context `c'. Each byte of the string is
   mapped through the encoding vector of the current font to obtain the
   glyph to display.
   Wraps CGContextShowTextAtPoint. */
-(void) showTextAtPoint_x:(CGFloat)x y:(CGFloat)y string:(const char *)string length:(size_t)length;

/* Draw the glyphs pointed to by `g', an array of `count' glyphs, at the
   point specified by the text matrix in the context `c'.
   Wraps CGContextShowGlyphs. */
-(void) showGlyphs_g:(const CGGlyph [])g count:(size_t)count;

/* Display the glyphs pointed to by `glyphs', an array of `count' glyphs, at
   the point `(x, y)', specified in user space, in `context'.
   Wraps CGContextShowGlyphsAtPoint. */
-(void) showGlyphsAtPoint_x:(CGFloat)x y:(CGFloat)y glyphs:(const CGGlyph [])glyphs count:(size_t)count;

/* Draw `glyphs', an array of `count' CGGlyphs, at the current point
   specified by the text matrix. Each element of `advances' specifies the
   offset from the previous glyph's origin to the origin of the associated
   glyph; the advances are specified in user space.
   Wraps CGContextShowGlyphsWithAdvances. */
-(void) showGlyphsWithAdvances_glyphs:(const CGGlyph [])glyphs advances:(const CGSize [])advances count:(size_t)count;

/* Draw `page' in the current user space of the context `c'.
   Wraps CGContextDrawPDFPage. */
-(void) drawPDFPage: (CGPDFPageRef)page;

/* Begin a new page.
   Wraps CGContextBeginPage. */
-(void) beginPage: (const CGRect *)mediaBox;

/* End the current page.
   Wraps CGContextEndPage. */
-(void) endPage;

/* Flush all drawing to the destination.
   Wraps CGContextFlush. */
-(void) flush;

/* Synchronized drawing.
   Wraps CGContextSynchronize. */
-(void) synchronize;

/* Turn on antialiasing if `shouldAntialias' is true; turn it off otherwise.
   This parameter is part of the graphics state.
   Wraps CGContextSetShouldAntialias. */
-(void) setShouldAntialias: (bool)shouldAntialias;

/* Allow antialiasing in `context' if `allowsAntialiasing' is true; don't
   allow it otherwise. This parameter is not part of the graphics state. A
   context will perform antialiasing if both `allowsAntialiasing' and the
   graphics state parameter `shouldAntialias' are true.
   Wraps CGContextSetAllowsAntialiasing. */
-(void) setAllowsAntialiasing: (bool)allowsAntialiasing;

/* Turn on font smoothing if `shouldSmoothFonts' is true; turn it off
   otherwise. This parameter is part of the graphics state. Note that this
   doesn't guarantee that font smoothing will occur: not all destination
   contexts support font smoothing.
   Wraps CGContextSetShouldSmoothFonts. */
-(void) setShouldSmoothFonts: (bool)shouldSmoothFonts;

/* If `allowsFontSmoothing' is true, then allow font smoothing when
   displaying text in `context'; otherwise, don't allow font smoothing. This
   parameter is not part of the graphics state. Fonts will be smoothed if
   they are antialiased when drawn and if both `allowsFontSmoothing' and the
   graphics state parameter `shouldSmoothFonts' are true.
   Wraps CGContextSetAllowsFontSmoothing. */
-(void) setAllowsFontSmoothing: (bool)allowsFontSmoothing;

/* If `shouldSubpixelPositionFonts' is true, then glyphs may be placed at
   subpixel positions (if allowed) when displaying text in `context';
   otherwise, glyphs will be forced to integer pixel boundaries. This
   parameter is part of the graphics state.
   Wraps CGContextSetShouldSubpixelPositionFonts. */
-(void) setShouldSubpixelPositionFonts: (bool)shouldSubpixelPositionFonts;

/* If `allowsFontSubpixelPositioning' is true, then allow font subpixel
   positioning when displaying text in `context'; otherwise, don't allow
   subpixel positioning. This parameter is not part of the graphics state. A
   context will place glyphs at subpixel positions if fonts will be
   antialiased when drawn and if both `allowsFontSubpixelPositioning' and
   the graphics state parameter `shouldSubpixelPositionFonts' are true.
   Wraps CGContextSetAllowsFontSubpixelPositioning. */
-(void) setAllowsFontSubpixelPositioning: (bool)allowsFontSubpixelPositioning;

/* If `shouldSubpixelQuantizeFonts' is true, then quantize the subpixel
   positions of glyphs when displaying text in `context'; otherwise, don't
   quantize the subpixel positions. This parameter is part of the graphics
   state.
   Wraps CGContextSetShouldSubpixelQuantizeFonts. */
-(void) setShouldSubpixelQuantizeFonts: (bool)shouldSubpixelQuantizeFonts;

/* If `allowsFontSubpixelQuantization' is true, then allow font subpixel
   quantization when displaying text in `context'; otherwise, don't allow
   subpixel quantization. This parameter is not part of the graphics state.
   A context quantizes subpixel positions if glyphs will be drawn at
   subpixel positions and `allowsFontSubpixelQuantization' and the graphics
   state parameter `shouldSubpixelQuantizeFonts' are both true.
   Wraps CGContextSetAllowsFontSubpixelQuantization. */
-(void) setAllowsFontSubpixelQuantization: (bool)allowsFontSubpixelQuantization;

/* Begin a transparency layer in `context'. All subsequent drawing
   operations until a corresponding `CGContextEndTransparencyLayer' are
   composited into a fully transparent backdrop (which is treated as a
   separate destination buffer from the context). After the transparency
   layer is ended, the result is composited into the context using the
   global alpha and shadow state of the context. This operation respects the
   clipping region of the context. After a call to this function, all of the
   parameters in the graphics state remain unchanged with the exception of
   the following:
     - The global alpha is set to 1.
     - The shadow is turned off.
     - The blend mode is set to `kCGBlendModeNormal'.
   Ending the transparency layer restores these parameters to the values
   they had before `CGContextBeginTransparencyLayer' was called.
   Transparency layers may be nested.
   Wraps CGContextBeginTransparencyLayer. */
-(void) beginTransparencyLayer: (CFDictionaryRef)auxiliaryInfo;

/* Begin a transparency layer in `context'. This function is identical to
  `CGContextBeginTransparencyLayer' except that the content of the
  transparency layer will be bounded by `rect' (specified in user space).
   Wraps CGContextBeginTransparencyLayerWithRect. */
-(void) beginTransparencyLayerWithRect:(CGRect)rect auxiliaryInfo:(CFDictionaryRef)auxiliaryInfo;

/* End a tranparency layer.
   Wraps CGContextEndTransparencyLayer. */
-(void) endTransparencyLayer;

/* Return the affine transform mapping the user space (abstract coordinates)
   of `context' to device space (pixels).
   Wraps CGContextGetUserSpaceToDeviceSpaceTransform. */
-(CGAffineTransform) getUserSpaceToDeviceSpaceTransform;

/* Transform `point' from the user space of `context' to device space.
   Wraps CGContextConvertPointToDeviceSpace. */
-(CGPoint) convertPointToDeviceSpace: (CGPoint)point;

/* Transform `point' from device space to the user space of `context'.
   Wraps CGContextConvertPointToUserSpace. */
-(CGPoint) convertPointToUserSpace: (CGPoint)point;

/* Transform `size' from the user space of `context' to device space.
   Wraps CGContextConvertSizeToDeviceSpace. */
-(CGSize) convertSizeToDeviceSpace: (CGSize)size;

/* Transform `size' from device space to the user space of `context'.
   Wraps CGContextConvertSizeToUserSpace. */
-(CGSize) convertSizeToUserSpace: (CGSize)size;

/* Transform `rect' from the user space of `context' to device space. Since
   affine transforms do not preserve rectangles in general, this function
   returns the smallest rectangle which contains the transformed corner
   points of `rect'.
   Wraps CGContextConvertRectToDeviceSpace. */
-(CGRect) convertRectToDeviceSpace: (CGRect)rect;

/* Transform `rect' from device space to the user space of `context'. Since
   affine transforms do not preserve rectangles in general, this function
   returns the smallest rectangle which contains the transformed corner
   points of `rect'.
   Wraps CGContextConvertRectToUserSpace. */
-(CGRect) convertRectToUserSpace: (CGRect)rect;


@end
