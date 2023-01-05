#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace odintsov {
  class Concave: public Shape {
    public:
      Concave(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
    private:
      point_t p1, p2, p3, p4;
  };
}

#endif
