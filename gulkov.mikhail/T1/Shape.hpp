#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
  virtual double getArea();
  virtual rectangle_t getFrameRect();
  virtual void move(point_t position);
  virtual void move(double dx, double dy) = 0;
};

#endif
