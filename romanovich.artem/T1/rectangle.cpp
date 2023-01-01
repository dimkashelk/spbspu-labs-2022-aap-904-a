#include "rectangle.h"
#include <iostream>
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
  frameRect.pos.x = (C.x + B.x) / 2;
  frameRect.pos.y = (B.y + A.y) / 2;
  return frameRect;
}
void Rectangle::move(double dx, double dy)
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
    A.x = k * (A.x - getFrameRect().pos.x) + getFrameRect().pos.x;
    A.y = k * (A.y - getFrameRect().pos.y) + getFrameRect().pos.y;
    B.x = k * (B.x - getFrameRect().pos.x) + getFrameRect().pos.x;
    B.y = k * (B.y - getFrameRect().pos.y) + getFrameRect().pos.y;
    C.x = k * (C.x - getFrameRect().pos.x) + getFrameRect().pos.x;
    C.y = k * (C.y - getFrameRect().pos.y) + getFrameRect().pos.y;
    D.x = k * (D.x - getFrameRect().pos.x) + getFrameRect().pos.x;
    D.y = k * (D.y - getFrameRect().pos.y) + getFrameRect().pos.y;
  }
}
Rectangle *Rectangle::clone() const
{
  return nullptr;
}
void Rectangle::isoScale(point_t *pointsArray, double x, double y, double k)
{
  Rectangle rectangle(pointsArray[0], pointsArray[1], pointsArray[2], pointsArray[3]);
  point_t shiftPosition{};
  shiftPosition.x = x;
  shiftPosition.y = y;
  rectangle.move(shiftPosition);
  double dx = shiftPosition.x - rectangle.getFrameRect().pos.x;
  double dy = shiftPosition.y - rectangle.getFrameRect().pos.y;
  rectangle.scale(k);
  dx *= k;
  dy *= k;
  rectangle.move(5, 5);
}
