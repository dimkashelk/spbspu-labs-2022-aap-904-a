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
    CompositeShape &operator=(const CompositeShape &compositeShape);
    CompositeShape &operator=(CompositeShape &&compositeShape);
    ~CompositeShape();
    Shape *operator[](size_t index);
    const Shape *operator[](size_t index) const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t point);
    void move(double dx, double dy);
    void scale(double k);
    void isoScale(point_t point, double k);
  private:
    size_t size;
    size_t capacity;
    Shape **shapes;
    void free(Shape **shapes, size_t size);
  };
}

#endif
