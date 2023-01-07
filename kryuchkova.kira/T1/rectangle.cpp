#include "rectangle.h"
#include <stdexcept>

kryuchkova::Rectangle::Rectangle(const point_t & ld_point, const point_t & ru_point):
  lb_point(lb_point),
  ru_point(ru_point)
{
  if (lb_point.x >= ru_point.x || lb_point.y >= ru_point.y)
  {
    throw std::invalid_argument("It's not a rectangle");
  }
}

double kryuchkova::Rectangle::getArea()
{
  double area = (ru_point.x - lb_point.x) * (ru_point.y - lb_point.y);
  return area;
}

kryuchkova::rectangle_t kryuchkova::Rectangle::getFrameRect() const
{
  double width = ru_point.x - lb_point.x;
  double height = ru_point.y - lb_point.y;
  point_t pos((lb_point.x + ru_point.x) / 2.0, (lb_point.y + ru_point.y) / 2.0);
  return rectangle_t(width, height, pos);
}

void kryuchkova::Rectangle::move(double dx, double dy)
{
  lb_point.x += dx;
  lb_point.y += dy;
  ru_point.x += dx;
  ru_point.y += dy;
}

void kryuchkova::Rectangle::move(point_t point)
{
  point_t pos((lb_point.x + ru_point.x) / 2.0, (lb_point.y + ru_point.y) / 2.0);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void kryuchkova::Rectangle::scale(double k)
{
  double width = ru_point.x - lb_point.x;
  double height = ru_point.y - lb_point.y;
  double dx = ((k - 1) * width) / 2;
  double dy = ((k - 1) * height) / 2;
  lb_point.x -= dx;
  lb_point.y -= dy;
  ru_point.x += dx;
  ru_point.y += dy;
}
