#include "ellipse.h"
#include <cmath>

double turkin::Ellipse::getArea() const
{
  return r1 * r2 * M_PI;
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

void turkin::Ellipse::move(turkin::point_t position)
{
  rect_.position = position;
}

void turkin::Ellipse::scale(double ds)
{
  r1 = r1 * ds;
  r2 = r2 * ds;
  rect_.width = r1 * 2.0;
  rect_.height = r2 * 2.0;
}

turkin::Ellipse::Ellipse(turkin::point_t one, double nr1, double nr2):
  rect_(one, nr1, nr2),
  r1(nr1),
  r2(nr2)
{}

