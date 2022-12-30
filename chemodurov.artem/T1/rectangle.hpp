#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Rectangle: public chemodurov::Shape
  {
   public:
    Rectangle(const chemodurov::point_t & left_down, const chemodurov::point_t & right_up);
    ~Rectangle();
    double getArea() const;
    chemodurov::rectangle_t getFrameRect() const;
    void move(const chemodurov::point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    chemodurov::Shape * clone() const;
   private:
    chemodurov::Polygon p;
  };
}

#endif
