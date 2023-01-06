#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace odintsov {
  class Rectangle: public Shape {
    public:
      Rectangle(double leftX, double bottomY, double rightX, double topY);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
      Rectangle* clone() const;
    private:
      rectangle_t rect;
  };
}

#endif
