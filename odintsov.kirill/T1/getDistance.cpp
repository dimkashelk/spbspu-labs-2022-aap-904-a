#include "getDistance.hpp"
#include <cmath>
#include "base-types.hpp"

double getSquaredDistance(const odintsov::point_t& p1, const odintsov::point_t& p2)
{
  return std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2);
}

double getDistance(const odintsov::point_t& p1, const odintsov::point_t& p2)
{
  return std::sqrt(getSquaredDistance(p1, p2));
}
