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
  rect_.pos.x = rect_.pos.x + dx;
  rect_.pos.y = rect_.pos.y + dy;
}

void turkin::Ellipse::move(point_t position)
{
  rect_.pos = position;
}

void turkin::Ellipse::scaleW(double ds)
{
  r1 = r1 * ds;
  r2 = r2 * ds;
  rect_.width = r1 * 2.0;
  rect_.height = r2 * 2.0;
}

turkin::Ellipse::Ellipse(point_t one, double nr1, double nr2):
  rect_({{one.x, one.y}, nr1 * 2.0, nr2 * 2.0}),
  r1(nr1),
  r2(nr2)
{
  if (r1 <= 0.0 || r2 <= 0.0)
  {
    throw std::logic_error("bad ellipse size");
  }
}

