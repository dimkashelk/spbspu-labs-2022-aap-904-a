#ifndef BASEFUNC_HPP
#define BASEFUNC_HPP
#include "base-types.hpp"

namespace tarasenko
{
  rectangle_t makeRectangle(point_t point_ld, point_t point_ru);
  point_t * getPointRect(rectangle_t rect);
};
#endif
