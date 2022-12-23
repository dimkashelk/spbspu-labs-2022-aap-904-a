#include "polygon.h"
#include "triangulatepoints.h"
Polygon::Polygon(point_t *points, size_t size):
  triangles(nullptr),
  count(0)
{
  TriangulatePoints triangulatePoints(points, size);
  triangles = triangulatePoints(count);
}
