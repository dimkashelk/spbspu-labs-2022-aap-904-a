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
  double side_b = std::sqrt(std::pow((dots[1].x - dots[0].x), 2) + std::pow((dots[1].y - dots[0].y), 2));
  double side_c = std::sqrt(std::pow((dots[2].x - dots[1].x), 2) + std::pow((dots[2].y - dots[1].y), 2));

  return side_a + side_b < side_c || side_a + side_c < side_b || side_b + side_c < side_a;
}

double checkOneTriangle(point_t a, point_t b, point_t c)
{
  return ((a.x - c.x) * (b.y - a.y) - (b.x - a.x) * (a.y - c.y));
}

bool checkTriangles(point_t dots[])
{
  double triangle1 = checkOneTriangle(dots[0], dots[1], dots[3]);
  double triangle2 = checkOneTriangle(dots[1], dots[2], dots[3]);
  bool is_above_zero = triangle1 > 0.0 && triangle2 > 0.0;
  bool is_below_zero = triangle1 < 0.0 && triangle2 < 0.0;
  double triangle3 = 0.0;

  if (is_above_zero || is_below_zero)
  {
    triangle3 = checkOneTriangle(dots[2], dots[0], dots[3]);
    if ((triangle3 > 0.0 && is_above_zero) || (triangle3 < 0.0 && is_below_zero))
    {
      return false;
    }
  }
  return true;
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

point_t scaleDelta(point_t pos, scale_t scale)
{
  return {(pos.x - scale.pos.x) * scale.scale, (pos.y - scale.pos.y) * scale.scale};
}
