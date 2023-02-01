#include "triangle.h"
#include <stdexcept>

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
  double width = B_.x - C_.x;
  double height = C_.y - A_.y;
  return { width, height, getCenterRectangle(A_, B_) };
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
  point_t pos = getCenterTriangle(A_, B_, C_);
  A_ = scalePoint(A_, pos, k);
  B_ = scalePoint(B_, pos, k);
  C_ = scalePoint(C_, pos, k);
}

void Triangle::move(double dx, double dy)
{
  point_t dpoint{ dx, dy };
  A_ = movePoint(A_, dpoint);
  B_ = movePoint(B_, dpoint);
  C_ = movePoint(C_, dpoint);
}

Shape* Triangle::clone() const
{
  return new Triangle(A_, B_, C_);
}
