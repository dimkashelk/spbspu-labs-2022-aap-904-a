#include "base_types.h"
#include <iostream>

rectangle_t::rectangle_t(point_t pos1, point_t pos2):
  pos{(pos1.x + pos2.x) / 2, (pos1.y + pos2.y) / 2},
  width(pos2.x - pos1.x),
  height(pos2.y - pos1.y)
{}

rectangle_t::rectangle_t(point_t pos, double width, double height):
  width(width),
  height(height)
{
  if ((width <= 0) || (height <=0))
  {
    std::cout << "wrong values";
  }
}


