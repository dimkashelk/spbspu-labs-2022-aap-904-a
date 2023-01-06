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
    ~CompositeShape();
    Shape * operator[](size_t i);
    Shape * operator[](size_t i) const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(const point_t & position, double k);
    void push_back(const Shape * shp);
    void push_back(Shape * shp);
    void pop_back();
    bool empty();
    size_t size();
    CompositeShape *clone() const;
    size_t size() const;
  private:
    size_t size_;
    size_t capacity_;
    Shape ** shape_;
};
#endif
