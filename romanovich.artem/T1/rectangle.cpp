#include "rectangle.h"
Rectangle::Rectangle(point_t A_, point_t B_, point_t C_, point_t D_) :
  A(A_),
  B(B_),
  C(C_),
  D(D_)
{
}
double Rectangle::getArea() const
{
  return (B.y - A.y) * (C.x - B.x);
}
rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t frameRect{};
  frameRect.height = B.y - A.y;
  frameRect.width = C.x - B.x;
  frameRect.pos.x = (C.x - B.x) / 2;
  frameRect.pos.y = (B.y - A.y) / 2;
  return frameRect;
}
void Rectangle::move(double dx, double dy)
{
  A.x, B.x, C.x, D.x += dx;
  A.y, B.y, C.y, D.y += dy;
}
void Rectangle::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}
void Rectangle::scale(double k)
{
}
Rectangle *Rectangle::clone() const
{
  return nullptr;
}
