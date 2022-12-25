#include "polygon.hpp"

namespace chemodurov
{
  chemodurov::point_t * copyArrayOfPoints(const chemodurov::point_t * arr, size_t arr_size)
  {
    chemodurov::point_t * temp = new point_t[arr_size];
    for (size_t i = 0; i < arr_size; ++i)
    {
      temp[i] = arr[i];
    }
    return temp;
  }

  double calcPolygonArea(const chemodurov::point_t * verts, size_t num_of_verts)
  {
    double area = 0.0;
    for (size_t i = 0; i < num_of_verts - 1; ++i)
    {
      area += verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y;
    }
    area *= 0.5;
    return area;
  }

  chemodurov::point_t findPolygonCenter(const chemodurov::point_t * verts, size_t num_of_verts)
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
}

chemodurov::Polygon::Polygon(const chemodurov::point_t * verts, size_t num_of_verts):
 vertices_(chemodurov::copyArrayOfPoints(verts, num_of_verts)),
 number_of_vertices_(num_of_verts),
 center_(chemodurov::findPolygonCenter(verts, num_of_verts))
{
  
}

chemodurov::Polygon::~Polygon()
{
  delete [] vertices_;
}

double chemodurov::Polygon::getArea() const
{
  return chemodurov::calcPolygonArea(vertices_, number_of_vertices_);
}
