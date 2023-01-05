#include "concave.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <array>
Concave::Concave(point_t A, point_t B, point_t C, point_t D):
  A_(A),
  B_(B),
  C_(C),
  D_(D)
{
  if (!goodConcaveInput())
  {
    throw std::invalid_argument("Bad concave input.");
  }
}
bool Concave::goodConcaveInput() const
{
  std::array<double, 6> sides = getSides();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double max_ = std::max({a, b, c});
  double min_ = std::max({a, b, c});
  double midl_ = a + b + c - max_ - min_;
  bool firstThreeTriangle = (max_ < min_ + midl_);
  bool fourthLeftAB = ((D_.x - A_.x) * (B_.y - A_.y) - (D_.y - A_.y) * (B_.x - A_.x) > 0);
  bool fourthLeftBC = ((D_.x - B_.x) * (C_.y - B_.y) - (D_.y - B_.y) * (C_.x - B_.x) > 0);
  bool fourthLeftCA = ((D_.x - C_.x) * (A_.y - C_.y) - (D_.y - C_.y) * (A_.x - C_.x) > 0);
  if (fourthLeftAB && fourthLeftBC && fourthLeftCA)
  {
    return firstThreeTriangle;
  }
  if (!fourthLeftAB && !fourthLeftBC && !fourthLeftCA)
  {
    return firstThreeTriangle;
  }
  return false;
}
std::array<double, 6> Concave::getSides() const
{
  double a_x = A_.x - C_.x;
  double a_y = A_.y - C_.y;
  double b_x = C_.x - B_.x;
  double b_y = C_.y - B_.y;
  double c_y = A_.y - B_.y;
  double c_x = A_.x - B_.x;
  double a1_x = C_.x - D_.x;
  double a1_y = C_.y - D_.y;
  double b1_x = b_x;
  double b1_y = b_y;
  double c1_x = D_.x - B_.x;
  double c1_y = D_.y - B_.y;
  double a = sqrt(a_x * a_x + a_y * a_y);
  double b = sqrt(b_x * b_x + b_y * b_y);
  double c = sqrt(c_x * c_x + c_y * c_y);
  double a1 = sqrt(a1_x * a1_x + a1_y * a1_y);
  double b1 = sqrt(b1_x * b1_x + b1_y * b1_y);
  double c1 = sqrt(c1_x * c1_x + c1_y * c1_y);
  std::array<double, 6> arr = {a, b, c, a1, b1, c1};
  return arr;
}
double Concave::getArea() const
{
  std::array<double, 6> sides = getSides();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double a1 = sides[3];
  double b1 = sides[4];
  double c1 = sides[5];
  double p1 = (a + b + c) / 2;
  double p2 = (a1 + b1 + c1) / 2;
  double s1 = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c));
  double s2 = sqrt(p2 * (p2 - a1) * (p2 - b1) * (p2 - c1));
  return s1 - s2;
}
rectangle_t Concave::getFrameRect() const
{
  double sup = std::max({A_.y, B_.y, C_.y});
  double inf = std::min({A_.y, B_.y, C_.y});
  double left = std::min({A_.x, B_.x, C_.x});
  double right = std::max({A_.x, B_.x, C_.x});
  return {(right + left) / 2, (sup + inf) / 2, right - left, sup - inf};
}
void Concave::move(double dx, double dy)
{
  A_.x += dx;
  B_.x += dx;
  C_.x += dx;
  D_.x += dx;
  A_.y += dy;
  B_.y += dy;
  C_.y += dy;
  D_.y += dy;
}
void Concave::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Concave::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
  double centerX = getFrameRect().pos.x;
  double centerY = getFrameRect().pos.y;
  for (point_t p: {A_, B_, C_, D_})
  {
    p.x = k * (p.x - centerX) + centerX;
    p.y = k * (p.y - centerY) + centerY;
  }
}
Shape *Concave::clone() const
{
  return nullptr;
}
