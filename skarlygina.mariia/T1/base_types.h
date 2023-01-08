#ifndef BASE_TYPES_H
#define BASE_TYPES_H

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double height;
  double width;
  point_t position;
};

namespace baseFunctions
{
  point_t SummVector(point_t point, double dx, double dy);
  point_t findDifference(point_t position, point_t rect);
  point_t Scale(point_t point, point_t center, double k);
  point_t CenterMove(point_t center, point_t center_rect, double k);
  double Radius(double radius, double k);
}

#endif

