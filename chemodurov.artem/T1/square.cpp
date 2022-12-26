#include "square.hpp"

namespace chemodurov
{
  chemodurov::point_t * makeArrayOfXPoints(const chemodurov::point_t & left_down
  {
    const size_t x = 4;
    chemodurov::point_t * arr = new point_t[x];
    arr[0] = left_down;
    arr[1] = {left_down.x, left_down.y + length};
    arr[2] = {left_down.x + length, left_down.y + length};
    arr[3] = {right_up.x, left_down.y};
    return arr;
  }
}

chemodurov::Square::Square(const chemodurov::point_t & left_down, double length):
 p()
{}
