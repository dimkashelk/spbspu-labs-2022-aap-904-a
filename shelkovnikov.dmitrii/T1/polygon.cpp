#include "polygon.h"
#include <algorithm>
#include "triangulatepoints.h"
#include "isotropic_scaling.h"
Polygon::Polygon(point_t *points, size_t size):
  triangles_(nullptr),
  count_(0)
{
  TriangulatePoints triangulatePoints(points, size);
  count_ = triangulatePoints.getSize();
  triangles_ = new Triangle[count_];
  for (size_t i = 0; i < count_; i++)
  {
    triangles_[i] = triangulatePoints();
  }
}
Polygon::Polygon(const Polygon &polygon)
{
  triangles_ = new Triangle[polygon.count_];
  for (size_t i = 0; i < polygon.count_; i++)
  {
    triangles_[i] = polygon.triangles_[i];
  }
  count_ = polygon.count_;
}
Polygon::Polygon(Polygon &&polygon):
  triangles_(polygon.triangles_),
  count_(polygon.count_)
{
  delete[] polygon.triangles_;
}
Polygon::~Polygon() noexcept
{
  delete[] triangles_;
}
Polygon &Polygon::operator=(const Polygon &other)
{
  if (triangles_)
  {
    delete[] triangles_;
  }
  triangles_ = new Triangle[other.count_];
  for (size_t i = 0; i < other.count_; i++)
  {
    triangles_[i] = other.triangles_[i];
  }
  count_ = other.count_;
  return *this;
}
Polygon &Polygon::operator=(Polygon &&tmp)
{
  operator=(tmp);
  return *this;
}
double Polygon::getArea() const
{
  double global_area = 0.0;
  for (size_t i = 0; i < count_; i++)
  {
    global_area += triangles_[i].getArea();
  }
  return global_area;
}
rectangle_t Polygon::getFrameRect() const
{
  double x_min = triangles_[0].getFrameRect().getLeftDownPoint().x;
  double y_min = triangles_[0].getFrameRect().getLeftDownPoint().y;
  double x_max = x_min;
  double y_max = y_min;
  for (size_t i = 0; i < count_; i++)
  {
    rectangle_t rectangle = triangles_[i].getFrameRect();
    x_min = std::min(x_min, rectangle.getLeftDownPoint().x);
    y_min = std::min(y_min, rectangle.getLeftDownPoint().y);
    x_max = std::max(x_max, rectangle.getRightUpPoint().x);
    y_max = std::max(y_max, rectangle.getRightUpPoint().y);
  }
  return rectangle_t(point_t(x_min, y_min), point_t(x_max, y_max));
}
void Polygon::move(point_t point)
{
  point_t center = getCenter();
  vector_t direction(point, center);
  move(direction.x, direction.y);
}
void Polygon::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < count_; i++)
  {
    triangles_[i].move(delta_x, delta_y);
  }
}
void Polygon::scale(double k)
{
  point_t center = getCenter();
  for (size_t i = 0; i < count_; i++)
  {
    isotropic_scaling(&triangles_[i], center, k);
  }
}
Shape* Polygon::clone() const
{
  return new Polygon(*this);
}
point_t Polygon::getCenter() const
{
  double x_sum = 0;
  double y_sum = 0;
  for (size_t i = 0; i < count_; i++)
  {
    point_t *points = triangles_[i].getPoints();
    for (size_t j = 0; j < 3; j++)
    {
      x_sum += points[j].x;
      y_sum += points[j].y;
    }
    delete[] points;
  }
  return point_t(x_sum / (count_ * 3), y_sum / (count_ * 3));
}
std::istream& operator>>(std::istream &in, Polygon &polygon)
{
  size_t size = 0;
  size_t capacity = 10;
  point_t *points = new point_t[capacity];
  do
  {
    point_t point;
    in >> point;
    if (in)
    {
      points[size] = point;
      size++;
      if (size == capacity)
      {
        capacity += 10;
        point_t *new_points = new point_t[capacity];
        for (size_t i = 0; i < size; i++)
        {
          new_points[i] = points[i];
        }
        delete[] points;
        points = new_points;
      }
    }
  }
  while (in);
  try
  {
    polygon = Polygon(points, size);
  }
  catch (...)
  {
    delete[] points;
    throw;
  }
  delete[] points;
  return in;
}
