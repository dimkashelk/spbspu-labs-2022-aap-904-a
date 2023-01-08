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
  point_t diff = baseFunctions::findDifference(position, getFrameRectangle().position);
  move(diff.x, diff.y);
}

void Ellipse::scale(double k)
{
  point_t center = getFrameRectangle().position;
  radius_horizontal_ = baseFunctions::Radius(radius_horizontal_, k);
  radius_vertical_ = baseFunctions::Radius(radius_vertical_, k);
  center_ = baseFunctions::CenterMove(center_, center, k);
}
