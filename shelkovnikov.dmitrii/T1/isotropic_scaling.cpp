#include "isotropic_scaling.h"
#include "vector_t.h"
void isotropic_scaling(Shape *shape, point_t point, double k)
{
  rectangle_t rectangle_1 = shape->getFrameRect();
  shape->move(point);
  rectangle_t rectangle_2 = shape->getFrameRect();
  vector_t direction(rectangle_2.getLeftDownPoint(), rectangle_1.getLeftDownPoint());
  direction *= k;
  shape->scale(k);
  shape->move(direction.x, direction.y);
}
