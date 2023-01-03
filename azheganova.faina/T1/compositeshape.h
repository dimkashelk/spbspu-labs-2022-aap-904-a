#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"

class CompositeShape
{
  public:
    CompositeShape(const CompositeShape & rhs);
    CompositeShape(CompositeShape &&);
    CompositeShape(unsigned long&);
    CompositeShape(size_t&);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(const point_t & position, double k);
    void push_back(shape * shapes);
  private:
    shape ** shape_;
    size_t size_;
    size_t capacity_;
};
#endif
