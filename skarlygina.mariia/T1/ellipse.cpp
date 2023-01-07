#include "ellipse.h"
#include <stdexcept>

Ellipse::Ellipse(point_t center, double radius_vertical, double radius_horizontal):
  center_(center),
  radius_vertical_(radius_vertical),
  radius_horizontal_(radius_horizontal)
{}

double Ellipse::getArea() const
{
  const double pi = 3.1416;
  return (pi * radius_vertical_ * radius_horizontal_);
}
rectangle_t Ellipse::getFrameRectangle() const
{
  rectangle_t frame_rectangle{};
  frame_rectangle.height = radius_vertical_ * 2;
  frame_rectangle.width = radius_horizontal_ * 2;
  frame_rectangle.position.x = center_.x;
  frame_rectangle.position.y = center_.y;
  return frame_rectangle;
}

void Ellipse::move(double dx, double dy)
{
  center_ = baseFunctions::SummVector(center_, dx, dy);
}

void Ellipse::move(point_t position)
{
  double dx = baseFunctions::findDifference(position.x, getFrameRectangle().position.x);
  double dy = baseFunctions::findDifference(position.y, getFrameRectangle().position.y);
  move(dx, dy);
}

void Ellipse::scale(double k)
{
  double center_x = getFrameRectangle().position.x;
  double center_y = getFrameRectangle().position.y;
  radius_horizontal_ *= k;
  radius_vertical_ *= k;
  center_.x = center_x * k;
  center_.y = center_y * k;
}
