#include "triangulatepoints.h"
#include <stdexcept>
#include <cmath>
#include <limits>
TriangulatePoints::TriangulatePoints(point_t *points, size_t size):
  points_(new point_t[size]),
  size_(size),
  first_(0),
  second_(0),
  third_(0),
  count_triangles_(0)
{
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
  if (containsThreePointsOnLine())
  {
    delete[] points_;
    throw std::logic_error("3 or more points_ on one line here.......");
  }
  if (size < 3)
  {
    delete[] points_;
    throw std::logic_error("Need minimum 3 points");
  }
}
TriangulatePoints::~TriangulatePoints()
{
  delete[] points_;
}
Triangle TriangulatePoints::operator()()
{
  while (size_ > 3)
  {
    first_ = 0;
    second_ = 1;
    third_ = 2;
    while (third_ < size_)
    {
      if (getMixedProduct(vector_t(points_[third_], points_[first_]), vector_t(points_[second_], points_[first_])) > 0)
      {
        try
        {
          Triangle triangle = Triangle(points_[first_], points_[second_], points_[third_]);
          if (!containsAnyPoint(triangle))
          {
            removePoint(second_);
            count_triangles_++;
            return triangle;
          }
          else
          {
            first_ += 3;
            second_ += 3;
            third_ += 3;
          }
        }
        catch (const std::logic_error &e)
        {
          first_ += 3;
          second_ += 3;
          third_ += 3;
        }
      }
      else
      {
        first_ += 3;
        second_ += 3;
        third_ += 3;
      }
    }
  }
  Triangle triangle = Triangle(points_[0], points_[1], points_[2]);
  return triangle;
}
size_t TriangulatePoints::getSize() const
{
  return count_triangles_;
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
        double A = points_[i].y - points_[j].y;
        double B = -(points_[i].x - points_[j].x);
        double C = -B * points_[j].y - A * points_[j].x;
        if (std::fabs(A * points_[k].x + B * points_[k].y + C) <= error)
        {
          contains_three_points_on_line = true;
        }
      }
    }
  }
  return contains_three_points_on_line;
}
