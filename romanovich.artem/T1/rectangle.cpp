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
  double area = -1;
  if (A.x == B.x)
  {
    area = (A.y - B.y) * (B.x - C.x);
  }
  else
  {
    area = (A.x - B.x) * (B.y - C.y);
  }
  return area > 0 ? area : -area;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t();
}
void Rectangle::move(double dx, double dy)
{
}
void Rectangle::move(point_t position)
{
}
void Rectangle::scale(double k)
{
}
Rectangle *Rectangle::clone() const
{
  return nullptr;
}
