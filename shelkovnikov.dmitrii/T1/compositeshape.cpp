#include "compositeshape.h"
#include <algorithm>
#include <limits>
#include <stdexcept>
#include "base_functions.h"
dimkashelk::CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shapes_(new Shape*[capacity_])
{}
dimkashelk::CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(new Shape*[capacity_])
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = compositeShape.shapes_[i]->clone();
  }
}
dimkashelk::CompositeShape::CompositeShape(CompositeShape &&compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(new Shape*[capacity_])
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = compositeShape.shapes_[i];
  }
  delete[] compositeShape.shapes_;
}
dimkashelk::CompositeShape &dimkashelk::CompositeShape::operator=(const CompositeShape &other)
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  shapes_ = new Shape*[capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = other.shapes_[i]->clone();
  }
  return *this;
}
dimkashelk::CompositeShape &dimkashelk::CompositeShape::operator=(CompositeShape &&tmp)
{
  operator=(tmp);
  for (size_t i = 0; i < size_; i++)
  {
    delete tmp.shapes_[i];
  }
  delete[] tmp.shapes_;
  return *this;
}
dimkashelk::Shape *dimkashelk::CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}
const dimkashelk::Shape *dimkashelk::CompositeShape::operator[](size_t id) const
{
  return shapes_[id];
}
dimkashelk::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}
double dimkashelk::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}
dimkashelk::rectangle_t dimkashelk::CompositeShape::getFrameRect() const
{
  rectangle_t rectangle = shapes_[0]->getFrameRect();
  point_t left_down = getLeftDownPoint(rectangle);
  point_t right_up = getRightUpPoint(rectangle);
  double x_min = left_down.x;
  double y_min = left_down.y;
  double x_max = right_up.x;
  double y_max = right_up.y;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle = shapes_[i]->getFrameRect();
    left_down = getLeftDownPoint(rectangle);
    right_up = getRightUpPoint(rectangle);
    x_min = std::min(x_min, left_down.x);
    y_min = std::min(y_min, left_down.y);
    x_max = std::max(x_max, right_up.x);
    y_max = std::max(y_max, right_up.y);
  }
  return rectangle_t(point_t{x_min, y_min}, point_t{x_max, y_max});
}
void dimkashelk::CompositeShape::move(point_t point)
{
  point_t center = getCenter();
  move(point.x - center.x, point.y - center.y);
}
void dimkashelk::CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(delta_x, delta_y);
  }
}
void dimkashelk::CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  point_t center = getCenter();
  for (size_t i = 0; i < size_; i++)
  {
    point_t shape_center = shapes_[i]->getFrameRect().point;
    shapes_[i]->scale(k);
    shapes_[i]->move(k * (shape_center.x - center.x), k * (shape_center.y - center.y));
  }
}
dimkashelk::point_t dimkashelk::CompositeShape::getCenter() const
{
  return getFrameRect().point;
}
void dimkashelk::CompositeShape::push_back(Shape *shp)
{
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  if (size_ == capacity_)
  {
    if (max_size_t == capacity_)
    {
      throw std::overflow_error("Stack overflow");
    }
    Shape **new_shapes = new Shape*[capacity_ + 10];
    capacity_ += 10;
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
void dimkashelk::CompositeShape::pop_back()
{
  if (!empty())
  {
    delete shapes_[size_ - 1];
    size_--;
  }
}
dimkashelk::Shape* dimkashelk::CompositeShape::at(size_t id)
{
  return shapes_[id];
}
const dimkashelk::Shape* dimkashelk::CompositeShape::at(size_t id) const
{
  return shapes_[id];
}
bool dimkashelk::CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t dimkashelk::CompositeShape::size() const noexcept
{
  return size_;
}
