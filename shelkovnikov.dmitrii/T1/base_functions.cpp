#include "base_functions.h"
point_t getLeftDownPoint(rectangle_t rect)
{
  return point_t(rect.point.x - rect.width / 2, rect.point.y - rect.height / 2);
}
point_t getRightUpPoint(rectangle_t rect)
{
  return point_t(rect.point.x + rect.width / 2, rect.point.y + rect.height / 2);
}
