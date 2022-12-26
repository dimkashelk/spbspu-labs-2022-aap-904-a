#include "rectangle.h"
Rectangle::Rectangle(point_t point, double width, double height):
  rectangle(point, width, height)
{}
Rectangle::Rectangle(rectangle_t rectangle):
  rectangle(rectangle)
{}
Rectangle::Rectangle(double x1, double y1, double x2, double y2):
  rectangle(x1, y1, x2, y2)
{}
Rectangle::Rectangle(const Rectangle &rect):
  rectangle(rect.rectangle)
{}
Rectangle::Rectangle(Rectangle &&rect):
  rectangle(rect.rectangle)
{}
Rectangle &Rectangle::operator=(const Rectangle &other)
{
  rectangle = other.rectangle;
}
double Rectangle::getArea() const
{
  return rectangle.width * rectangle.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle;
}
void Rectangle::move(point_t point)
{
  rectangle.point = point;
}
void Rectangle::move(double delta_x, double delta_y)
{
  rectangle.point.x += delta_x;
  rectangle.point.y += delta_y;
}
void Rectangle::scale(double k)
{
  rectangle.width *= k;
  rectangle.height *= k;
}
Shape *Rectangle::clone() const
{
  return new Rectangle(rectangle);
}
