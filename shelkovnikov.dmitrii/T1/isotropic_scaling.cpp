#include "isotropic_scaling.h"
#include "base_functions.h"
void dimkashelk::isotropic_scaling(Shape *shape, point_t point, double k)
{
  point_t point_1 = get_left_down_point(shape->getFrameRect());
  shape->move(point);
  point_t point_2 = get_left_down_point(shape->getFrameRect());
  shape->scale(k);
  shape->move(-k * (point_2.x - point_1.x), -k * (point_2.y - point_1.y));
}
