#include "triangle.h"
#include <cmath>
#include <stdexcept>
dimkashelk::Triangle::Triangle()
{}
dimkashelk::Triangle::Triangle(point_t p1, point_t p2, point_t p3)
{
  double side1 = std::sqrt(pow((p1.x - p2.x), 2) + pow(p1.y - p2.y, 2));
  double side2 = std::sqrt(pow((p1.x - p3.x), 2) + pow(p1.y - p3.y, 2));
  double side3 = std::sqrt(pow((p3.x - p2.x), 2) + pow(p3.y - p2.y, 2));
  if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2)
  {
    throw std::logic_error("It's not a triangle_");
  }
  points[0] = p1;
  points[1] = p2;
  points[2] = p3;
}
dimkashelk::Triangle::Triangle(const Triangle &triangle)
{
  points[0] = triangle.points[0];
  points[1] = triangle.points[1];
  points[2] = triangle.points[2];
}
dimkashelk::Triangle::Triangle(Triangle &&triangle)
{
  points[0] = triangle.points[0];
  points[1] = triangle.points[1];
  points[2] = triangle.points[2];
}
dimkashelk::Triangle &dimkashelk::Triangle::operator=(const Triangle &other)
{
  points[0] = other.points[0];
  points[1] = other.points[1];
  points[2] = other.points[2];
  return *this;
}
dimkashelk::Triangle &dimkashelk::Triangle::operator=(Triangle &&tmp)
{
  points[0] = tmp.points[0];
  points[1] = tmp.points[1];
  points[2] = tmp.points[2];
  return *this;
}
double dimkashelk::Triangle::getArea() const
{
  // the area of the triangle_ is half of the length of the vector product
  // let 's make a matrix
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  double a_x = points[1].x - points[0].x;
  double a_y = points[1].y - points[0].y;
  double b_x = points[2].x - points[0].x;
  double b_y = points[2].y - points[0].y;
  double third_coord = a_x * b_y - a_y * b_x;
  // |a * b| = |c| = sqrt(x * x + y * y + z * z)
  // where x = 0, y = 0 => |c| = sqrt(z * z) = z
  return std::fabs(third_coord) / 2;
}
dimkashelk::rectangle_t dimkashelk::Triangle::getFrameRect() const
{
  //  _____
  // |  o  |
  // | / \ |
  // |/   \|
  // o_____o
  // (x_min, y_min) - left down point of frame rect
  // (x_max, y_max) - right up point of frame rect
  double x_min = std::min(points[0].x, std::min(points[1].x, points[2].x));
  double y_min = std::min(points[0].y, std::min(points[1].y, points[2].y));
  double x_max = std::max(points[0].x, std::max(points[1].x, points[2].x));
  double y_max = std::max(points[0].y, std::max(points[1].y, points[2].y));
  return rectangle_t(point_t{x_min, y_min}, point_t{x_max, y_max});
}
void dimkashelk::Triangle::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < 3; i++)
  {
    points[i].x += delta_x;
    points[i].y += delta_y;
  }
}
void dimkashelk::Triangle::move(point_t point)
{
  point_t point_center_of_gravity = this->getCenter();
  this->move(point.x - point_center_of_gravity.x, point.y - point_center_of_gravity.y);
}
void dimkashelk::Triangle::scale(double k)
{
  point_t center_of_gravity = getCenter();
  for (size_t i = 0; i < 3; i++)
  {
    points[i].x = k * (points[i].x - center_of_gravity.x) + center_of_gravity.x;
    points[i].y = k * (points[i].y - center_of_gravity.y) + center_of_gravity.y;
  }
}
dimkashelk::Shape* dimkashelk::Triangle::clone() const
{
  Triangle *copy = new Triangle(points[0], points[1], points[2]);
  return copy;
}
dimkashelk::Triangle dimkashelk::Triangle::rotate(double theta) const
{
  double new_p_x_1 = std::cos(theta) * (points[1].x - points[0].x) - std::sin(theta) * (points[1].y - points[0].y) + points[0].x;
  double new_p_y_1 = std::sin(theta) * (points[1].x - points[0].x) + std::cos(theta) * (points[1].y - points[0].y) + points[0].y;
  double new_p_x_2 = std::cos(theta) * (points[2].x - points[0].x) - std::sin(theta) * (points[2].y - points[0].y) + points[0].x;
  double new_p_y_2 = std::sin(theta) * (points[2].x - points[0].x) + std::cos(theta) * (points[2].y - points[0].y) + points[0].y;
  return Triangle(points[0], point_t{new_p_x_1, new_p_y_1}, point_t{new_p_x_2, new_p_y_2});
}
dimkashelk::point_t dimkashelk::Triangle::getCenter() const
{
  return point_t{(points[0].x + points[1].x + points[2].x) / 3, (points[0].y + points[1].y + points[2].y) / 3};
}
