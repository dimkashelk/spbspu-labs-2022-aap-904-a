#include "triangle.h"
#include <stdexcept>
#include <math.h>

Triangle::Triangle(const point_t& A, const point_t& B, const point_t& C) :
  name_("Triangle: "),
  A_(A),
  B_(B),
  C_(C)
{
  if (!isCorrectTriangle(A, B, C))
  {
    throw std::invalid_argument("invalid triangle\n");
  }
}

std::string Triangle::getName() const
{
  return name_;
}

double Triangle::getArea() const
{
  double ab_side = std::sqrt(pow(B_.x - A_.x, 2) + pow(B_.y - A_.y, 2));
  double ac_side = std::sqrt(pow(C_.x - A_.x, 2) + pow(C_.y - A_.y, 2));
  double bc_side = std::sqrt(pow(C_.x - B_.x, 2) + pow(C_.y - B_.y, 2));
  double halfmeter = (ab_side + ac_side + bc_side) / 2;
  return std::sqrt(halfmeter * (halfmeter - ab_side) * (halfmeter - ac_side) * (halfmeter - bc_side));
}

rectangle_t Triangle::getFrameRect() const
{
  double x_min = std::min(A_.x, std::min(B_.x, C_.x));
  double y_min = std::min(A_.y, std::min(B_.y, C_.y));
  double x_max = std::max(A_.x, std::min(B_.x, C_.x));
  double y_max = std::max(A_.y, std::min(B_.y, C_.y));
  point_t leftPoint{ x_min, y_min };
  point_t rightPoint{ x_max, y_max };
  point_t pos{ (leftPoint.x + rightPoint.x) / 2, (leftPoint.y + rightPoint.y) / 2 };
  return { rightPoint.x - leftPoint.x, rightPoint.y - leftPoint.y, pos };
}

void Triangle::move(point_t point)
{
  point_t pos = getCenterTriangle(A_, B_, C_);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void Triangle::scale(double k)
{
 /* point_t pos = getCenterTriangle(A_, B_, C_);
  A_ = scalePoint(A_, pos, k);
  B_ = scalePoint(B_, pos, k);
  C_ = scalePoint(C_, pos, k);*/
  point_t pos = getCenterTriangle(A_, B_, C_);
  A_.x = k * (A_.x - pos.x) + pos.x;
  A_.y = k * (A_.y - pos.y) + pos.y;
  B_.x = k * (B_.x - pos.x) + pos.x;
  B_.y = k * (B_.y - pos.y) + pos.y;
  C_.x = k * (C_.x - pos.x) + pos.x;
  C_.y = k * (C_.y - pos.y) + pos.y;
}

void Triangle::move(double dx, double dy)
{
  point_t dpoint{ dx, dy };
  //A_ = movePoint(A_, dpoint);
  //B_ = movePoint(B_, dpoint);
  //C_ = movePoint(C_, dpoint);
  A_ += dpoint;
  B_ += dpoint;
  C_ += dpoint;
}

Shape* Triangle::clone() const
{
  return new Triangle(A_, B_, C_);
}
