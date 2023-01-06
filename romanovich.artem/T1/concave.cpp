#include "concave.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <array>
Concave::Concave(const point_t &A, const point_t &B, const point_t &C, const point_t &D):
  a_(A),
  b_(B),
  c_(C),
  d_(D)
{
  if (!goodConcaveInput())
  {
    throw std::invalid_argument("Bad concave input.");
  }
}
bool Concave::goodConcaveInput() const
{
  std::array<double, 6> sides = splitIntoTriangles();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double maxSide = std::max({a, b, c});
  double minSide = std::max({a, b, c});
  double midlSide = a + b + c - maxSide - minSide;
  bool firstThreeTriangle = (maxSide < minSide + midlSide);
  bool fourthLeftAB = ((d_.x - a_.x) * (b_.y - a_.y) - (d_.y - a_.y) * (b_.x - a_.x) > 0);
  bool fourthLeftBC = ((d_.x - b_.x) * (c_.y - b_.y) - (d_.y - b_.y) * (c_.x - b_.x) > 0);
  bool fourthLeftCA = ((d_.x - c_.x) * (a_.y - c_.y) - (d_.y - c_.y) * (a_.x - c_.x) > 0);
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
std::array<double, 6> Concave::splitIntoTriangles() const
{
  double a = twoPointsDistance(a_, c_);
  double b = twoPointsDistance(c_, b_);
  double c = twoPointsDistance(a_, b_);
  double a1 = twoPointsDistance(c_, d_);
  double b1 = b;
  double c1 = twoPointsDistance(d_, b_);
  std::array<double, 6> arr = {a, b, c, a1, b1, c1};
  return arr;
}
double Concave::getArea() const
{
  std::array<double, 6> sides = splitIntoTriangles();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double a1 = sides[3];
  double b1 = sides[4];
  double c1 = sides[5];
  double p = (a + b + c) / 2;
  double p1 = (a1 + b1 + c1) / 2;
  double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double s1 = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c1));
  return s - s1;
}
rectangle_t Concave::getFrameRect() const
{
  double sup = std::max({a_.y, b_.y, c_.y});
  double inf = std::min({a_.y, b_.y, c_.y});
  double left = std::min({a_.x, b_.x, c_.x});
  double right = std::max({a_.x, b_.x, c_.x});
  return {(right + left) / 2, (sup + inf) / 2, right - left, sup - inf};
}
void Concave::move(double dx, double dy)
{
  point_t *points[4]{&a_, &b_, &c_, &d_};
  for (point_t *p: points)
  {
    p->x += dx;
    p->y += dy;
  }
}
void Concave::move(const point_t &position)
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
  point_t *points[4]{&a_, &b_, &c_, &d_};
  for (point_t *p: points)
  {
    p->x = k * (p->x - centerX) + centerX;
    p->y = k * (p->y - centerY) + centerY;
  }
}
Shape *Concave::clone() const
{
  return new Concave(a_, b_, c_, d_);
}
