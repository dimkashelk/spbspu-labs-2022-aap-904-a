#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

namespace kryuchkova
{
  class Circle: Shape
  {
  public:
    Circle(const point_t & pos, const double & radius);
    double getArea();
    rectangle_t getFrameRect() const;
    void move(point_t point);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
  private:
    point_t pos;
    double radius;
  };

}

#endif
