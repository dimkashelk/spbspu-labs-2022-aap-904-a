#include "calc-polygon-area.hpp"

double chemodurov::calcPolygonArea(const chemodurov::point_t * verts, size_t num_of_verts)
{
  double area = 0.0;
  for (size_t i = 0; i < num_of_verts - 1; ++i)
  {
    area += verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y;
  }
  area *= 0.5;
  return area;
}
