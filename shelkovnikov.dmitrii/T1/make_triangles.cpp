#include "make_triangles.h"
#include <stdexcept>
dimkashelk::Triangle* dimkashelk::makeTriangles(const point_t *points, size_t size)
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
    catch (...)
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
dimkashelk::TriangulatePoints::TriangulatePoints(const point_t *points, size_t size):
  points_(new point_t[size]),
  size_(size),
  point_(1)
{
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
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
  if (point_ + 1 >= size_)
  {
    point_ = 1;
  }
  while (point_ + 1 < size_)
  {
    if (getMixedProduct(points_[point_ + 1], points_[0], points_[point_], points_[0]) >= 0)
    {
      Triangle triangle = Triangle(points_[0], points_[point_], points_[point_ + 1]);
      point_++;
      return triangle;
    }
    else
    {
      point_++;
    }
  }
  Triangle triangle = Triangle(points_[0], points_[1], points_[2]);
  points_++;
  return triangle;
}
bool dimkashelk::TriangulatePoints::hasNext() const
{
  return size_ > point_ + 1;
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
