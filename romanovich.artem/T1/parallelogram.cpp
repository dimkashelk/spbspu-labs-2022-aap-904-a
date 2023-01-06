#include "parallelogram.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <iostream>
Parallelogram::Parallelogram(const point_t &A, const point_t &B, const point_t &C):
  a_(A),
  b_(B),
  c_(C)
{
  if (!goodParallelogramInput())
  {
    throw std::invalid_argument("Bad parallelogram input.");
  }
}
double Parallelogram::getArea() const
{
  double a = twoPointsDistance(b_, c_);
  double b = twoPointsDistance(a_, b_);
  double c = twoPointsDistance(a_, c_);
  double p = (a + b + c) / 2;
  return 2 * std::sqrt(p * (p - a) * (p - b) * (p - c));
}
rectangle_t Parallelogram::getFrameRect() const
{
  double sup = std::max({a_.y, b_.y, c_.y});
  double inf = std::min({a_.y, b_.y, c_.y});
  double left = std::min({a_.x, b_.x, c_.x});
  double right = std::max({a_.x, b_.x, c_.x});
  return {(right + left) / 2, (sup + inf) / 2, right - left, sup - inf};
}
void Parallelogram::move(double dx, double dy)
{
  point_t *points[3]{&a_, &b_, &c_};
  for (point_t *p: points)
  {
    addVectorToPoint(p, dx, dy);
  }
}
void Parallelogram::move(const point_t &position)
{
  point_t s = shift(position, getFrameRect().pos);
  move(s.x, s.y);
}
void Parallelogram::scale(double k)
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  point_t *point[3]{&a_, &b_, &c_};
  for (point_t *p: point)
  {
    multiplyVector(center, p, k);
  }
}
Shape *Parallelogram::clone() const
{
  return new Parallelogram(a_, b_, c_);
}
bool Parallelogram::goodParallelogramInput() const
{
  return (((a_.y == b_.y) || (b_.y == c_.y)) && (a_.y - b_.y != c_.y - b_.y));
}
