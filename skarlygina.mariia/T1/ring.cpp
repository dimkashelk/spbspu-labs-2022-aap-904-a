#include "ring.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
Ring::Ring(point_t center, double radius_small, double radius_big):
  center_(center),
  radius_small_(radius_small),
  radius_big_(radius_big)
{}

double Ring::getArea() const
{
  const double pi = M_PI;
  return (pi * radius_big_ * radius_big_ - pi * radius_small_ * radius_small_);
}

rectangle_t Ring::getFrameRectangle() const
{
  rectangle_t frame_rectangle{};
  frame_rectangle.height = radius_big_;
  frame_rectangle.width = radius_big_;
  frame_rectangle.position.x = center_.x;
  frame_rectangle.position.y = center_.y;
  return frame_rectangle;
}

void Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Ring::move(point_t position)
{
  double dx = position.x - getFrameRectangle().position.x;
  double dy = position.y - getFrameRectangle().position.y;
  move(dx, dy);
}

void Ring::scale(double k)
{
	if (k <= 0)
	{
		throw std::logic_error("Error: wrong coefficient");
	}
	double center_x = getFrameRectangle().position.x;
	double center_y = getFrameRectangle().position.y;
}
