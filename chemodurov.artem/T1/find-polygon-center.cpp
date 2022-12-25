#include "find-polygon-center.hpp"

chemodurov::point_t chemodurov::findPolygonCenter(const chemodurov::point_t * verts, size_t num_of_verts)
{
  double area = calcPolygonArea(verts, num_of_verts);
  double x_of_center = 0.0;
  double y_of_center = 0.0;
  for (size_t i = 0; i < num_of_verts - 1; ++i)
  {
    x_of_center += (verts[i].x + verts[i + 1].x) * (verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y);
    y_of_center += (verts[i].y + verts[i + 1].y) * (verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y);
  }
  x_of_center /= (6 * area);
  y_of_center /= (6 * area);
  chemodurov::point_t temp{x_of_center, y_of_center};
  return temp;
}
