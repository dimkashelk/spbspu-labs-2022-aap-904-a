#include "circle.h"
#include <stdexcept>

kryuchkova::Circle::Circle(const point_t &pos, const double radius):
  pos(pos),
  radius(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("It's not a Circle");
  }
}

std::string kryuchkova::Circle::getName() const
{
  return "CIRCLE";
}

double kryuchkova::Circle::getArea() const
{
  double pi = 3.14159265358979323846;
  return pi * radius * radius;
}

kryuchkova::rectangle_t kryuchkova::Circle::getFrameRect() const
{
  return rectangle_t{radius * 2, radius * 2, pos};
}

void kryuchkova::Circle::move(double dx, double dy)
{
  movePoint(pos, point_t{dx, dy});
}

void kryuchkova::Circle::move(point_t point)
{
  movePoint(pos, point);
}

void kryuchkova::Circle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("scaling koef must be positive");
  }
  radius *= k;
}

kryuchkova::Shape *kryuchkova::Circle::clone() const
{
  return new Circle(pos, radius);
}
