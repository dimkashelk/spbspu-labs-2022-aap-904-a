#ifndef CALC_POLYGON_AREA_HPP
#define CALC_POLYGON_AREA_HPP
#include <cstddef>
#include "base-types.hpp"

namespace chemodurov
{
  double calcPolygonArea(const chemodurov::point_t * vertices, size_t number_of_vertices);
}

#endif
