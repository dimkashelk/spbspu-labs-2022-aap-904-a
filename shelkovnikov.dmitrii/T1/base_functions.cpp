#include "base_functions.h"
dimkashelk::point_t dimkashelk::get_left_down_point(rectangle_t rect)
{
  return point_t{rect.point.x - rect.width / 2, rect.point.y - rect.height / 2};
}
dimkashelk::point_t dimkashelk::get_right_up_point(rectangle_t rect)
{
  return point_t{rect.point.x + rect.width / 2, rect.point.y + rect.height / 2};
}
