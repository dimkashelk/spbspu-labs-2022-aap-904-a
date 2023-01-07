#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace kryuchkova
{
  class Rectangle: Shape
  {
  public:
    Rectangle(const point_t &lb_point, const point_t &ru_point);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    //Shape *clone() const;
  private:
    point_t lb_point;
    point_t ru_point;
  };

}

#endif
