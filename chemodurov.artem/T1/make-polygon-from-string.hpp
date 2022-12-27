#ifndef MAKE_POLYGON_FROM_STRING_HPP
#define MAKE_POLYGON_FROM_STRING_HPP
#include <string>
#include "shape.hpp"

namespace chemodurov
{
  chemodurov::Shape * makePolygonFromString(const std::string & data);
}

#endif
