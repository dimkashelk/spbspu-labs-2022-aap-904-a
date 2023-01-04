#include "base_functions.h"
#include <cmath>
#include <stdexcept>
dimkashelk::point_t dimkashelk::getLeftDownPoint(rectangle_t rect)
{
  return point_t{rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2};
}
dimkashelk::point_t dimkashelk::getRightUpPoint(rectangle_t rect)
{
  return point_t{rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2};
}
bool dimkashelk::isRectangularTriangle(const point_t *points)
{
  double square[3]{0.0, 0.0, 0.0};
  for (size_t i = 0; i < 3; i++)
  {
    square[i] = std::pow(points[i].x - points[(i + 1) % 3].x, 2) + std::pow(points[i].y - points[(i + 1) % 3].y, 2);
  }
  bool result = false;
  for (size_t i = 0; i < 3; i++)
  {
    result = result || square[i]  == square[(i + 1) % 3] + square[(i + 2) % 3];
  }
  return result;
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
dimkashelk::rectangle_t dimkashelk::makeRectangle(point_t left, point_t right)
{
  if (right.x <= left.x || right.y <= left.y)
  {
    throw std::logic_error("It isn't rectangle");
  }
  rectangle_t rect{point_t{(left.x + right.x) / 2, (left.y + right.y) / 2},right.x - left.x,right.y - left.y};
  return rect;
}
