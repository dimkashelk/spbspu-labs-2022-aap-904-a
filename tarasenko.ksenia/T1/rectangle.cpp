#include "rectangle.hpp"

Rectangle::Rectangle(double x1, double y1, double x2, double y2):
  rect_(x1, y1, x2, y2)
{
  if ((x1 > x2) || (y1 > y2))
  {
    throw std::invalid_argument("incorrect rectangle coordinates");
  }
}

double Rectangle::getArea() const
{
  return rect_.width_ * rect_.height_;
}

rectangle_t getFrameRect() const
{
  return rect_;
}

void Rectangle::move(point_t pos);
{
  rect_.pos_ = pos;
}

void Rectangle::move(double dx, double dy);
{
  rect_.pos_.x_ += dx;
  rect_.pos_.y_ += dy;
}

void Rectangle::scale(double k);
{
  rect_.width_ *= k;
  rect_.height *= k;
}

Shape * Rectangle::clone() const
{
  return new Rectangle(rect_);
}
