#include "polygon.h"
#include <algorithm>
#include "triangulatepoints.h"
#include "isotropic_scaling.h"
#include "base_functions.h"
dimkashelk::Polygon::Polygon(point_t *points, size_t size):
  count_(0),
  triangles_(makeTriangles(points, size)),
  center{0.0, 0.0}
{
  double x_sum = 0.0;
  double y_sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    x_sum += points[i].x;
    y_sum += points[i].y;
  }
  center = point_t{x_sum / size, y_sum / size};
}
dimkashelk::Polygon::Polygon(const Polygon &polygon):
  count_(polygon.count_),
  triangles_(new Triangle[polygon.count_]),
  center(polygon.center)
{
  for (size_t i = 0; i < polygon.count_; i++)
  {
    triangles_[i] = Triangle(polygon.triangles_[i]);
  }
}
dimkashelk::Polygon::~Polygon() noexcept
{
  delete[] triangles_;
}
double dimkashelk::Polygon::getArea() const
{
  double global_area = 0.0;
  for (size_t i = 0; i < count_; i++)
  {
    global_area += triangles_[i].getArea();
  }
  return global_area;
}
dimkashelk::rectangle_t dimkashelk::Polygon::getFrameRect() const
{
  rectangle_t rectangle = triangles_[0].getFrameRect();
  point_t left_down = getLeftDownPoint(rectangle);
  point_t right_up = getRightUpPoint(rectangle);
  double x_min = left_down.x;
  double y_min = left_down.y;
  double x_max = right_up.x;
  double y_max = right_up.y;
  for (size_t i = 0; i < count_; i++)
  {
    rectangle = triangles_[i].getFrameRect();
    left_down = getLeftDownPoint(rectangle);
    right_up = getRightUpPoint(rectangle);
    x_min = std::min(x_min, left_down.x);
    y_min = std::min(y_min, left_down.y);
    x_max = std::max(x_max, right_up.x);
    y_max = std::max(y_max, right_up.y);
  }
  return rectangle_t(point_t{x_min, y_min}, point_t{x_max, y_max});
}
void dimkashelk::Polygon::move(point_t point)
{
  point_t center = getCenter();
  move(point.x - center.x, point.y - center.y);
}
void dimkashelk::Polygon::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < count_; i++)
  {
    triangles_[i].move(delta_x, delta_y);
  }
  center.x += delta_x;
  center.y += delta_y;
}
void dimkashelk::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  for (size_t i = 0; i < count_; i++)
  {
    isotropicScaling(&triangles_[i], center, k);
  }
}
dimkashelk::Shape* dimkashelk::Polygon::clone() const
{
  return new Polygon(*this);
}
dimkashelk::Triangle* dimkashelk::Polygon::makeTriangles(point_t *points, size_t size)
{
  TriangulatePoints triangulatePoints(points, size);
  size_t s = 0;
  size_t capacity = 10;
  Triangle *triangles = new Triangle[capacity];
  while (triangulatePoints.hasNext())
  {
    triangles[s++] = triangulatePoints();
    if (s == capacity)
    {
      capacity += 10;
      Triangle *new_triangles = new Triangle[capacity];
      for (size_t i = 0; i < s; i++)
      {
        new_triangles[i] = triangles[i];
      }
      delete[] triangles;
      triangles = new_triangles;
    }
  }
  count_ = s;
  return triangles;
}
