#include "rectangle.h"
#include "base_types.h"
#include <iostream>
#include <cmath>

Rectangle::Rectangle(point_t point1, point_t point2):
  rectangle1(point1, point2)
{}
Rectangle::Rectangle(rectangle_t rectangle1):
  rectangle1(rectangle1)
{}
double Rectangle::getArea() const
{
  return rectangle1.width * rectangle1.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle1;
}
void Rectangle::move(point_t point)
{
  rectangle1.pos = point;
}
void Rectangle::move(double dx, double dy)
{
  rectangle1.pos.x += dx;
  rectangle1.pos.y += dy;
}
void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    std::cout << "incorrect value";
  }
  else
  {
  rectangle1.width *= std::fabs(k);
  rectangle1.height *= std::fabs(k);
  }
}
Shape *Rectangle::clone() const
{
  return new Rectangle(rectangle1);
}
