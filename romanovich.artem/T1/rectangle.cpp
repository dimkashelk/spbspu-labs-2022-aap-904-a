#include "rectangle.h"
#include <stdexcept>
Rectangle::Rectangle(point_t A, point_t C):
  A_(A),
  //B_{A.x, C.y},
  C_(C)
//D_{C.x, A.y}
{
  if (!goodRectangleInput())
  {
    throw std::invalid_argument("Bad rectangle input.");
  }
}
double Rectangle::getArea() const
{
  return (C_.y - A_.y) * (C_.x - A_.x);
}
rectangle_t Rectangle::getFrameRect() const
{
  return {(C_.x + A_.x) / 2, (C_.y + A_.y) / 2, C_.x - A_.x, C_.y - A_.y};
}
void Rectangle::move(double dx, double dy)
{
  for (point_t p: {A_, C_})
  {
    p.x += dx;
    p.y += dy;
  }
}
void Rectangle::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
  double centerX = getFrameRect().pos.x;
  double centerY = getFrameRect().pos.y;
  for (point_t p: {A_, C_})
  {
    p.x = k * (p.x - centerX) + centerX;
    p.y = k * (p.y - centerY) + centerY;
  }
}
Shape *Rectangle::clone() const
{
  return nullptr;
}
bool Rectangle::goodRectangleInput() const
{
  return (A_.x < C_.x && A_.y < C_.y);
}
