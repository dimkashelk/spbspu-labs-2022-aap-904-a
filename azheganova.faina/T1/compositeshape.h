#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"

class CompositeShape
{
  public:
    CompositeShape();
    CompositeShape(size_t capasity);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(const point_t & position, double k);
    void push_back(shape * shapes);
    CompositeShape *clone() const;
  private:
    shape ** shape_;
    size_t size_;
    size_t capacity_;
};
#endif
