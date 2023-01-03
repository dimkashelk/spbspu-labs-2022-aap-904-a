#include "rectangle.h"
#include "base_types.h"
#include <cmath>

rectangle::rectangle(point_t point1, point_t point2):
  rectangle1(point1, point2)
{}
rectangle::rectangle(rectangle_t rectangle1):
  rectangle1(rectangle1)
{}
double rectangle::getArea() const
{
  return rectangle1.width * rectangle1.height;
}
rectangle_t rectangle::getFrameRect() const
{
  return rectangle1;
}
void rectangle::move(point_t point)
{
  rectangle1.pos = point;
}
void rectangle::move(double dx, double dy)
{
  rectangle1.pos.x += dx;
  rectangle1.pos.y += dy;
}
void rectangle::scale(double k)
{
  rectangle1.width *= std::fabs(k);
  rectangle1.height *= std::fabs(k);
}

shape *rectangle::clone() const
{
  return new rectangle(rectangle1);
}
