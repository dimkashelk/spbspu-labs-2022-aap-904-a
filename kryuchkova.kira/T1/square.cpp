#include "square.h"
#include <stdexcept>

kryuchkova::Square::Square(const point_t &lb_point, const double &length):
  lb_point_(lb_point),
  length_(length)
{
  if (length <= 0)
  {
    throw std::invalid_argument("It's not a Square");
  }
}

std::string kryuchkova::Square::getName() const
{
  return "SQUARE";
}

double kryuchkova::Square::getArea() const
{
  return length_ * length_;
}

kryuchkova::rectangle_t kryuchkova::Square::getFrameRect() const
{
  point_t pos{length_ / 2 + lb_point_.x, length_ / 2 + lb_point_.y};
  return rectangle_t{length_, length_, pos};
}

void kryuchkova::Square::move(const double dx, const double dy)
{
  movePoint(lb_point_, point_t{dx, dy});
}

void kryuchkova::Square::move(const point_t point)
{
  point_t pos{length_ / 2 + lb_point_.x, length_ / 2 + lb_point_.y};
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void kryuchkova::Square::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("scaling koef must be positive");
  }
  double dx = ((k - 1) * length_) / 2;
  double dy = ((k - 1) * length_) / 2;
  lb_point_.x -= dx;
  lb_point_.y -= dy;
  length_ *= k;
}

kryuchkova::Shape *kryuchkova::Square::clone() const
{
  return new Square(lb_point_, length_);
}
