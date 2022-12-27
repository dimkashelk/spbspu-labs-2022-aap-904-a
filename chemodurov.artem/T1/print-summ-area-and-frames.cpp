#include "print-summ-area-and-frames.hpp"
#include <iostream>

void printLeftDownAndRightUp(std::ostream & out, const chemodurov::rectangle_t & rect)
{
  chemodurov::point_t left_down{rect.pos.x - 0.5 * rect.width, rect.pos.y - 0.5 * rect.height};
  chemodurov::point_t right_up{rect.pos.x + 0.5 * rect.width, rect.pos.y + 0.5 * rect.height};
  out << left_down.x << ' ' << left_down.y << ' ' << right_up.x << ' ' << right_up.y;
}

void chemodurov::printSummAreaAndFrames(std::ostream & out, chemodurov::Shape ** shp, size_t shp_size)
{
  if (!shp_size)
  {
    throw std::invalid_argument("Invalid size of Shape array");
  }
  double summ_area = 0.0;
  chemodurov::rectangle_t * frames = new chemodurov::rectangle_t[shp_size];
  for (size_t i = 0; i < shp_size; ++i)
  {
    summ_area += (*shp[i]).getArea();
    frames[i] = (*shp[i]).getFrameRect();
  }
  out << summ_area;
  for (size_t i = 0; i < shp_size; ++i)
  {
    printLeftDownAndRightUp(out << ' ', frames[i]);
  }
}
