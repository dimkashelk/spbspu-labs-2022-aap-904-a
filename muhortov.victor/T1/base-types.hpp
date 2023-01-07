#ifndef GITLAB_LABS_BASE_TYPES_HPP
#define GITLAB_LABS_BASE_TYPES_HPP

struct point_t
  {
  double x, y;
  };

struct  rectangle_t
  {
  point_t pos;
  double width, height;
  };

struct scale_t
{
  point_t pos;
  double scale;
};
#endif
