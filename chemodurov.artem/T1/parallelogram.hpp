#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "polygon.hpp"

namespace chemodurov
{
  class Parallelogram: public Shape
  {
   public:
    Parallelogram(const point_t & fst, const point_t & sec, const point_t & trd);
    ~Parallelogram();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & pos);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const;
   private:
    Polygon p;
    Parallelogram(const Polygon & pol);
  };
}

#endif
