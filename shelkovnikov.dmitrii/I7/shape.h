#ifndef SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#include <string>
#include "base_types.h"
class Shape
{
public:
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t point) const = 0;
  virtual void move(double x, double y) const = 0;
  virtual void scale(double k) const = 0;
  virtual std::string getName() const = 0;
};
#endif
