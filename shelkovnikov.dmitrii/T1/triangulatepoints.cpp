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
  for (size_t i = 0; i < size - 2; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      for (size_t k = j + 1; k < size; k++)
      {}
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
