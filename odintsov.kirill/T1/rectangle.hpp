#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace odintsov {
  class Rectangle: public Shape {
    public:
      Rectangle(double x, double y, double width, double height);
      Rectangle(const point_t& pos, double width, double height);
      explicit Rectangle(const rectangle_t& rect);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
    private:
      rectangle_t rect;
  };
}

#endif
