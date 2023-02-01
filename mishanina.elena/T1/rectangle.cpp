#include "rectangle.h"

Rectangle::Rectangle(const point_t& ld_point, const point_t& ru_point)
{
}

double Rectangle::getArea() const
{
  return 0.0;
}

std::string Rectangle::getName() const
{
  return "";
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{ };
}

void Rectangle::move(const point_t point)
{
}

void Rectangle::move(const double dx, const double dy)
{
}

void Rectangle::scale(double k)
{
}

Shape* Rectangle::clone() const
{
  return nullptr;
}
