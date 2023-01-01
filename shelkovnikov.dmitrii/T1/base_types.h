#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#include <istream>
struct point_t
{
  double x;
  double y;
  point_t();
  point_t(double x, double y);
};
struct rectangle_t
{
  point_t point;
  double width;
  double height;
  rectangle_t(point_t point_1, point_t point_2);
  rectangle_t(point_t point, double width, double height);
};
std::istream& operator>>(std::istream &in, point_t &point);
std::ostream& operator<<(std::ostream &out, point_t &point);
std::ostream& operator<<(std::ostream &out, rectangle_t &rectangle);
#endif
