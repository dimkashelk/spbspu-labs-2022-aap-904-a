#include "regular.h"
#include <stdexcept>
#include <cmath>
Regular::Regular(double x1, double y1, double x2, double y2, double x3, double y3):
  triangle(x1, y1, x2, y2, x3, y3),
  count(0)
{
  if (!triangle.isRectangular())
  {
    throw std::logic_error("Triangle isn't rectangular");
  }
  double side_1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
  double side_2 = std::sqrt(std::pow(x3 - x1, 2) + std::pow(y3 - y1, 2));
  double angle_degrees = acos(side_1 / side_2) * 180.0 / std::PI;
  count = static_cast< size_t >(360 / angle_degrees);
}
