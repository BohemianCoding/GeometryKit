//  Created by Pieter Omvlee on 19/09/2011.
//  Copyright (c) 2014 Bohemian Coding. All rights reserved.

#import "GKRect.h"
#import "GKCorner.h"

@class GKPoint, GKOffset;

typedef GKOffset *(^BCCornerOffsetCallbackBlock)(GKCorner *corner);

static NSPoint GKRectPointForCorner(NSRect rect, GKCornerType corner) {
  switch (corner) {
    case GKCornerTopLeft:
      return NSMakePoint(NSMinX(rect), NSMinY(rect));
    case GKCornerTopRight:
      return NSMakePoint(NSMaxX(rect), NSMinY(rect));
    case GKCornerBottomLeft:
      return NSMakePoint(NSMinX(rect), NSMaxY(rect));
    case GKCornerBottomRight:
      return NSMakePoint(NSMaxX(rect), NSMaxY(rect));
    case GKCornerMidTop:
      return NSMakePoint(NSMidX(rect), NSMinY(rect));
    case GKCornerMidLeft:
      return NSMakePoint(NSMinX(rect), NSMidY(rect));
    case GKCornerMidRight:
      return NSMakePoint(NSMaxX(rect), NSMidY(rect));
    case GKCornerMidBottom:
      return NSMakePoint(NSMidX(rect), NSMaxY(rect));
    case GKCornerMid:
      return NSMakePoint(NSMidX(rect), NSMidY(rect));
    default:
      return NSZeroPoint;
  }
};

@interface GKRect (Corner)
- (GKPoint *)pointForCorner:(GKCorner *)corner;
- (NSArray *)pointsForCorners:(NSArray *)corners;

- (GKRect *)moveCorner:(GKCorner *)corner toPoint:(GKPoint *)point;
- (GKRect *)resizeByPuttingCorner:(GKCorner *)corner atPoint:(GKPoint *)point;
- (GKCorner *)closestCornerForPoint:(GKPoint *)point withMargin:(CGFloat)margin;
- (GKCorner *)closestCornerForPoint:(GKPoint *)point withMargin:(CGFloat)margin satisfyingMask:(NSUInteger)cornerMask;
- (GKCorner *)closestCornerForPoint:(GKPoint *)point marginCallback:(BCCornerOffsetCallbackBlock)marginBlock;
- (GKRect *)snapToRects:(NSArray *)rects withMargin:(CGFloat)margin;

- (GKOffset *)distanceFromCornerToMid:(GKCorner *)corner;
@end
