#include "Base-types.hpp"
#include <cmath>

double calcVectorLength(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}

bool checkTriangleSides(point_t dots[])
{
  double side_a = std::sqrt(std::pow((dots[2].x - dots[0].x), 2) + std::pow((dots[2].y - dots[0].y), 2));
  double side_b = std::sqrt(
    (dots[1].x - dots[0].x) * (dots[1].x - dots[0].x) + (dots[1].y - dots[0].y) * (dots[1].y - dots[0].y));
  double side_c = std::sqrt(
    (dots[2].x - dots[1].x) * (dots[2].x - dots[1].x) + (dots[2].y - dots[1].y) * (dots[2].y - dots[1].y));

  return side_a + side_b < side_c || side_a + side_c < side_b || side_b + side_c < side_a;
}

bool checkTriangles(point_t dots[])
{
  bool triangle1 = ((dots[0].x - dots[3].x) * (dots[1].y - dots[0].y) - (dots[1].x - dots[0].x) * (dots[0].y - dots[3].y)) > 0;
  bool triangle2 = ((dots[1].x - dots[3].x) * (dots[2].y - dots[1].y) - (dots[2].x - dots[1].x) * (dots[1].y - dots[3].y)) > 0;
  bool triangle3 = ((dots[2].x - dots[3].x) * (dots[0].y - dots[2].y) - (dots[0].x - dots[2].x) * (dots[2].y - dots[3].y)) > 0;

  return !((triangle1 && triangle2 && triangle3) || (!triangle1 && !triangle2 && !triangle3));
}

bool validateConcave(point_t dots[])
{
  return checkTriangleSides(dots) || dots[0].x == dots[3].x || dots[0].y == dots[3].y || checkTriangles(dots);
}

point_t addVector(point_t dot, double dx, double dy)
{
  dot.x += dx;
  dot.y += dy;
  return dot;
}
