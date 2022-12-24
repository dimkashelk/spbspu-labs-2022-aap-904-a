#include "polygon.h"
#include <algorithm>
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
rectangle_t Polygon::getFrameRect() const
{
  double x_min = triangles[0]->getFrameRect().getLeftDownPoint().x;
  double y_min = triangles[0]->getFrameRect().getLeftDownPoint().y;
  double x_max = x_min;
  double y_max = y_min;
  for (size_t i = 0; i < count; i++)
  {
    rectangle_t rectangle = triangles[i]->getFrameRect();
    x_min = std::min(x_min, rectangle.getLeftDownPoint().x);
    y_min = std::min(y_min, rectangle.getLeftDownPoint().y);
    x_max = std::max(x_max, rectangle.getRightUpPoint().x);
    y_max = std::max(y_max, rectangle.getRightUpPoint().y);
  }
  return rectangle_t(x_min, y_min, x_max, y_max);
}
