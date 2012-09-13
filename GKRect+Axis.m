//  Created by Pieter Omvlee on 20/09/2011.
//  Copyright (c) 2011 Bohemian Coding. All rights reserved.

#import "GKRect+Axis.h"
#import "GKRect+Edge.h"
#import "GKAxis.h"
#import "GKAxisPosition.h"

@implementation GKRect (Axis)

- (CGFloat)minForAxis:(GKAxis *)axis  { return axis.type == GKAxisHorizontal ? self.minX : self.minY; }
- (CGFloat)midForAxis:(GKAxis *)axis  { return axis.type == GKAxisHorizontal ? self.midX : self.midY; }
- (CGFloat)maxForAxis:(GKAxis *)axis  { return axis.type == GKAxisHorizontal ? self.maxX : self.maxY; }
- (CGFloat)sizeForAxis:(GKAxis *)axis { return axis.type == GKAxisHorizontal ? self.width : self.height; }

- (GKRect *)setMin:(CGFloat)value forAxis:(GKAxis *)axis
{
  if (axis.type == GKAxisHorizontal)
    self.x = value;
  else
    self.y = value;
  return self;
}

- (GKRect *)setMid:(CGFloat)value forAxis:(GKAxis *)axis
{
  if (axis.type == GKAxisHorizontal)
    self.x = value - self.width/2;
  else
    self.y = value - self.height/2;
  return self;
}

- (GKRect *)setMax:(CGFloat)value forAxis:(GKAxis *)axis
{
  if (axis.type == GKAxisHorizontal)
    self.x = value - self.width;
  else
    self.y = value - self.height;
  return self;
}

- (GKRect *)setSize:(CGFloat)value forAxis:(GKAxis *)axis
{
  if (axis.type == GKAxisHorizontal)
    self.width = value;
  else
    self.height = value;
  return self;
}

- (GKRect *)setSize:(CGFloat)value forAxis:(GKAxis *)axis anchoredToPosition:(GKAxisPosition *)edge
{
  GKRect *rectCopy = [self copy];
  [self setSize:value forAxis:axis];
  if (edge.type == GKAxisPositionMid)
    [self setMid:[rectCopy midForAxis:axis] forAxis:axis];
  else if (edge.type == GKAxisPositionMax)
    [self setMax:[rectCopy maxForAxis:axis] forAxis:axis];
  [rectCopy release];
  return self;
}

@end
