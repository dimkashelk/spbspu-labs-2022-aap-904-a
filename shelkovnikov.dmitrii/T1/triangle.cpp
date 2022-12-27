#include "triangle.h"
#include <cmath>
#include <stdexcept>
#include "vector_t.h"
#include "line_t.h"
Triangle::Triangle():
  point1_(0.0, 0.0),
  point2_(0.0, 0.0),
  point3_(0.0, 0.0)
{}
Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  point1_(p1),
  point2_(p2),
  point3_(p3)
{
  double side1 = std::sqrt(pow((point1_.x - point2_.x), 2) + pow(point1_.y - point2_.y, 2));
  double side2 = std::sqrt(pow((point1_.x - point3_.x), 2) + pow(point1_.y - point3_.y, 2));
  double side3 = std::sqrt(pow((point3_.x - point2_.x), 2) + pow(point3_.y - point2_.y, 2));
  if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2)
  {
    throw std::logic_error("It's not a triangle_");
  }
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle(point_t(x1, y1), point_t(x2, y2), point_t(x3, y3))
{}
Triangle::Triangle(const Triangle &triangle):
  point1_(triangle.point1_),
  point2_(triangle.point2_),
  point3_(triangle.point3_)
{}
Triangle::Triangle(Triangle &&triangle):
  point1_(triangle.point1_),
  point2_(triangle.point2_),
  point3_(triangle.point3_)
{}
Triangle &Triangle::operator=(const Triangle &other)
{
  point1_ = other.point1_;
  point2_ = other.point2_;
  point3_ = other.point3_;
  return *this;
}
Triangle &Triangle::operator=(Triangle &&tmp)
{
  point1_ = tmp.point1_;
  point2_ = tmp.point2_;
  point3_ = tmp.point3_;
  return *this;
}
double Triangle::getArea() const
{
  // the area of the triangle_ is half of the length of the vector product
  // let 's make a matrix
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  vector_t a(point2_.x - point1_.x, point2_.y - point1_.y);
  vector_t b(point3_.x - point1_.x, point3_.y - point1_.y);
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
  double x_min = std::min(point1_.x, std::min(point2_.x, point3_.x));
  double y_min = std::min(point1_.y, std::min(point2_.y, point3_.y));
  double x_max = std::max(point1_.x, std::max(point2_.x, point3_.x));
  double y_max = std::max(point1_.y, std::max(point2_.y, point3_.y));
  return rectangle_t(x_min, y_min, x_max, y_max);
}
void Triangle::move(double delta_x, double delta_y)
{
  point1_.x += delta_x;
  point1_.y += delta_y;
  point2_.x += delta_x;
  point2_.y += delta_y;
  point3_.x += delta_x;
  point3_.y += delta_y;
}
void Triangle::move(point_t point)
{
  point_t point_center_of_gravity = this->getCenter();
  this->move(point.x - point_center_of_gravity.x, point.y - point_center_of_gravity.y);
}
void Triangle::scale(double k)
{
  point_t point_center_of_gravity = this->getCenter();
  vector_t direction1(point1_.x - point_center_of_gravity.x, point1_.y - point_center_of_gravity.y);
  vector_t direction2(point2_.x - point_center_of_gravity.x, point2_.y - point_center_of_gravity.y);
  vector_t direction3(point3_.x - point_center_of_gravity.x, point3_.y - point_center_of_gravity.y);
  direction1 *= k;
  direction2 *= k;
  direction3 *= k;
  point1_.x = direction1.x + point_center_of_gravity.x;
  point1_.y = direction1.y + point_center_of_gravity.y;
  point2_.x = direction2.x + point_center_of_gravity.x;
  point2_.y = direction2.y + point_center_of_gravity.y;
  point3_.x = direction2.x + point_center_of_gravity.x;
  point3_.y = direction2.y + point_center_of_gravity.y;
}
Shape *Triangle::clone() const
{
  Triangle *copy = new Triangle(point1_, point2_, point3_);
  return copy;
}
bool Triangle::isRectangular()
{
  vector_t side_vector_1(point1_, point2_);
  vector_t side_vector_2(point1_, point3_);
  vector_t side_vector_3(point2_, point3_);
  double side_1 = side_vector_1.getLength();
  double side_2 = side_vector_2.getLength();
  double side_3 = side_vector_3.getLength();
  return std::pow(side_1, 2) == std::pow(side_2, 2) + std::pow(side_3, 2) ||
    std::pow(side_2, 2) == std::pow(side_3, 2) + std::pow(side_1, 2) ||
    std::pow(side_3, 2) == std::pow(side_1, 2) + std::pow(side_2, 2);
}
point_t *Triangle::getPoints() const
{
  return new point_t[3]{point1_, point2_, point3_};
}
point_t Triangle::getCenter() const
{
  return point_t((point1_.x + point2_.x + point3_.x) / 3, (point1_.y + point2_.y + point3_.y) / 3);
}
bool Triangle::containsPoint(point_t point) const
{
  line_t line1(point1_, point2_);
  bool one_side_with_point3 = ((line1.A * point.x + line1.B * point.y + line1.C) * (line1.A * point3_.x + line1.B * point3_.y + line1.C)) > 0;
  line_t line2(point1_, point3_);
  bool one_side_with_point2 = ((line2.A * point.x + line2.B * point.y + line2.C) * (line2.A * point2_.x + line2.B * point2_.y + line2.C)) > 0;
  line_t line3(point2_, point3_);
  bool one_side_with_point1 = ((line3.A * point.x + line3.B * point.y + line3.C) * (line3.A * point1_.x + line3.B * point1_.y + line3.C)) > 0;
  return one_side_with_point1 && one_side_with_point2 && one_side_with_point3;
}
