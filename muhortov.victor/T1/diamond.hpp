#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include <array>
#include "base-types.hpp"
#include "shape.hpp"

class Diamond: public Shape
{
public:
  Diamond(point_t one, point_t two, point_t three);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void scaleWithoutCheck(double k) override;
  Shape *clone() const override;
private:
  std::array< point_t, 5 > positions;
  double d1, d2;
};

#endif
