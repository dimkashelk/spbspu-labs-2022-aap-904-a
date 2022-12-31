#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Rectangle: public Shape
  {
   public:
    Rectangle(const point_t & left_down, const point_t & right_up);
    ~Rectangle();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
   private:
    Polygon p;
    Rectangle(const Polygon & p);
  };
}

#endif
