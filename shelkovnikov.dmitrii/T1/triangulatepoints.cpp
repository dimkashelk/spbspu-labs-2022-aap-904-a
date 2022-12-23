#include "triangulatepoints.h"
TriangulatePoints::TriangulatePoints(point_t *points, size_t size):
  points(points),
  size(size)
{}
Triangle *TriangulatePoints::operator()() const
{
  // Delaunay triangulation
  //Triangulation algorithm:
  //1. Take three vertices A1, A2, A3
  //2. Check whether the vectors A1A3, A1A2 form the left triple of vectors (the vector product is positive).
  //3. Check whether there are any of the remaining vertices of the polygon inside the triangle A1A2A3.
  //4. If both conditions are met, then we build a triangle A1A2A3, and exclude vertex A2 from the polygon, without touching vertex A1, shift vertices A2 (A2 to A3), A3 (A3 to A4)
  //5. If at least one condition is not met, we move on to the next three vertices.
  //6. Repeat from step 1 until there are three vertices left.
  point_t *point1 = points;
  size_t index1 = 0;
  point_t *point2 = points + 1;
  size_t index2 = 1;
  point_t *point3 = points + 2;
  size_t index3 = 2;
  while (size > 3)
  {
    if (get_mixed_product(vector_t(*point3, *point1), vector_t(*point2, *point1)) > 0)
    {
      Triangle triangle(*point1, *point2, *point3);
      if (!containsAnyPoint(triangle))
      {

      }
    }
  }
}
double TriangulatePoints::get_mixed_product(vector_t a, vector_t b) const
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
