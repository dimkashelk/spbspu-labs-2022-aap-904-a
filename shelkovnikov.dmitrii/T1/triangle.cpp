#include "triangle.h"
#include <cmath>
#include <stdexcept>
#include "vector_t.h"
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
void Triangle::move(double delta_x, double delta_y)
{
  point1.x += delta_x;
  point1.y += delta_y;
  point2.x += delta_x;
  point2.y += delta_y;
  point3.x += delta_x;
  point3.y += delta_y;
}
void Triangle::move(point_t point)
{
  point_t point_center_of_gravity = this->getCenterOfGravity();
  this->move(point.x - point_center_of_gravity.x, point.y - point_center_of_gravity.y);
}
void Triangle::scale(double k)
{
  point_t point_center_of_gravity = this->getCenterOfGravity();
  vector_t direction1(point1.x - point_center_of_gravity.x, point1.y - point_center_of_gravity.y);
  vector_t direction2(point2.x - point_center_of_gravity.x, point2.y - point_center_of_gravity.y);
  vector_t direction3(point3.x - point_center_of_gravity.x, point3.y - point_center_of_gravity.y);
  direction1 *= k;
  direction2 *= k;
  direction3 *= k;
  point1.x = direction1.x + point_center_of_gravity.x;
  point1.y = direction1.y + point_center_of_gravity.y;
  point2.x = direction2.x + point_center_of_gravity.x;
  point2.y = direction2.y + point_center_of_gravity.y;
  point3.x = direction2.x + point_center_of_gravity.x;
  point3.y = direction2.y + point_center_of_gravity.y;
}
bool Triangle::isRectangular()
{
  vector_t side_vector_1(point1, point2);
  vector_t side_vector_2(point1, point3);
  vector_t side_vector_3(point2, point3);
  double side_1 = side_vector_1.getLength();
  double side_2 = side_vector_2.getLength();
  double side_3 = side_vector_3.getLength();
  return std::pow(side_1, 2) == std::pow(side_2, 2) + std::pow(side_3, 2) ||
    std::pow(side_2, 2) == std::pow(side_3, 2) + std::pow(side_1, 2) ||
    std::pow(side_3, 2) == std::pow(side_1, 2) + std::pow(side_2, 2);
}
point_t *Triangle::getPoints() const
{
  return new point_t[3]{point1, point2, point3};
}
point_t Triangle::getCenterOfGravity() const
{
  return point_t((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3);
}
bool Triangle::containsPoint(point_t point) const
{
  line_t line1(point1, point2);
  bool one_side_with_point3 = ((line1.A * point.x + line1.B * point.y + line1.C) * (line1.A * point3.x + line1.B * point3.y + line1.C)) > 0;
  line_t line2(point1, point3);
  bool one_side_with_point2 = ((line2.A * point.x + line2.B * point.y + line2.C) * (line2.A * point2.x + line2.B * point2.y + line2.C)) > 0;
  line_t line3(point2, point3);
  bool one_side_with_point1 = ((line3.A * point.x + line3.B * point.y + line3.C) * (line3.A * point1.x + line3.B * point1.y + line3.C)) > 0;
  return one_side_with_point1 && one_side_with_point2 && one_side_with_point3;
}
