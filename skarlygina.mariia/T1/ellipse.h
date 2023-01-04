#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"
class Ellipse : public Shape
{

public:
  Ellipse(point_t center, double radius_vert, double radius_horizont): center_(center), radius_vert_(radius_vert), radius_horizont_(radius_horizont) {}
  double getArea() const override;
  rectangle_t getFrameRectangle() const override;
  void move(const point_t& position) override;
  void move(double dx, double dy) override;
  void scale(double k) override;

private:
  double radius_vert_, radius_horizont_;
  point_t center_;

};
#endif
