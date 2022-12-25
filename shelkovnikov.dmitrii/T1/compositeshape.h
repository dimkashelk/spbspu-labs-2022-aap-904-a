#ifndef SPBSPU_LABS_2022_AAP_904_A_COMPOSITE_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_COMPOSITE_SHAPE_H
#include <cstddef>
#include "base_types.h"
#include "shape.h"
class CompositeShape
{
public:
  CompositeShape(Shape **shapes, size_t size);
  const double getArea() const;
  const rectangle_t getFrameRect() const;
  void move(point_t point);
  void move(double delta_x, double delta_y);
  void scale(double k);
private:
  Shape **shapes_;
  size_t size_;
};
#endif
