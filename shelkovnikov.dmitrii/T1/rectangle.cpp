#include "rectangle.h"
Rectangle::Rectangle(point_t point, double width, double height):
  rectangle(point, width, height)
{}
Rectangle::Rectangle(rectangle_t rectangle):
  rectangle(rectangle)
{}
double Rectangle::getArea() const
{
  return rectangle.width * rectangle.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle;
}
void Rectangle::move(double delta_x, double delta_y)
{
  rectangle.point.x += delta_x;
  rectangle.point.y += delta_y;
}
void Rectangle::move(point_t point) const
{
  rectangle.point = point;
}
