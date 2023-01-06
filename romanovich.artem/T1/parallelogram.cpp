#include "parallelogram.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
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
    p->x += dx;
    p->y += dy;
  }
}
void Parallelogram::move(const point_t &position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Parallelogram::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  point_t point[3]{a_, b_, c_};
  for (size_t i = 0; i < 3; ++i)
  {
    multiplyVector(center, &point[i], k);
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
