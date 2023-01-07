#include "ring.h"
#include <stdexcept>

Ring::Ring(point_t center, double radius_small, double radius_big):
  center_(center),
  radius_small_(radius_small),
  radius_big_(radius_big)
{}

double Ring::getArea() const
{
  const double pi = 3.1416;
  return (pi * radius_big_ * radius_big_ - pi * radius_small_ * radius_small_);
}

rectangle_t Ring::getFrameRectangle() const
{
  rectangle_t frame_rectangle{};
  frame_rectangle.height = radius_big_ * 2;
  frame_rectangle.width = radius_big_ * 2;
  frame_rectangle.position.x = center_.x;
  frame_rectangle.position.y = center_.y;
  return frame_rectangle;
}

void Ring::move(double dx, double dy)
{
  center_ = baseFunctions::SummVector(center_, dx, dy);
}

void Ring::move(point_t position)
{
  double dx = baseFunctions::findDifference(position.x, getFrameRectangle().position.x);
  double dy = baseFunctions::findDifference(position.y, getFrameRectangle().position.y);
  move(dx, dy);
}

void Ring::scale(double k)
{
  double center_x = getFrameRectangle().position.x;
  double center_y = getFrameRectangle().position.y;
  radius_small_ *= k;
  radius_big_ *= k;
  center_.x = center_x * k;
  center_.y = center_y * k;
}
