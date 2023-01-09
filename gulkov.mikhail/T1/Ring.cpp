#include "Ring.hpp"
#include <stdexcept>

Ring::Ring(point_t center, Shape *EllipseOne, Shape *EllipseTwo):
  center_(center),
  rect_(EllipseTwo->getFrameRect()),
  EllipseOne_(EllipseOne),
  EllipseTwo_(EllipseTwo)
{
  if (EllipseOne_->getArea() > EllipseOne_->getArea())
  {
    throw std::invalid_argument("Bad input, invalid ellipses radius's, => invalid ring");
  }
}

double Ring::getArea() const
{
  return EllipseTwo_->getArea() - EllipseTwo_->getArea();
}

rectangle_t Ring::getFrameRect() const
{
  return rect_;
}

void Ring::move(point_t position)
{
  double dx = position.x - getFrameRect().pos.x;
  double dy = position.y - getFrameRect().pos.y;
  move(dx, dy);
}

void Ring::move(double delta_x, double delta_y)
{
  rect_.pos.x += delta_x;
  rect_.pos.y += delta_y;
}

void Ring::makeScale(double k)
{
  EllipseOne_->makeScale(k);
  EllipseTwo_->makeScale(k);
}

Shape *Ring::clone() const
{
  return new Ring(center_, EllipseOne_, EllipseTwo_);
}
