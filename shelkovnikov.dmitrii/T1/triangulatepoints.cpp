#include "triangulatepoints.h"
#include <stdexcept>
#include <cmath>
#include <limits>
#include "line_t.h"
TriangulatePoints::TriangulatePoints(point_t *points, size_t size):
  points(points),
  size(size)
{
  if (containsThreePointsOnLine())
  {
    throw std::logic_error("3 or more points on one line here.......");
  }
}
Triangle **TriangulatePoints::operator()(size_t &new_size)
{
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
  new_size = index;
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
bool TriangulatePoints::containsThreePointsOnLine()
{
  constexpr double error = std::numeric_limits< double >::epsilon();
  bool contains_three_points_on_line = false;
  for (size_t i = 0; i < size - 2 && !contains_three_points_on_line; i++)
  {
    for (size_t j = i + 1; j < size - 1 && !contains_three_points_on_line; j++)
    {
      for (size_t k = j + 1; k < size && !contains_three_points_on_line; k++)
      {
        line_t line(points[j], points[i]);
        if (fabs(line.A * points[k].x + line.B * points[k].y + line.C) <= error)
        {
          contains_three_points_on_line = true;
        }
      }
    }
  }
  return contains_three_points_on_line;
}
