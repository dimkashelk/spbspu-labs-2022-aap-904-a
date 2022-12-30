#ifndef MAKE_POLYGON_FROM_STRING_HPP
#define MAKE_POLYGON_FROM_STRING_HPP
#include <string>
#include "shape.hpp"

namespace chemodurov
{
  point_t * getArrayOfPoints(const std::string & data, size_t & arr_size);
  Shape * makePolygonFromPoints(point_t * arr, size_t arr_size);
}

#endif
