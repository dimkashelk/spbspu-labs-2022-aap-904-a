#include "triangulatepoints.h"
#include <stdexcept>
#include <cmath>
#include <limits>
#include "line_t.h"
TriangulatePoints::TriangulatePoints(point_t *points, size_t size):
  points_(points),
  size_(size),
  triangles_(new Triangle*[size_])
{
  if (containsThreePointsOnLine())
  {
    delete[] triangles_;
    throw std::logic_error("3 or more points_ on one line here.......");
  }
  size_t index = 0;
  while (size_ > 3)
  {
    point_t *point = points;
    size_t ind = 0;
    size_t last_number = 2;
    while (last_number < size_)
    {
      if (getMixedProduct(vector_t(*(point + 2), *point), vector_t(*(point + 1), *point)) > 0)
      {
        try
        {
          Triangle *triangle = new Triangle(*point, *(point + 1), *(point + 2));
          if (!containsAnyPoint(*triangle))
          {
            triangles_[index] = triangle;
            index++;
            last_number++;
            removePoint(ind + 1);
          }
          else
          {
            point += 3;
            last_number += 3;
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
  triangles_[index] = triangle;
  index++;
  size_ = index;
}
TriangulatePoints::~TriangulatePoints()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete triangles_[i];
  }
  delete[] triangles_;
  delete[] points_;
}
Triangle TriangulatePoints::operator()() const
{
  Triangle triangle = **triangles_;
  return triangle;
}
size_t TriangulatePoints::getSize() const
{
  return size_;
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
  for (size_t r = 0; r < size_; r++)
  {
    contains_any_point = triangle.containsPoint(points_[r]);
    if (contains_any_point)
    {
      break;
    }
  }
  return contains_any_point;
}
void TriangulatePoints::removePoint(size_t ind)
{
  if (size_ == 0)
  {
    return;
  }
  for (size_t i = ind; i < size_ - 1; i++)
  {
    points_[i] = points_[i + 1];
  }
  size_--;
}
bool TriangulatePoints::containsThreePointsOnLine()
{
  constexpr double error = std::numeric_limits< double >::epsilon();
  bool contains_three_points_on_line = false;
  for (size_t i = 0; i < size_ - 2 && !contains_three_points_on_line; i++)
  {
    for (size_t j = i + 1; j < size_ - 1 && !contains_three_points_on_line; j++)
    {
      for (size_t k = j + 1; k < size_ && !contains_three_points_on_line; k++)
      {
        line_t line(points_[j], points_[i]);
        if (fabs(line.A * points_[k].x + line.B * points_[k].y + line.C) <= error)
        {
          contains_three_points_on_line = true;
        }
      }
    }
  }
  return contains_three_points_on_line;
}
