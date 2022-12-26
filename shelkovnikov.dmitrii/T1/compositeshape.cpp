#include "compositeshape.h"
#include <algorithm>
#include "vector_t.h"
CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shapes_(new Shape*[capacity_])
{}
CompositeShape::CompositeShape(Shape **shapes, size_t size):
  size_(size),
  capacity_(size_),
  shapes_(new Shape*[capacity_])
{
  shapes_ = new Shape*[capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = shapes[i]->clone();
  }
}
Shape *CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}
const Shape *CompositeShape::operator[](size_t id) const
{
  return shapes_[id];
}
CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}
double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}
rectangle_t CompositeShape::getFrameRect() const
{
  rectangle_t rectangle = shapes_[0]->getFrameRect();
  double x_min = rectangle.getLeftDownPoint().x;
  double y_min = rectangle.getLeftDownPoint().y;
  double x_max = rectangle.getRightUpPoint().x;
  double y_max = rectangle.getRightUpPoint().y;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle = shapes_[i]->getFrameRect();
    x_min = std::min(x_min, rectangle.getLeftDownPoint().x);
    y_min = std::min(y_min, rectangle.getLeftDownPoint().y);
    x_max = std::max(x_max, rectangle.getRightUpPoint().x);
    y_max = std::max(y_max, rectangle.getRightUpPoint().y);
  }
  return rectangle_t(x_min, y_min, x_max, y_max);
}
void CompositeShape::move(point_t point)
{
  point_t center = getCenter();
  vector_t direction(point, center);
  move(direction.x, direction.y);
}
void CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(delta_x, delta_y);
  }
}
void CompositeShape::scale(double k)
{
  point_t center = getCenter();
  for (size_t i = 0; i < size_; i++)
  {
    point_t shape_center = shapes_[i]->getFrameRect().point;
    vector_t direction(shape_center, center);
    direction *= k;
    shapes_[i]->scale(k);
    shapes_[i]->move(direction.x, direction.y);
  }
}
point_t CompositeShape::getCenter() const
{
  return getFrameRect().point;
}
void CompositeShape::push_back(Shape *shp)
{
  if (size_ == capacity_)
  {
    capacity_ += 10;
    Shape **new_shapes = new Shape*[capacity_];
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes_[i];
    }
    delete[] shapes_;
    shapes_ = new_shapes;
  }
  shapes_[size_] = shp->clone();
  size_++;
}
void CompositeShape::pop_back()
{
  size_--;
}
Shape* CompositeShape::at(size_t id)
{
  return shapes_[id];
}
const Shape* CompositeShape::at(size_t id) const
{
  return shapes_[id];
}
bool CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t CompositeShape::size() const noexcept
{
  return size_;
}
