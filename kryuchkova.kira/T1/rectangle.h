#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace kryuchkova
{
  class Rectangle: Shape
  {
  public:
    Rectangle(const point_t & lb_point, const point_t & ru_point);
    double getArea();
    rectangle_t getFrameRect() const;
    void move(point_t point);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
  };
}

#endif
