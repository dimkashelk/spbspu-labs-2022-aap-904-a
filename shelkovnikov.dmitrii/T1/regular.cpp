#include "regular.h"
#include <stdexcept>
#include <cmath>
#include "isotropic_scaling.h"
#include "base_functions.h"
dimkashelk::Regular::Regular(point_t point_1, point_t point_2, point_t point_3):
  triangle_(point_1, point_2, point_3),
  size_(0),
  center_(point_1)
{
  point_t *points = new point_t[3]{point_1, point_2, point_3};
  if (!dimkashelk::isRectangularTriangle(points))
  {
    delete[] points;
    throw std::logic_error("Triangle isn't rectangular");
  }
  delete[] points;
  double side_1 = std::sqrt(std::pow(point_2.x - point_1.x, 2) + std::pow(point_2.y - point_1.y, 2));
  double side_2 = std::sqrt(std::pow(point_3.x - point_1.x, 2) + std::pow(point_3.y - point_1.y, 2));
  double hypotenuse = std::max(side_1, side_2);
  double cathet = std::min(side_1, side_2);
  double angle_degrees = std::round((acos(cathet / hypotenuse) * 180.0 / M_PI) * 1000) / 1000;
  size_ = static_cast< size_t >(360 / angle_degrees);
  if (size_ * angle_degrees != 360)
  {
    throw std::logic_error("Cannot build regular figure");
  }
}
dimkashelk::Regular::Regular(const Regular &regular):
  triangle_(regular.triangle_),
  size_(regular.size_),
  center_(regular.center_)
{}
double dimkashelk::Regular::getArea() const
{
  return triangle_.getArea() * size_;
}
dimkashelk::rectangle_t dimkashelk::Regular::getFrameRect() const
{
  // rotate point (px, py) around point (ox, oy) by angle theta
  // p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
  // p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy
  point_t *points = triangle_.getPoints();
  double o_x = points[0].x;
  double o_y = points[0].y;
  double p_x_1 = points[1].x;
  double p_y_1 = points[1].y;
  double p_x_2 = points[2].x;
  double p_y_2 = points[2].y;
  delete[] points;
  double min_x = std::min(p_x_1, p_x_2);
  double min_y = std::min(p_y_1, p_y_2);
  double max_x = std::max(p_x_1, p_x_2);
  double max_y = std::max(p_y_1, p_y_2);
  double theta = 360.0 / size_ * 2 * M_PI / 180;
  for (size_t i = 0; i < size_; i++)
  {
    double new_p_x_1 = std::cos(theta) * (p_x_1 - o_x) - std::sin(theta) * (p_y_1 - o_y) + o_x;
    double new_p_y_1 = std::sin(theta) * (p_x_1 - o_x) + std::cos(theta) * (p_y_1 - o_y) + o_y;
    double new_p_x_2 = std::cos(theta) * (p_x_2 - o_x) - std::sin(theta) * (p_y_2 - o_y) + o_x;
    double new_p_y_2 = std::sin(theta) * (p_x_2 - o_x) + std::cos(theta) * (p_y_2 - o_y) + o_y;
    p_x_1 = new_p_x_1;
    p_y_1 = new_p_y_1;
    p_x_2 = new_p_x_2;
    p_y_2 = new_p_y_2;
    min_x = std::min(min_x, std::min(p_x_1, p_x_2));
    min_y = std::min(min_y, std::min(p_y_1, p_y_2));
    max_x = std::max(max_x, std::max(p_x_1, p_x_2));
    max_y = std::max(max_y, std::max(p_y_1, p_y_2));
  }
  return rectangle_t(point_t{min_x, min_y}, point_t{max_x, max_y});
}
void dimkashelk::Regular::move(double delta_x, double delta_y)
{
  triangle_.move(delta_x, delta_y);
}
void dimkashelk::Regular::move(point_t point)
{
  Shape *triangle = triangle_.clone();
  triangle->move(center_);
  point_t begin_point = dimkashelk::getLeftDownPoint(triangle->getFrameRect());
  triangle->move(point);
  point_t end_point = dimkashelk::getLeftDownPoint(triangle->getFrameRect());
  double delta_x = end_point.x - begin_point.x;
  double delta_y = end_point.y - begin_point.y;
  triangle_.move(delta_x, delta_y);
  delete triangle;
}
void dimkashelk::Regular::scale(double k)
{
  rectangle_t begin_rect = triangle_.getFrameRect();
  triangle_.move(dimkashelk::getLeftDownPoint(begin_rect));
  rectangle_t end_rect = triangle_.getFrameRect();
  triangle_.scale(k);
  triangle_.move(k * (end_rect.point.x - begin_rect.point.x), k * (end_rect.point.y - begin_rect.point.y));
}
dimkashelk::Shape *dimkashelk::Regular::clone() const
{
  return new Regular(*this);
}
