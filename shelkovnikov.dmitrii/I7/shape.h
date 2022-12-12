#ifndef SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#include "base_types.h"
class Shape
{
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t point) const = 0;
};
#endif
