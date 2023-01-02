#ifndef SPBSPU_LABS_2022_AAP_904_A_COMPOSITESHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_COMPOSITESHAPE_H
#include <cstddef>
#include "base-types.h"
#include "shape.h"
class CompositeShape
{
public:
  CompositeShape(const CompositeShape &rhs);
  CompositeShape(CompositeShape &);
  explicit CompositeShape(size_t capacity);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double dx, double dy);
  void move(point_t position);
  void scale(double k);
  void push_back(Shape *shp);
  void pop_back();
  Shape *at(size_t id);
  Shape *operator[](size_t id);
  bool empty();
  size_t size();
  CompositeShape *clone() const;
  ~CompositeShape();

  void isoScale(Shape &shape, double x, double y, double k);

private:
  Shape **shape_;
  size_t size_;
  size_t capacity_;
};
#endif
