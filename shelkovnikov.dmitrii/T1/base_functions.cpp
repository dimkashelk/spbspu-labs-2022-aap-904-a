#include "base_functions.h"
#include <cmath>
dimkashelk::point_t dimkashelk::getLeftDownPoint(rectangle_t rect)
{
  return point_t{rect.point.x - rect.width / 2, rect.point.y - rect.height / 2};
}
dimkashelk::point_t dimkashelk::getRightUpPoint(rectangle_t rect)
{
  return point_t{rect.point.x + rect.width / 2, rect.point.y + rect.height / 2};
}
bool dimkashelk::isRectangularTriangle(const point_t *points)
{
  double square[3];
  for (size_t i = 0; i < 3; i++)
  {
    square[i] = std::pow(points[i].x - points[(i + 1) % 3].x, 2) + std::pow(points[i].y - points[(i + 1) % 3].y, 2);
  }
  return square[0]  == square[1] + square[2] || square[1] == square[0] + square[2] || square[2] == square[0] + square[1];
}
dimkashelk::point_t dimkashelk::getCenterOfWeight(const point_t *points, size_t size)
{
  double x_sum = 0.0;
  double y_sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    x_sum += points[i].x;
    y_sum += points[i].y;
  }
  return point_t{x_sum / size, y_sum / size};
}
dimkashelk::rectangle_t dimkashelk::makeRectangle(point_t left_down, point_t right_up)
{
  if (right_up.x <= left_down.x || right_up.y <= left_down.y)
  {
    throw std::logic_error("It isn't rectangle");
  }
  rectangle_t rect{point_t{(left_down.x + right_up.x) / 2, (left_down.y + right_up.y) / 2}, right_up.x - left_down.x, right_up.y - left_down.y};
  return rect;
}
