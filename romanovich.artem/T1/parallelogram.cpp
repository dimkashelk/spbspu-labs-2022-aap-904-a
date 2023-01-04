#include "parallelogram.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
Parallelogram::Parallelogram(point_t A, point_t B, point_t C):
  A(A),
  B(B),
  C(C),
  D{A.x - B.x + C.x, A.y - B.y + C.y}
{
  if (!goodParallelogramInput())
  {
    throw std::invalid_argument("Bad parallelogram input.");
  }
}
double Parallelogram::getArea() const
{
  double ax = C.x - B.x;
  double ay = C.y - B.y;
  double by = A.y - B.y;
  double bx = A.x - B.x;
  double cx = C.x - A.x;
  double cy = C.y - A.y;
  double a = sqrt(ax * ax + ay * ay);
  double b = sqrt(bx * bx + by * by);
  double c = sqrt(cx * cx + cy * cy);
  double p = (a + b + c) / 2;
  return 2 * sqrt(p * (p - a) * (p - b) * (p - c));
}
rectangle_t Parallelogram::getFrameRect() const
{
  rectangle_t frameRect{};
  double sup = std::max({A.y, B.y, C.y});
  double inf = std::min({A.y, B.y, C.y});
  frameRect.height = sup - inf;
  double left = std::min({A.x, B.x, C.x});
  double right = std::max({A.x, B.x, C.x});
  frameRect.width = right - left;
  frameRect.pos.x = (right + left) / 2;
  frameRect.pos.y = (sup + inf) / 2;
  return frameRect;
}
void Parallelogram::move(double dx, double dy)
{
  A.x += dx;
  B.x += dx;
  C.x += dx;
  D.x += dx;
  A.y += dy;
  B.y += dy;
  C.y += dy;
  D.y += dy;
}
void Parallelogram::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Parallelogram::scale(double k)
{
  if (k > 0)
  {
    double centerX = getFrameRect().pos.x;
    double centerY = getFrameRect().pos.y;
    A.x = k * (A.x - centerX) + centerX;
    A.y = k * (A.y - centerY) + centerY;
    C.x = k * (C.x - centerX) + centerX;
    C.y = k * (C.y - centerY) + centerY;
    B.x = k * (B.x - centerX) + centerX;
    B.y = k * (B.y - centerY) + centerY;
    D.x = k * (D.x - centerX) + centerX;
    D.y = k * (D.y - centerY) + centerY;
  }
  else
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
}
Shape *Parallelogram::clone() const
{
  return nullptr;
}
bool Parallelogram::goodParallelogramInput() const
{
  return (((A.y == B.y) || (B.y == C.y)) && (A.y - B.y != C.y - B.y));
}
