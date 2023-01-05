#include "getDistance.hpp"
#include <cmath>

double getSquaredDistance(const point_t& p1, const point_t& p2)
{
  return std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2);
}

double getDistance(const point_t& p1, const point_t& p2)
{
  return std::sqrt(getSquaredDistance(p1, p2));
}
