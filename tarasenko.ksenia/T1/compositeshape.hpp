#ifndef  COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "shape.hpp"
#include "cstddef"
namespace tarasenko
{
  class CompositeShape
  {
  public:
   CompositeShape();
   size_t size() const;
   double getArea() const;
   rectangle_t getFrameRect() const;
   void move(point_t pos);
   void move(double dx, double dy);
   void scale(double k);
   void push_back(Shape * shp);
   void pop_back();
   Shape * at(size_t id);
   Shape * operator[](size_t id);
   bool empty() const;
   ~CompositeShape();
  private:
   size_t size_;
   size_t capacity_;
   Shape ** shapes;
  };
}
#endif
