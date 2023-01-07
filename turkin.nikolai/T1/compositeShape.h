#ifndef T1_COMPOSITESHAPE_H
#define T1_COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"
namespace turkin
{
  class CompositeShape
  {
    public:
      explicit CompositeShape(size_t capacity);
      void push_back(Shape * shp);
      void push_back(const Shape * shp);
      void pop_back();
      Shape * at(size_t id) const;
      Shape * operator[](size_t id) const;
      bool empty() const;
      size_t size() const;
      rectangle_t getFrameRect() const;
      double getArea() const;
      void move(double dx, double dy);
      void move(point_t position);
      void scale(turkin::scale_t scale);
      ~CompositeShape();
    private:
      Shape ** shapes;
      size_t capacity_;
      size_t size_;
  };
}
#endif

