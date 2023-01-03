#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"
#include "base_types.h"
#include "rectangle.h"

class CompositeShape
{
  public:
    explicit CompositeShape();
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape && rhs);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(const point_t & position, double k);
    void push_back(shape * shapes);
    CompositeShape *clone() const;
  private:
    size_t size_;
    size_t capacity_;
    shape ** shape_;
};
#endif
