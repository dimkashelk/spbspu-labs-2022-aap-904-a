#include "ellipse.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>

Ellipse::Ellipse(point_t center, double axis_vertical, double axis_horizontal):
  center_(center),
  axis_vertical_(axis_vertical),
  axis_horizontal_(axis_horizontal)
{}

double Ellipse::getArea() const
{
  const double pi = M_PI;
  return (pi * (axis_vertical_ / 2) * (axis_horizontal_ / 2));
}
rectangle_t Ellipse::getFrameRectangle() const
{
  rectangle_t frame_rectangle{};
  frame_rectangle.height = axis_vertical_;
  frame_rectangle.width = axis_horizontal_;
  frame_rectangle.position.x = center_.x;
  frame_rectangle.position.y = center_.y;
  return frame_rectangle;
}

void Ellipse::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Ellipse::move(point_t position)
{
  double dx = position.x - getFrameRectangle().position.x;
  double dy = position.y - getFrameRectangle().position.y;
  move(dx, dy);
}

void Ellipse::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Error: wrong coefficient");
  }
  double center_x = getFrameRectangle().position.x;
  double center_y = getFrameRectangle().position.y;
  axis_horizontal_ *= k;
  axis_vertical_ *= k;
  center_.x = center_x * k;
  center_.y = center_y * k;
}
