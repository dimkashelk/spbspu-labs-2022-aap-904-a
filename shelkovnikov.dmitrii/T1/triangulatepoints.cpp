#include "triangulatepoints.h"
#include <stdexcept>
#include <cmath>
#include <limits>
dimkashelk::TriangulatePoints::TriangulatePoints(point_t *points, size_t size):
  points_(new point_t[size]),
  size_(size),
  point_(1),
  count_use_points_(2)
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
dimkashelk::TriangulatePoints::~TriangulatePoints()
{
  delete[] points_;
}
dimkashelk::Triangle dimkashelk::TriangulatePoints::operator()()
{
  if (size_ > 3)
  {
    if (point_ + 1 >= size_)
    {
      point_ = 1;
    }
    while (point_ + 1 < size_)
    {
      if (getMixedProduct(points_[point_ + 1], points_[0], points_[point_], points_[0]) > 0)
      {
        try
        {
          Triangle triangle = Triangle(points_[0], points_[point_], points_[point_ + 1]);
          point_++;
          count_use_points_++;
          return triangle;
        }
        catch (const std::logic_error &e)
        {
          point_ += 3;
        }
      }
      else
      {
        point_ += 3;
      }
    }
  }
  Triangle triangle = Triangle(points_[0], points_[1], points_[2]);
  count_use_points_ += 3;
  return triangle;
}
bool dimkashelk::TriangulatePoints::hasNext() const
{
  return size_ > count_use_points_;
}
double dimkashelk::TriangulatePoints::getMixedProduct(point_t p1_end, point_t p1_start, point_t p2_end, point_t p2_start) const
{
  //         |i  j  k|
  // a * b = |x1 y1 0| = 0 * i + 0 * j + (x1 * y2 - x2 * y1) * k;
  //         |x2 y2 0|
  double a_x = p1_end.x - p1_start.x;
  double a_y = p1_end.y - p1_start.y;
  double b_x = p2_end.x - p2_start.x;
  double b_y = p2_end.y - p2_start.y;
  double third_coord = a_x * b_y - a_y * b_x;
  //             |x1 y1 0|
  // a * b * c = |x2 y2 0| = x1 * y2 * z3 - x2 * y1 * z3
  //             |0  0 z3|
  return a_x * b_y * third_coord - b_x * a_y * third_coord;
}
bool dimkashelk::TriangulatePoints::containsThreePointsOnLine()
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
