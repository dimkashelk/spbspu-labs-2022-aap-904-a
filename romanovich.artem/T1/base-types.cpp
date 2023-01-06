#include <cmath>
#include <algorithm>
#include <array>
#include "base-types.h"
double twoPointsDistance(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}
bool isTriangle(std::array< double, 6 > sides)
{
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double maxSide = std::max({a, b, c});
  double minSide = std::max({a, b, c});
  double midlSide = a + b + c - maxSide - minSide;
  return (maxSide < minSide + midlSide);
}
bool pointInsideTriangle(triangle_t triangle, point_t point)
{
  point_t a = triangle.a;
  point_t b = triangle.b;
  point_t c = triangle.c;
  bool isLeftAB = ((point.x - a.x) * (b.y - a.y) - (point.y - a.y) * (b.x - a.x) > 0);
  bool isLeftBC = ((point.x - b.x) * (c.y - b.y) - (point.y - b.y) * (c.x - b.x) > 0);
  bool isLeftCA = ((point.x - c.x) * (a.y - c.y) - (point.y - c.y) * (a.x - c.x) > 0);
  return ((isLeftAB && isLeftBC && isLeftCA) || (!isLeftAB && !isLeftBC && !isLeftCA));
}
point_t multiplyVector(point_t center, point_t point, double koeff)
{
  point.x = koeff * (point.x - center.x) + center.x;
  point.y = koeff * (point.y - center.y) + center.y;
  return point;
}
