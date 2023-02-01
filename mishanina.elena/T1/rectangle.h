#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.h"
#include "shape.h"
#include <string>

class Rectangle : public Shape
{
public:
  Rectangle(const point_t& ld_point, const point_t& ru_point);
  std::string getName() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t point) override;
  void scale(double k) override;
  void move(const double dx, const double dy) override;
  Shape* clone() const override;

private:
  const char* name_;
  point_t ld_point_, ru_point_;
};

#endif
