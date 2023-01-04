#include "polygon.h"
#include <algorithm>
#include <stdexcept>
#include "isotropic_scaling.h"
#include "base_functions.h"
#include "make_triangles.h"
dimkashelk::Polygon::Polygon(const point_t *points, size_t size):
  count_(0),
  triangles_(makeTriangles(points, size)),
  center_(getCenterOfWeight(points, size))
{
  if (size >= 3)
  {
    count_ = size - 2;
  }
}
dimkashelk::Polygon::Polygon(const Polygon &polygon):
  count_(polygon.count_),
  triangles_(new Triangle[polygon.count_]),
  center_(polygon.center_)
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
  rectangle_t rectangle = dimkashelk::getFrameRect(triangles_[0].getFrameRect(), triangles_[0].getFrameRect());
  for (size_t i = 1; i < count_; i++)
  {
    rectangle = dimkashelk::getFrameRect(triangles_[i].getFrameRect(), triangles_[i].getFrameRect());
  }
  return rectangle;
}
void dimkashelk::Polygon::move(point_t point)
{
  move(point.x - center_.x, point.y - center_.y);
}
void dimkashelk::Polygon::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < count_; i++)
  {
    triangles_[i].move(delta_x, delta_y);
  }
  center_.x += delta_x;
  center_.y += delta_y;
}
void dimkashelk::Polygon::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  for (size_t i = 0; i < count_; i++)
  {
    isotropicScaling(&triangles_[i], center_, k);
  }
}
dimkashelk::Shape* dimkashelk::Polygon::clone() const
{
  return new Polygon(*this);
}
