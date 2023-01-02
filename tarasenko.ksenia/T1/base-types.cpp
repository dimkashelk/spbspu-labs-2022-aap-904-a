#include "base-types.hpp"

tarasenko::point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}

tarasenko::rectangle_t::rectangle_t(point_t point_ld, point_t point_ru):
  width_(point_ld.x_ - point_ru.x_),
  height_(point_ld.y_ - point_ru.y_),
  pos_((point_ru.x_ + point_ld.x_) / 2, (point_ru.y_ + point_ld.y_) / 2)
{}
