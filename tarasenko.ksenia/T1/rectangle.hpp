#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace tarasenko
{
  class Rectangle: public Shape
  {
  public:
   Rectangle(point_t point_ld, point_t point_ru);
   double getArea() const override;
   rectangle_t getFrameRect() const override;
   void move(point_t pos) override;
   void move(double dx, double dy) override;
   void scale(double k) override;
   Shape * clone() const override;
  private:
   point_t vertexes[2];
   rectangle_t rect_;
  };
}
#endif