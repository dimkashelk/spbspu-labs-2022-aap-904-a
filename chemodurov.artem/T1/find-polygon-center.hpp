#ifndef FINDPOLYGONCENTER_HPP
#define FINDPOLYGONCENTER_HPP
#include "calc-polygon-area.hpp"

namespace chemodurov
{
  chemodurov::point_t findPolygonCenter(const chemodurov::point_t * vertices, size_t number_of_vertices);
}

#endif
