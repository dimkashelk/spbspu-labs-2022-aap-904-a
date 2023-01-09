#include "Ring.hpp"
#include <stdexcept>
#include "Ellipse.hpp"

Ring::Ring(point_t center, double r1, double r2):
  EllipseOne_(new Ellipse({center.x, center.y}, r1, r1)),
  EllipseTwo_(new Ellipse({center.x, center.y}, r2, r2)),
  rect_(EllipseOne_->getFrameRect()),
  center_(center),
  r1_(r1),
  r2_(r2)
{
  if (EllipseOne_->getArea() < EllipseTwo_->getArea())
  {
    delete EllipseOne_;
    delete EllipseTwo_;
    throw std::invalid_argument("Bad input, invalid ellipses radius's, => invalid ring");
  }
}

double Ring::getArea() const
{
  return (EllipseOne_->getArea() - EllipseTwo_->getArea());
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
  rect_.width = (EllipseOne_->getFrameRect().width / 2) * 2.0;
  rect_.height = (EllipseOne_->getFrameRect().height / 2) * 2.0;
}

Shape *Ring::clone() const
{
  return new Ring(center_, r1_, r2_);
}

Ring::~Ring()
{
  delete EllipseOne_;
  delete EllipseTwo_;
}
+