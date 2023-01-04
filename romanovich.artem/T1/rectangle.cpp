#include <stdexcept>
#include "rectangle.h"
Rectangle::Rectangle(point_t *pointsArray) :
  A(pointsArray[0]),
  B(pointsArray[1]),
  C(pointsArray[2]),
  D(pointsArray[3])
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
    double centerX = getFrameRect().pos.x;
    double centerY = getFrameRect().pos.y;
    A.x = k * (A.x - centerX) + centerX;
    A.y = k * (A.y - centerY) + centerY;
    C.x = k * (C.x - centerX) + centerX;
    C.y = k * (C.y - centerY) + centerY;
    B.x = A.x;
    B.y = C.y;
    D.x = C.x;
    D.y = A.y;
  }
  else
  {
    throw std::invalid_argument("Invalid scaling coeff.");
  }
}
Rectangle *Rectangle::clone() const
{
  return nullptr;
}
