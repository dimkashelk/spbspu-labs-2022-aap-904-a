#include "isoscale.hpp"

void tarasenko::isoScale(Shape * shape, point_t center, double k)
{
  shape->checkCoefficient(k);
  point_t pos_1 = shape->getFrameRect().pos_;
  shape->move(center);
  point_t pos_2 = shape->getFrameRect().pos_;
  shape->scale(k);
  shape->move((pos_1.x_ - pos_2.x_) * k, (pos_1.y_ - pos_2.y_) * k);
}