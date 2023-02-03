#include "make_triangles.h"
#include <stdexcept>
#include "base_functions.h"
dimkashelk::Triangle *dimkashelk::makeTriangles(const point_t *points, size_t size)
{
  TriangulatePoints triangulatePoints(points, size);
  size_t s = 0;
  Triangle *triangles = new Triangle[size - 2];
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
  }
  return triangles;
}
dimkashelk::TriangulatePoints::TriangulatePoints(const point_t *points, size_t size) :
  points_(new point_t[size]),
  size_(size),
  point_first_(0),
  point_second_(1)
{
  if (size < 3)
  {
    delete[] points_;
    throw std::logic_error("Need minimum 3 points");
  }
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
}
dimkashelk::TriangulatePoints::~TriangulatePoints()
{
  delete[] points_;
}
dimkashelk::Triangle dimkashelk::TriangulatePoints::operator()()
{
  if (point_second_ + 1 < size_ && size_ != 3)
  {
    point_first_ = 0;
    point_second_ = 1;
  }
  while (point_second_ + 2 < size_)
  {
    if (getVectorProduct(points_[point_second_ + 1], points_[point_first_], points_[point_second_], points_[point_first_]) > 0)
    {
      size_t count = 0;
      Triangle triangle = Triangle(points_[point_first_], points_[point_second_], points_[point_second_ + 1]);
      for (size_t i = 0; i < size_; i++)
      {
        point_t points[]{points_[point_first_], points_[point_second_], points_[point_second_ + 1], points_[i]};
        if (containsPointInTriangle(points))
        {
          count++;
        }
      }
      if (count == 3)
      {
        removePoint(point_second_);
        return triangle;
      }
      point_first_++;
      point_second_++;
    }
    else
    {
      point_first_++;
      point_second_++;
    }
  }
  Triangle triangle = Triangle(points_[0], points_[1], points_[2]);
  return triangle;
}
bool dimkashelk::TriangulatePoints::hasNext() const
{
  return size_ >= 3;
}
bool dimkashelk::TriangulatePoints::containsPointInTriangle(point_t *p) const
{
  int sign_1 = sign((p[0].x - p[3].x) * (p[1].y - p[0].y) - (p[1].x - p[0].x) * (p[0].y - p[3].y));
  int sign_2 = sign((p[1].x - p[3].x) * (p[2].y - p[1].y) - (p[2].x - p[1].x) * (p[1].y - p[3].y));
  int sign_3 = sign((p[2].x - p[3].x) * (p[0].y - p[2].y) - (p[0].x - p[2].x) * (p[2].y - p[3].y));
  return sign_1 + sign_2 + sign_3 == 3 || sign_1 + sign_2 + sign_3 == -3 || sign_1 * sign_2 * sign_3 == 0;
}
void dimkashelk::TriangulatePoints::removePoint(size_t ind)
{
  for (; ind + 1 < size_; ind++)
  {
    points_[ind] = points_[ind + 1];
  }
  size_--;
}
