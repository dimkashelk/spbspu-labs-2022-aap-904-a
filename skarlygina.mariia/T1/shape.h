#ifndef SHAPE_H
#define SHAPE_H
#include "base_types.h"
class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRectangle() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(point_t position) = 0;
  virtual void scale(double k) = 0;

  virtual ~Shape() = default;
};
#endif

