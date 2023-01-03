#include "rectangle.h"

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

void turkin::Rectangle::move(turkin::point_t position)
{
  rect_.position = position;
}

void turkin::Rectangle::scale(double ds)
{
  rect_.width = rect_.width * ds;
  rect_.height = rect_.height * ds;
}

turkin::Rectangle::Rectangle(turkin::point_t one, turkin::point_t two):
  rect_(one, two)
{}

turkin::Rectangle::Rectangle(turkin::point_t one, double side):
  rect_(one, side)
{}

