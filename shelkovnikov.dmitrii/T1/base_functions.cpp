#include "base_functions.h"
dimkashelk::point_t dimkashelk::getLeftDownPoint(rectangle_t rect)
{
  return point_t{rect.point.x - rect.width / 2, rect.point.y - rect.height / 2};
}
dimkashelk::point_t dimkashelk::getRightUpPoint(rectangle_t rect)
{
  return point_t{rect.point.x + rect.width / 2, rect.point.y + rect.height / 2};
}
