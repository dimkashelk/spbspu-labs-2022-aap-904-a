#include "circle.h"

turkin::Circle::Circle(turkin::point_t position, double radius):
  Rectangle({position.x - radius, position.y - radius}, {position.x + radius, position.y + radius})
{}

double turkin::Circle::getArea() const
{
  return 3.14159265358979323846 * rect_.width * rect_.width / 2 / 2;
}

