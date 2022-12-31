#include "triangle.h"
#include <cmath>
#include <stdexcept>
#include "vector_t.h"
Triangle::Triangle()
{}
Triangle::Triangle(point_t p1, point_t p2, point_t p3)
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
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle(point_t(x1, y1), point_t(x2, y2), point_t(x3, y3))
{}
Triangle::Triangle(const Triangle &triangle)
{
  points[0] = triangle.points[0];
  points[1] = triangle.points[1];
  points[2] = triangle.points[2];
}
Triangle::Triangle(Triangle &&triangle)
{
  points[0] = triangle.points[0];
  points[1] = triangle.points[1];
  points[2] = triangle.points[2];
}
Triangle &Triangle::operator=(const Triangle &other)
{
  points[0] = other.points[0];
  points[1] = other.points[1];
  points[2] = other.points[2];
  return *this;
}
Triangle &Triangle::operator=(Triangle &&tmp)
{
  points[0] = tmp.points[0];
  points[1] = tmp.points[1];
  points[2] = tmp.points[2];
  return *this;
}
double Triangle::getArea() const
{
  // the area of the triangle_ is half of the length of the vector product
  // let 's make a matrix
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  vector_t a(points[1].x - points[0].x, points[1].y - points[0].y);
  vector_t b(points[2].x - points[0].x, points[2].y - points[0].y);
  double third_coord = a.x * b.y - a.y * b.x;
  // |a * b| = |c| = sqrt(x * x + y * y + z * z)
  // where x = 0, y = 0 => |c| = sqrt(z * z) = z
  return std::fabs(third_coord) / 2;
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
  double x_min = std::min(points[0].x, std::min(points[1].x, points[2].x));
  double y_min = std::min(points[0].y, std::min(points[1].y, points[2].y));
  double x_max = std::max(points[0].x, std::max(points[1].x, points[2].x));
  double y_max = std::max(points[0].y, std::max(points[1].y, points[2].y));
  return rectangle_t(point_t(x_min, y_min), point_t(x_max, y_max));
}
void Triangle::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < 3; i++)
  {
    points[i].x += delta_x;
    points[i].y += delta_y;
  }
}
void Triangle::move(point_t point)
{
  point_t point_center_of_gravity = this->getCenter();
  this->move(point.x - point_center_of_gravity.x, point.y - point_center_of_gravity.y);
}
void Triangle::scale(double k)
{
  point_t center_of_gravity = getCenter();
  for (size_t i = 0; i < 3; i++)
  {
    points[i].x = k * (points[i].x - center_of_gravity.x) + center_of_gravity.x;
    points[i].y = k * (points[i].y - center_of_gravity.y) + center_of_gravity.y;
  }
}
Shape* Triangle::clone() const
{
  Triangle *copy = new Triangle(points[0], points[1], points[2]);
  return copy;
}
bool Triangle::isRectangular()
{
  double square[3];
  for (size_t i = 0; i < 3; i++)
  {
    square[i] = std::pow(points[i].x - points[(i + 1) % 3].x, 2) + std::pow(points[i].y - points[(i + 1) % 3].y, 2);
  }
  return square[0]  == square[1] + square[2] || square[1] == square[0] + square[2] || square[2] == square[0] + square[1];
}
point_t* Triangle::getPoints() const
{
  return new point_t[3]{points[0], points[1], points[2]};
}
point_t Triangle::getCenter() const
{
  return point_t((points[0].x + points[1].x + points[2].x) / 3, (points[0].y + points[1].y + points[2].y) / 3);
}
bool Triangle::containsPoint(point_t point) const
{
  double A = points[1].y - points[0].y;
  double B = -(points[1].x - points[0].x);
  double C = -B * points[0].y - A * points[0].x;
  bool one_side_with_point3 = ((A * point.x + B * point.y + C) * (A * points[2].x + B * points[2].y + C)) > 0;
  A = points[2].y - points[0].y;
  B = -(points[2].x - points[0].x);
  C = -B * points[0].y - A * points[0].x;
  bool one_side_with_point2 = ((A * point.x + B * point.y + C) * (A * points[1].x + B * points[1].y + C)) > 0;
  A = points[2].y - points[1].y;
  B = -(points[2].x - points[1].x);
  C = -B * points[1].y - A * points[1].x;
  bool one_side_with_point1 = ((A * point.x + B * point.y + C) * (A * points[0].x + B * points[0].y + C)) > 0;
  return one_side_with_point1 && one_side_with_point2 && one_side_with_point3;
}
