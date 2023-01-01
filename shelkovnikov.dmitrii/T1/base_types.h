#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#include <istream>
namespace dimkashelk
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    point_t point;
    double width;
    double height;
    rectangle_t(point_t point_1, point_t point_2);
    rectangle_t(point_t point, double width, double height);
  };
}
#endif
