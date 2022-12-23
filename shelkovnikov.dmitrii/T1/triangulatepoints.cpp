#include "triangulatepoints.h"
#include <stdexcept>
TriangulatePoints::TriangulatePoints(point_t *points, size_t size):
  points(points),
  size(size)
{}
Triangle **TriangulatePoints::operator()()
{
  // Delaunay triangulation
  //Triangulation algorithm:
  //1. Take three vertices A1, A2, A3
  //2. Check whether the vectors A1A3, A1A2 form the left triple of vectors (the vector product is positive).
  //3. Check whether there are any of the remaining vertices of the polygon inside the triangle A1A2A3.
  //4. If both conditions are met, then we build a triangle A1A2A3, and exclude vertex A2 from the polygon, without touching vertex A1, shift vertices A2 (A2 to A3), A3 (A3 to A4)
  //5. If at least one condition is not met, we move on to the next three vertices.
  //6. Repeat from step 1 until there are three vertices left.
  Triangle **triangles = new Triangle*[size];
  size_t index = 0;
  while (size > 3)
  {
    point_t *point = points;
    size_t ind = 0;
    while (point < points - 2)
    {
      if (getMixedProduct(vector_t(*(point + 2), *point), vector_t(*(point + 1), *point)) > 0)
      {
        try
        {
          Triangle *triangle = new Triangle(*point, *(point + 1), *(point + 2));
          if (!containsAnyPoint(*triangle))
          {
            triangles[index] = triangle;
            index++;
            removePoint(ind + 1);
          }
          else
          {
            point += 3;
            ind += 2;
          }
        }
        catch (const std::logic_error &e)
        {
          point += 3;
          ind += 2;
        }
      }
      else
      {
        point += 3;
        ind += 2;
      }
    }
  }
  Triangle *triangle = new Triangle(*points, *(points + 1), *(points + 2));
  triangles[index] = triangle;
  Triangle **new_triangles = new Triangle*[index];
  for (size_t i = 0; i < index; i++)
  {
    new_triangles[i] = triangles[i];
  }
  delete[] triangles;
  return new_triangles;
}
double TriangulatePoints::getMixedProduct(vector_t a, vector_t b) const
{
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  double third_coord = a.x * b.y - a.y * b.x;
  //             |x1 y1 0|
  // a * b * c = |x2 y2 0| = x1 * y2 * z3 - x2 * y1 * z3
  //             |0  0 z3|
  return a.x * b.y * third_coord - b.x * a.y * third_coord;
}
bool TriangulatePoints::containsAnyPoint(const Triangle &triangle) const
{
  bool contains_any_point = false;
  for (size_t r = 0; r < size; r++)
  {
    contains_any_point = triangle.containsPoint(points[r]);
    if (contains_any_point)
    {
      break;
    }
  }
  return contains_any_point;
}
void TriangulatePoints::removePoint(size_t ind)
{
  if (size == 0)
  {
    return;
  }
  for (size_t i = ind; i < size - 1; i++)
  {
    points[i] = points[i + 1];
  }
  size--;
}
