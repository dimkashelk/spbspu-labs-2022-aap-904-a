#include "parallelogram.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
Parallelogram::Parallelogram(point_t A, point_t B, point_t C):
  A_(A),
  B_(B),
  C_(C)
//D_{A.x - B.x + C.x, A.y - B.y + C.y}
{
  if (!goodParallelogramInput())
  {
    throw std::invalid_argument("Bad parallelogram input.");
  }
}
double Parallelogram::getArea() const
{
  double ax = C_.x - B_.x;
  double ay = C_.y - B_.y;
  double by = A_.y - B_.y;
  double bx = A_.x - B_.x;
  double cx = C_.x - A_.x;
  double cy = C_.y - A_.y;
  double a = sqrt(ax * ax + ay * ay);
  double b = sqrt(bx * bx + by * by);
  double c = sqrt(cx * cx + cy * cy);
  double p = (a + b + c) / 2;
  return 2 * sqrt(p * (p - a) * (p - b) * (p - c));
}
rectangle_t Parallelogram::getFrameRect() const
{
  double sup = std::max({A_.y, B_.y, C_.y});
  double inf = std::min({A_.y, B_.y, C_.y});
  double left = std::min({A_.x, B_.x, C_.x});
  double right = std::max({A_.x, B_.x, C_.x});
  return {(right + left) / 2, (sup + inf) / 2, right - left, sup - inf};
}
void Parallelogram::move(double dx, double dy)
{
  point_t *points[3]{&A_, &B_, &C_};
  for (point_t *p: points)
  {
    p->x += dx;
    p->y += dy;
  }
}
void Parallelogram::move(point_t position)
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
  double centerX = getFrameRect().pos.x;
  double centerY = getFrameRect().pos.y;
  point_t *points[3]{&A_, &B_, &C_};
  for (point_t *p: points)
  {
    p->x = k * (p->x - centerX) + centerX;
    p->y = k * (p->y - centerY) + centerY;
  }
}
Shape *Parallelogram::clone() const
{
  return new Parallelogram(A_, B_, C_);
}
bool Parallelogram::goodParallelogramInput() const
{
  return (((A_.y == B_.y) || (B_.y == C_.y)) && (A_.y - B_.y != C_.y - B_.y));
}
