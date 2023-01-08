#include "ring.h"

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
  double height = baseFunctions::findRadius(radius_big_, 2.0);
  double width = baseFunctions::findRadius(radius_big_, 2.0);
  point_t position = {center_.x, center_.y};
  return {height, width, position};
}

void Ring::move(double dx, double dy)
{
  center_ = baseFunctions::findSummVector(center_, dx, dy);
}

void Ring::move(point_t position)
{
  point_t diff = baseFunctions::findDifference(position, getFrameRectangle().position);
  move(diff.x, diff.y);
}

void Ring::scale(double k)
{
  baseFunctions::findCorrectKoeff(k);
  point_t center = getFrameRectangle().position;
  radius_small_ = baseFunctions::findRadius(radius_small_, k);
  radius_big_ = baseFunctions::findRadius(radius_big_, k);
  center_ = baseFunctions::makeCenterMove(center_, center, k);
}
