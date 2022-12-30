#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Square: public chemodurov::Shape
  {
   public:
    Square(const chemodurov::point_t & left_down, double length);
    ~Square();
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
