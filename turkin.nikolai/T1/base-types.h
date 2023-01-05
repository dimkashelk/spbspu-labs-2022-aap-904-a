#ifndef T1_BASE_TYPES_H
#define T1_BASE_TYPES_H
#include <cstddef>
namespace turkin
{
  struct point_t
  {
    double x, y;
  };

  struct rectangle_t
  {
    point_t position;
    double width, height;
  };

  struct scale_t
  {
    point_t position;
    double scale;
  };
}

#endif

