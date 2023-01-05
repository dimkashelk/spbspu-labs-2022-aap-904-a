#include "rectangle.h"
#include <stdexcept>

double turkin::Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

turkin::rectangle_t turkin::Rectangle::getFrameRect() const
{
  return rect_;
}

void turkin::Rectangle::move(double dx, double dy)
{
  rect_.position.x = rect_.position.x + dx;
  rect_.position.y = rect_.position.y + dy;
}

void turkin::Rectangle::move(point_t position)
{
  rect_.position = position;
}

void turkin::Rectangle::scale(double ds)
{
  if (ds <= 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  rect_.width = rect_.width * ds;
  rect_.height = rect_.height * ds;
}

turkin::Rectangle::Rectangle(point_t one, point_t two):
  rect_({{(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y})
{}

