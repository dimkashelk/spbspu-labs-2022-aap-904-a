#include "base_types.h"

point_t baseFunctions::SummVector(point_t point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
  return point;
}

double baseFunctions::findDifference(double position, double rect)
{
  return position - rect;
}

point_t Scale(point_t point, point_t center, double k)
{
  point.x = center.x + (point.x - center.x) * k;
  point.y = center.y + (point.y - center.y) * k;
  return point;
}