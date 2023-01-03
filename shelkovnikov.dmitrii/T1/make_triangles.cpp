#include "make_triangles.h"
#include "triangulatepoints.h"
dimkashelk::Triangle* dimkashelk::makeTriangles(point_t *points, size_t size)
{
  TriangulatePoints triangulatePoints(points, size);
  size_t s = 0;
  size_t capacity = 10;
  Triangle *triangles = new Triangle[capacity];
  while (triangulatePoints.hasNext())
  {
    try
    {
      triangles[s++] = triangulatePoints();
    }
    catch(...)
    {
      delete[] triangles;
      throw;
    }
    if (s == capacity)
    {
      Triangle *new_triangles = new Triangle[capacity + 10];
      capacity += 10;
      for (size_t i = 0; i < s; i++)
      {
        new_triangles[i] = triangles[i];
      }
      delete[] triangles;
      triangles = new_triangles;
    }
  }
  return triangles;
}
