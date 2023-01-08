#ifndef RING_HPP
#define RING_HPP

#include "Base-types.hpp"
#include "Shape.hpp"

class Ring: public Shape
{
public:
  Ring(point_t center, double r1_inner, double r1_outer, double r2_inner, double r2_outer);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void makeScale(double k) override;
  Shape *clone() const override;
private:
  rectangle_t rect_;
  double r1_v_;
  double r1_h_;
  double r2_v_;
  double r2_h_;
};

#endif
