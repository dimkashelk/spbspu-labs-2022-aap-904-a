#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace chemodurov
{
  class Rectangle: public chemodurov::Shape
  {
   public:
    double getArea() const;
    chemodurov::rectangle_t getFrameRect() const;
    void move(chemodurov::point_t position);
    void move(double dx, double dy);
    void scale(double k);
   private:
    
  };
}

#endif
