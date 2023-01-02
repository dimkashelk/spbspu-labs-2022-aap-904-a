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
  CompositeShape();
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double dx, double dy);
  void move(point_t position);
  void scale(double k);
  CompositeShape *clone() const;
  ~CompositeShape() = default;
private:
  Shape **shape_;
  size_t size_;
  size_t capacity_;
};
#endif
