#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
namespace tarasenko
{
  class Complexquad: public Shape
  {
  public:
   Complexquad(point_t point_1, point_t point_2, point_t point_3, point_t point_4);
   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(point_t pos) override;
   void move(double dx, double dy) override;
   void scale(double k) override;
   Shape * clone() const override;
  private:
   point_t vertexes[4];
   point_t p_cross;
  };
}
#endif