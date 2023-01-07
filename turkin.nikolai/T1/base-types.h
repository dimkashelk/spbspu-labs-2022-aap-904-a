#ifndef T1_BASE_TYPES_H
#define T1_BASE_TYPES_H
namespace turkin
{
  struct point_t
  {
    double x, y;
  };

  struct rectangle_t
  {
    point_t pos;
    double width, height;
  };

  struct scale_t
  {
    point_t pos;
    double ds;
  };
}
#endif

