#include "print-summ-area-and-frames.hpp"
#include <iostream>
#include <iomanip>

namespace chemodurov
{
  void printLeftDownAndRightUp(std::ostream & out, const rectangle_t & rect)
  {
    point_t left_down{rect.pos.x - 0.5 * rect.width, rect.pos.y - 0.5 * rect.height};
    point_t right_up{rect.pos.x + 0.5 * rect.width, rect.pos.y + 0.5 * rect.height};
    out << std::setprecision(1) << left_down.x << ' ' << std::setprecision(1) << left_down.y << ' ';
    out << std::setprecision(1) << right_up.x << ' ' << std::setprecision(1) << right_up.y;
  }

}
void chemodurov::printSummAreaAndFrames(std::ostream & out, Shape ** shp, size_t shp_size)
{
  if (!shp_size)
  {
    throw std::invalid_argument("Invalid size of Shape array");
  }
  double summ_area = 0.0;
  rectangle_t * frames = nullptr;
  try
  {
    frames = new rectangle_t[shp_size];
  }
  catch (...)
  {
    delete [] frames;
    throw;
  }
  for (size_t i = 0; i < shp_size; ++i)
  {
    summ_area += shp[i]->getArea();
    frames[i] = shp[i]->getFrameRect();
  }
  out << std::fixed << std::setprecision(1) << summ_area;
  for (size_t i = 0; i < shp_size; ++i)
  {
    chemodurov::printLeftDownAndRightUp(out << ' ', frames[i]);
  }
  delete [] frames;
}
