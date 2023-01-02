#include "rectangle.hpp"
#include <stdexcept>

tarasenko::Rectangle::Rectangle(point_t point_ld, point_t point_ru):
  rect_(point_ld, point_ru)
{
  if ((point_ld.x_ >= point_ru.x_) || (point_ld.y_ >= point_ru.y_))
  {
    throw std::invalid_argument("incorrect rectangle coordinates");
  }
}

tarasenko::Rectangle::Rectangle(rectangle_t rect):
  rect_(rect)
{}

double tarasenko::Rectangle::getArea() const
{
  return rect_.width_ * rect_.height_;
}

tarasenko::rectangle_t tarasenko::Rectangle::getFrameRect() const
{
  return rect_;
}

void tarasenko::Rectangle::move(point_t pos)
{
  rect_.pos_ = pos;
}

void tarasenko::Rectangle::move(double dx, double dy)
{
  rect_.pos_.x_ += dx;
  rect_.pos_.y_ += dy;
}

void tarasenko::Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("the coefficient is less than zero");
  }
  rect_.width_ *= k;
  rect_.height_ *= k;
}

tarasenko::Shape * tarasenko::Rectangle::clone() const
{
  return new Rectangle(rect_);
}
