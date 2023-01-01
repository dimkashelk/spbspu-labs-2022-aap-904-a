#ifndef SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#include "base-types.h"
class Shape
{
public:
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double dx, double dy);
  void move(point_t position);
  void scale(double k);
  virtual Shape *clone() const = 0;
  virtual ~Shape();
};
#endif
