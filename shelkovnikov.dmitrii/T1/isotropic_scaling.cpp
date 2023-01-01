#include "isotropic_scaling.h"
#include "vector_t.h"
#include "base_functions.h"
void isotropic_scaling(Shape *shape, point_t point, double k)
{
  rectangle_t rectangle_1 = shape->getFrameRect();
  shape->move(point);
  rectangle_t rectangle_2 = shape->getFrameRect();
  vector_t direction(getLeftDownPoint(rectangle_2), getLeftDownPoint(rectangle_1));
  direction *= -k;
  shape->scale(k);
  shape->move(direction.x, direction.y);
}
