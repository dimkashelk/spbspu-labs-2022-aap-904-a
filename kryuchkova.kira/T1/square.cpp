#include "square.h"
#include <stdexcept>

kryuchkova::Square::Square(const point_t &lb_point, const double &length):
  lb_point(lb_point),
  length(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("It's not a Square");
  }
}

std::string kryuchkova::Square::getName() const
{
  return "SQUARE";
}

double kryuchkova::Square::getArea() const
{
  return length * length;
}

kryuchkova::rectangle_t kryuchkova::Square::getFrameRect() const
{
  point_t pos{length / 2 + lb_point.x, length / 2 + lb_point.y};
  return rectangle_t{length, length, pos};
}

void kryuchkova::Square::move(const double dx, const double dy)
{
  lb_point.x += dx;
  lb_point.y += dy;
}

void kryuchkova::Square::move(const point_t point)
{
  point_t pos{length / 2 + lb_point.x, length / 2 + lb_point.y};
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void kryuchkova::Square::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("scaling koef must be positive");
  }
  double dx = ((k - 1) * length) / 2;
  double dy = ((k - 1) * length) / 2;
  lb_point.x -= dx;
  lb_point.y -= dy;
  length *= k;
}

kryuchkova::Shape *kryuchkova::Square::clone() const
{
  return new Square(lb_point, length);
}
