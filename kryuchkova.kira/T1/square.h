#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

namespace kryuchkova
{
  class Square: Shape
  {
  public:
    Square(const point_t & lb_point, const double & length);
    double getArea();
    rectangle_t getFrameRect() const;
    void move(point_t point);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
  private:
    point_t lb_point;
    double length;
  };

}

#endif
