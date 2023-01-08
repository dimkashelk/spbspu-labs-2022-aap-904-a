#include "base-func.hpp"
#include <stdexcept>

tarasenko::rectangle_t tarasenko::makeRectangle(point_t point_ld, point_t point_ru)
{
  if (point_ru.x_ <= point_ld.x_ || point_ru.y_ <= point_ld.y_)
  {
    throw std::invalid_argument("It isn't rectangle");
  }
  rectangle_t rect{point_ru.x_ - point_ld.x_, point_ru.y_ - point_ld.y_, {(point_ru.x_ + point_ld.x_) / 2, (point_ru.y_ + point_ld.y_) / 2}};
  return rect;
}
