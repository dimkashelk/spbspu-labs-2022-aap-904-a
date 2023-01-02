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
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(point_t position) = 0;
  virtual void scale(double k) = 0;
  virtual CompositeShape *clone() const = 0;
  virtual ~CompositeShape() = default;
private:
  Shape **shape_;
  size_t size_;
  size_t capacity_;
};
#endif
