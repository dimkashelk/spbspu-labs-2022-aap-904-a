#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace tarasenko
{
  class Triangle: public Shape
  {
  public:
   point_t vertexes[3];
   double a, b, c;
   point_t center;
   Triangle(point_t point_1, point_t point_2, point_t point_3);
   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(point_t pos) override;
   void move(double dx, double dy) override;
   void scale(double k) override;
   Shape * clone() const override;
  };
}
#endif