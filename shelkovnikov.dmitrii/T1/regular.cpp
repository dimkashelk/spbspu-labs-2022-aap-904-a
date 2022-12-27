#include "regular.h"
#include <stdexcept>
#include <cmath>
Regular::Regular():
  triangle_(Triangle()),
  size_(0)
{}
Regular::Regular(double x1, double y1, double x2, double y2, double x3, double y3):
  triangle_(x1, y1, x2, y2, x3, y3),
  size_(0)
{
  if (!triangle_.isRectangular())
  {
    throw std::logic_error("Triangle isn't rectangular");
  }
  double side_1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
  double side_2 = std::sqrt(std::pow(x3 - x1, 2) + std::pow(y3 - y1, 2));
  double angle_degrees = acos(side_1 / side_2) * 180.0 / M_PI;
  size_ = static_cast< size_t >(360 / angle_degrees);
}
Regular::Regular(const Regular &regular):
  triangle_(regular.triangle_),
  size_(regular.size_)
{}
Regular::Regular(Regular &&regular):
  triangle_(regular.triangle_),
  size_(regular.size_)
{}
Regular &Regular::operator=(const Regular &other)
{
  triangle_ = other.triangle_;
  size_ = other.size_;
  return *this;
}
Regular &Regular::operator=(Regular &&tmp)
{
  triangle_ = tmp.triangle_;
  size_ = tmp.size_;
  return *this;
}
double Regular::getArea() const
{
  return triangle_.getArea() * size_;
}
rectangle_t Regular::getFrameRect() const
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
  double min_x = p_x_1;
  double min_y = p_y_1;
  double max_x = p_x_1;
  double max_y = p_y_1;
  double theta = 360.0f / size_;
  for (size_t i = 0; i < size_; i++)
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
  triangle_.move(delta_x, delta_y);
}
void Regular::move(point_t point)
{
  point_t *points = triangle_.getPoints();
  point_t center = triangle_.getCenter();
  double delta_x = center.x - points[0].x;
  double delta_y = center.y - points[0].y;
  triangle_.move(point);
  triangle_.move(delta_x, delta_y);
  delete[] points;
}
void Regular::scale(double k)
{
  point_t *old_points = triangle_.getPoints();
  triangle_.scale(k);
  point_t *new_points = triangle_.getPoints();
  triangle_.move(old_points[0].x - new_points[0].x, old_points[0].y - new_points[0].y);
  delete[] old_points;
  delete[] new_points;
}
Shape *Regular::clone() const
{
  return new Regular(*this);
}
std::istream& operator>>(std::istream &in, Regular &regular)
{
  Triangle triangle;
  in >> triangle;
  point_t *points = triangle.getPoints();
  try
  {
    regular = Regular(points[0].x, points[0].y, points[1].x, points[1].y, points[2].x, points[2].y);
  }
  catch (...)
  {
    delete[] points;
    throw;
  }
  delete[] points;
  return in;
}
