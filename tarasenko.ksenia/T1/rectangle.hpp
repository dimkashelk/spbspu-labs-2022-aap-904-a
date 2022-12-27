#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle: public Shape
{
  public:
   Rectangle(double x1, double y1, double x2, double y2);
   double getArea() const;
   rectangle_t getFrameRect() const;
   void move(point_t pos);
   void move(double dx, double dy);
   void scale(double k);

   ~Rectangle();
};
