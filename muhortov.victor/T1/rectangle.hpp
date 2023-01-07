#ifndef GITLAB_LABS_RECTANGLE_HPP
#define GITLAB_LABS_RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(point_t one, point_t two);
  double getArea() override;
  rectangle_t getFrameRect() override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
private:
  rectangle_t rectangle;
};

#endif
