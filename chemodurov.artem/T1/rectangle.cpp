#include "rectangle.hpp"
#include <cmath>
#include "base-types.hpp"

chemodurov::Rectangle::Rectangle(chemodurov::point_t left_down, chemodurov::point_t right_up):
 left_down_(left_down),
 right_up_(right_up),
 center_((right_up + left_down) * 0.5)
{}

double chemodurov::Rectangle::getArea() const
{
  return std::abs((right_up_.x - left_down_.x) * (right_up_.y - left_down_.y));
}

chemodurov::rectangle_t chemodurov::Rectangle::getFrameRect() const
{
  chemodurov::rectangle_t temp{center_, std::abs(right_up_.x - left_down_.x), std::abs(right_up_.y - left_down_.y)};
  return temp;
}

void chemodurov::Rectangle::move(chemodurov::point_t pos)
{
  center_ = pos;
}

void chemodurov::Rectangle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void chemodurov::Rectangle::scale(double k)
{
  right_up_ = (right_up_ - center_) * k + center_;
  left_down_ = (left_down_ - center_) * k + center_;
}
