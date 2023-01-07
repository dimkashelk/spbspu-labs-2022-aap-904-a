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