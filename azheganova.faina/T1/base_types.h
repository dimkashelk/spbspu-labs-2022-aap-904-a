#ifndef BASE_TYPES_H
#define BASE_TYPES_H

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
  rectangle_t(point_t pos1, point_t pos2);
  rectangle_t(point_t pos, double width, double height);
};

#endif
