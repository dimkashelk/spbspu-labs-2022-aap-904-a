#include "outputframerect.hpp"

void tarasenko::outputFrameRect(std::ostream & output, const tarasenko::rectangle_t & rect)
{
  tarasenko::point_t point_ld(rect.pos_.x_ - rect.width_ * 0.5, rect.pos_.y_ - rect.height_ * 0.5);
  tarasenko::point_t point_ru(rect.pos_.x_ + rect.width_ * 0.5, rect.pos_.y_ + rect.height_ * 0.5);
  output << point_ld.x_ << " " << point_ld.y_ << " " << point_ru.x_ << " " << point_ru.y_;
}