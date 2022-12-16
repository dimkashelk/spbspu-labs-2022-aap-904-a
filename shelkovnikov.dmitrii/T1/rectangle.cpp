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
