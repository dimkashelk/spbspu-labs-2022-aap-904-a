#include "ellipse.h"
#include <stdexcept>

double turkin::Ellipse::getArea() const
{
  return r1 * r2 * 3.14159265358979323846;
}

turkin::rectangle_t turkin::Ellipse::getFrameRect() const
{
  return rect_;
}

void turkin::Ellipse::move(double dx, double dy)
{
  rect_.position.x = rect_.position.x + dx;
  rect_.position.y = rect_.position.y + dy;
}

void turkin::Ellipse::move(point_t position)
{
  rect_.position = position;
}

void turkin::Ellipse::scale(double ds)
{
  if (ds <= 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  r1 = r1 * ds;
  r2 = r2 * ds;
  rect_.width = r1 * 2.0;
  rect_.height = r2 * 2.0;
}

turkin::Ellipse::Ellipse(point_t one, double nr1, double nr2):
  rect_({{one.x, one.y}, nr1 * 2.0, nr2 * 2.0}),
  r1(nr1),
  r2(nr2)
{}

