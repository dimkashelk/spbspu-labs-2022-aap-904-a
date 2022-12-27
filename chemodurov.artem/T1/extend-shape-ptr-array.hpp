#ifndef EXTEND_SHAPE_PTR_ARRAY_HPP
#define EXTEND_SHAPE_PTR_ARRAY_HPP
#include <cstddef>
#include "shape.hpp"

namespace chemodurov
{
  chemodurov::Shape ** extendShapePtrArray(chemodurov::Shape ** shp, size_t capacity, size_t new_capacity);
}

#endif
