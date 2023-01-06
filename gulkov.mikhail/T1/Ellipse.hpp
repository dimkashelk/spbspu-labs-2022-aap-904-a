#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Base-types.hpp"
#include "Shape.hpp"

class Ellipse : public Shape
{
public:
  Ellipse(point_t center, double radius1, double radius2);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  //void scale(double k) override;

private:
  rectangle_t rect_;
  double local_radius1;
  double local_radius2;
};

#endif
