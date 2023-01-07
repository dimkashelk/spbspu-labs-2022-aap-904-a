#include "Base-types.hpp"
#include <cmath>

double calcVectorLength(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}

bool validateConcave(const point_t &one, const point_t &two, const point_t &three, const point_t &four)
{
  double side_a = std::sqrt(std::pow((three.x - one.x), 2) + std::pow((three.y - one.y), 2));
  double side_b = std::sqrt((two.x - one.x) * (two.x - one.x) + (two.y - one.y) * (two.y - one.y));
  double side_c = std::sqrt((three.x - two.x) * (three.x - two.x) + (three.y - two.y) * (three.y - two.y));

  bool triangle1 = ((one.x - four.x) * (two.y - one.y) - (two.x - one.x) * (one.y - four.y)) > 0;
  bool triangle2 = ((two.x - four.x) * (three.y - two.y) - (three.x - two.x) * (two.y - four.y)) > 0;
  bool triangle3 = ((three.x - four.x) * (one.y - three.y) - (one.x - three.x) * (three.y - four.y)) > 0;

  bool is_not_side = side_a + side_b < side_c || side_a + side_c < side_b || side_b + side_c < side_a;
  bool is_not_coordinates = one.x == four.x || one.y == four.y;
  bool is_not_triangles = !((triangle1 && triangle2 && triangle3) || (!triangle1 && !triangle2 && !triangle3));

  return is_not_side || is_not_coordinates || is_not_triangles;
}
