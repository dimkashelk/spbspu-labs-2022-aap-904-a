#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
class Ellipse : public Shape
{

public:
  Ellipse(point_t center, double radius_vertical, double radius_horizontal): center_(center), radius_vertical_(radius_vertical), radius_horizontal_(radius_horizontal) {}
  double getArea() const override;
  rectangle_t getFrameRectangle() const override;
  void move(const point_t& position) override;
  void move(double dx, double dy) override;
  void scale(double k) override;

private:
  double radius_vertical_, radius_horizontal_;
  point_t center_;

};
#endif