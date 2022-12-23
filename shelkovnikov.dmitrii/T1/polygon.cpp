#include "polygon.h"
#include "triangulatepoints.h"
Polygon::Polygon(point_t *points, size_t size):
  triangles(nullptr),
  count(0)
{
  TriangulatePoints triangulatePoints(points, size);
  triangles = triangulatePoints(count);
}
double Polygon::getArea() const
{
  double global_area = 0.0;
  for (size_t i = 0; i < count; i++)
  {
    global_area += triangles[i]->getArea();
  }
  return global_area;
}
