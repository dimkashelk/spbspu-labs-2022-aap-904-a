#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Square: public Shape
  {
   public:
    Square(const point_t & left_down, double length);
    ~Square();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
   private:
    Polygon p;
    Square(const Polygon & p);
  };
}

#endif
