#include <stdexcept>
#include "rectangle.h"
Rectangle::Rectangle(point_t A, point_t C):
  A_(A),
  B_{A.x, C.y},
  C_(C),
  D_{C.x, A.y}
{
  if (!goodRectangleInput())
  {
    throw std::invalid_argument("Bad rectangle input.");
  }
}
double Rectangle::getArea() const
{
  return (B_.y - A_.y) * (C_.x - B_.x);
}
rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frameRect{};
  frameRect.height = B_.y - A_.y;
  frameRect.width = C_.x - B_.x;
  frameRect.pos.x = (C_.x + B_.x) / 2;
  frameRect.pos.y = (B_.y + A_.y) / 2;
  return frameRect;
}
void Rectangle::move(double dx, double dy)
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
void Rectangle::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Rectangle::scale(double k)
{
  if (k > 0)
  {
    double centerX = getFrameRect().pos.x;
    double centerY = getFrameRect().pos.y;
    for (point_t p: {A_, B_, C_, D_})
    {
      p.x = k * (p.x - centerX) + centerX;
      p.y = k * (p.y - centerY) + centerY;
    }
  }
  else
  {
    throw std::invalid_argument("Invalid scaling coeff.");
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
