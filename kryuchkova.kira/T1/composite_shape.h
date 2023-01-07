#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H
#include "base_types.h"
#include "shape.h"

namespace kryuchkova
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape &compositeShape);
    CompositeShape(CompositeShape &&compositeShape);
  private:
    size_t size;
    size_t capacity;
    Shape **shapes;
    void free(Shape **shapes, size_t size);
  };
}

#endif
