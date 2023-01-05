#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace odintsov {
  class Triangle: public Shape {
    public:
      Triangle(const point_t& p1, const point_t& p2, const point_t& p3);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
      point_t getMiddlePoint() const;
    private:
      point_t p1, p2, p3;
  };
}

#endif
