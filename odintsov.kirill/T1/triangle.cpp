#include "triangle.hpp"
#include <cmath>
#include "base-types.hpp"
#include "getDistance.hpp"
#include "minmax.hpp"

bool odintsov::isTriangle(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = getDistance(p1, p2);
  double b = getDistance(p1, p3);
  double c = getDistance(p2, p3);
  double maxSide = max(a, b, c);
  return maxSide < a + b + c - maxSide;
}

double odintsov::getTriangleArea(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = getDistance(p1, p2);
  double b = getDistance(p1, p3);
  double c = getDistance(p2, p3);
  double s = (a + b + c) * 0.5;
  return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

bool odintsov::isPointInsideTriangle(const point_t& p, const point_t& p1, const point_t& p2, const point_t& p3)
{
  double area1 = getTriangleArea(p1, p2, p);
  double area2 = getTriangleArea(p1, p3, p);
  double area3 = getTriangleArea(p2, p3, p);
  return getTriangleArea(p1, p2, p3) == area1 + area2 + area3;
}
