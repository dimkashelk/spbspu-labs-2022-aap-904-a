#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#include <istream>
struct point_t
{
  double x;
  double y;
  point_t();
  point_t(double x, double y);
  point_t(const point_t &point);
  point_t& operator=(const point_t point);
};
struct rectangle_t
{
  point_t point;
  double width;
  double height;
  rectangle_t(double x1, double y1, double x2, double y2);
  rectangle_t(point_t point, double width, double height);
  point_t getLeftDownPoint() const;
  point_t getRightUpPoint() const;
};
std::istream& operator>>(std::istream &in, point_t &point);
std::ostream& operator<<(std::ostream &out, point_t &point);
#endif
