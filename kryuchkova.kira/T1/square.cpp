#include "square.h"
#include <stdexcept>

kryuchkova::Square::Square(const point_t & ld_point, const double & length):
  lb_point(lb_point),
  length(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("It's not a Square");
  }
}

double kryuchkova::Square::getArea()
{
  return length * length;
}

kryuchkova::rectangle_t kryuchkova::Square::getFrameRect() const
{
  point_t pos(length / 2 + lb_point.x, length / 2 + lb_point.y);
  return rectangle_t(length, length, pos);
}

void kryuchkova::Square::move(double dx, double dy)
{
  lb_point.x += dx;
  lb_point.y += dy;
}

void kryuchkova::Square::move(point_t point)
{
  point_t pos(length / 2 + lb_point.x, length / 2 + lb_point.y);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void kryuchkova::Square::scale(double k)
{
  double dx = ((k - 1) * length) / 2;
  double dy = ((k - 1) * length) / 2;
  lb_point.x -= dx;
  lb_point.y -= dy;
  length *= k;
}
