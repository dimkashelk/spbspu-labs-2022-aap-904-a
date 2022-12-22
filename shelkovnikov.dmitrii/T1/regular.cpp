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
  double angle_degrees = acos(side_1 / side_2) * 180.0 / M_PI;
  count = static_cast< size_t >(360 / angle_degrees);
}
double Regular::getArea() const
{
  return triangle.getArea() * count;
}
rectangle_t Regular::getFrameRect() const
{
  // rotate point (px, py) around point (ox, oy) by angle theta
  // p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
  // p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy
  point_t *points = triangle.getPoints();
  double o_x = points[0].x;
  double o_y = points[0].y;
  double p_x_1 = points[1].x;
  double p_y_1 = points[1].y;
  double p_x_2 = points[2].x;
  double p_y_2 = points[2].y;
  delete[] points;
  double min_x = p_x_1;
  double min_y = p_y_1;
  double max_x = p_x_1;
  double max_y = p_y_1;
  double theta = 360.0f / count;
  for (size_t i = 0; i < count; i++)
  {
    p_x_1 = std::cos(theta) * (p_x_1 - o_x) - std::sin(theta) * (p_y_1 - o_y) + o_x;
    p_y_1 = std::sin(theta) * (p_x_1 - o_x) + std::cos(theta) * (p_y_1 - o_y) + o_y;
    p_x_2 = std::cos(theta) * (p_x_2 - o_x) - std::sin(theta) * (p_y_2 - o_y) + o_x;
    p_y_2 = std::sin(theta) * (p_x_2 - o_x) + std::cos(theta) * (p_y_2 - o_y) + o_y;
    min_x = std::min(min_x, std::min(p_x_1, p_x_2));
    min_y = std::min(min_x, std::min(p_y_1, p_y_2));
    max_x = std::max(max_x, std::max(p_x_1, p_x_2));
    max_y = std::max(max_x, std::max(p_y_1, p_y_2));
  }
  return rectangle_t(min_x, min_y, max_x, max_y);
}
void Regular::move(double delta_x, double delta_y)
{
  triangle.move(delta_x, delta_y);
}
void Regular::move(point_t point)
{
  point_t *points = triangle.getPoints();
  point_t center = triangle.getCenterOfGravity();
  double delta_x = center.x - points[0].x;
  double delta_y = center.y - points[0].y;
  triangle.move(point);
  triangle.move(delta_x, delta_y);
}
void Regular::scale(double k)
{
  point_t *old_points = triangle.getPoints();
  triangle.scale(k);
  point_t *new_points = triangle.getPoints();
  triangle.move(old_points[0].x - new_points[0].x, old_points[0].y - new_points[0].y);
}
