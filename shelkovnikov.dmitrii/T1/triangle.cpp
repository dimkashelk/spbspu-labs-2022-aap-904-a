#include "triangle.h"
#include <cmath>
#include <stdexcept>
Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  point1(p1),
  point2(p2),
  point3(p3)
{
  double side1 = std::sqrt(pow((point1.x - point2.x), 2) + pow(point1.y - point2.y, 2));
  double side2 = std::sqrt(pow((point1.x - point3.x), 2) + pow(point1.y - point3.y, 2));
  double side3 = std::sqrt(pow((point3.x - point2.x), 2) + pow(point3.y - point2.y, 2));
  if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2)
  {
    throw std::logic_error("It's not a triangle");
  }
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle(point_t(x1, y1), point_t(x2, y2), point_t(x3, y3))
{}
double Triangle::getArea() const
{
  // the area of the triangle is half of the length of the vector product
  // let 's make a matrix
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  vector_t a(point2.x - point1.x, point2.y - point1.y);
  vector_t b(point3.x - point1.x, point3.y - point1.y);
  double third_coord = a.x * b.y - a.y * b.x;
  // |a * b| = |c| = sqrt(x * x + y * y + z * z)
  // where x = 0, y = 0 => |c| = sqrt(z * z) = z
  return third_coord / 2;
}
rectangle_t Triangle::getFrameRect() const
{
  //  _____
  // |  o  |
  // | / \ |
  // |/   \|
  // o_____o
  // (x_min, y_min) - left down point of frame rect
  // (x_max, y_max) - right up point of frame rect
  double x_min = std::min(point1.x, std::min(point2.x, point3.x));
  double y_min = std::min(point1.y, std::min(point2.y, point3.y));
  double x_max = std::max(point1.x, std::max(point2.x, point3.x));
  double y_max = std::max(point1.y, std::max(point2.y, point3.y));
  return rectangle_t(x_min, y_min, x_max, y_max);
}
void Triangle::move(point_t point)
{
  double center_of_gravity_x = (point1.x + point2.x + point3.x) / 3;
  double center_of_gravity_y = (point1.y + point2.y + point3.y) / 3;
  vector_t direction(point.x - center_of_gravity_x, point.y - center_of_gravity_y);
  point1.x += direction.x;
  point1.y += direction.y;
  point2.x += direction.x;
  point2.y += direction.y;
  point3.x += direction.x;
  point3.y += direction.y;
}
void Triangle::move(double delta_x, double delta_y)
{
  point1.x += delta_x;
  point1.y += delta_y;
  point2.x += delta_x;
  point2.y += delta_y;
  point3.x += delta_x;
  point3.y += delta_y;
}
