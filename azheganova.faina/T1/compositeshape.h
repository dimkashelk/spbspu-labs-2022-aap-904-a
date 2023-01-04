#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"
#include "base_types.h"
#include "rectangle.h"

class CompositeShape
{
  public:
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs);
    CompositeShape(size_t capacity);
    shape * operator[](size_t i);
    shape * operator[](size_t i) const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(const point_t & position, double k);
    void push_back(shape * shapes);
    CompositeShape *clone() const;
    size_t size() const;
  private:
    size_t size_;
    size_t capacity_;
    shape ** shape_;
};
#endif
