#ifndef SPBSPU_LABS_2022_AAP_904_A_COMPOSITE_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_COMPOSITE_SHAPE_H
#include <cstddef>
#include "base_types.h"
#include "shape.h"
class CompositeShape
{
public:
  CompositeShape();
  CompositeShape(Shape **shapes, size_t size);
  Shape* operator[](size_t id);
  const Shape* operator[](size_t id) const;
  ~CompositeShape();
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t point);
  void move(double delta_x, double delta_y);
  void scale(double k);
  point_t getCenter() const;
  void push_back(Shape *shp);
  void pop_back();
  Shape* at(size_t id);
  const Shape* at(size_t id) const;
  bool empty() const noexcept;
  size_t size() const noexcept;
private:
  size_t size_;
  size_t capacity_;
  Shape **shapes_;
};
#endif
