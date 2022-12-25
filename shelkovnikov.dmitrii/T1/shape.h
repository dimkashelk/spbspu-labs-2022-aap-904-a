#ifndef SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#include "base_types.h"
class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t point) = 0;
  virtual void move(double delta_x, double delta_y) = 0;
  virtual void scale(double k) = 0;
  virtual ~Shape() = default;
};
#endif