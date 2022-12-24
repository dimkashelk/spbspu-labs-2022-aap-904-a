#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
 public:
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t position);
  void move(double dx, double dy);
  void scale(double k);
};

#endif
