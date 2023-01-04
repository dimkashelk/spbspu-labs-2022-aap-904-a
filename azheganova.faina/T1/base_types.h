#ifndef BASE_TYPES_H
#define BASE_TYPES_H

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
  rectangle_t(point_t pos1, point_t pos2);
  rectangle_t(point_t pos, double width, double height);
};

struct triangle_t
{
  point_t pos;
  triangle_t(point_t pos1, point_t pos2, point_t pos3);
};

#endif
