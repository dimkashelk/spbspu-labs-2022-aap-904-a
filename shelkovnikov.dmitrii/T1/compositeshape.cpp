#include "compositeshape.h"
#include <algorithm>
#include <limits>
#include "base_functions.h"
#include "isotropic_scaling.h"
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
    try
    {
      shapes_[i] = compositeShape.shapes_[i]->clone();
    }
    catch (...)
    {
      free();
      throw;
    }
  }
}
dimkashelk::CompositeShape::CompositeShape(CompositeShape &&compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(compositeShape.shapes_)
{
  compositeShape.shapes_ = nullptr;
  compositeShape.size_ = 0;
}
dimkashelk::CompositeShape &dimkashelk::CompositeShape::operator=(const CompositeShape &other)
{
  if (std::addressof(other) != this)
  {
    Shape **shapes = new Shape *[other.capacity_];
    for (size_t i = 0; i < size_; i++)
    {
      try
      {
        shapes[i] = other.shapes_[i]->clone();
      }
      catch (...)
      {
        for (size_t j = 0; j < i; j++)
        {
          delete shapes[j];
        }
        delete[] shapes;
        throw;
      }
    }
    free();
    shapes_ = shapes;
    size_ = other.size_;
    capacity_ = other.capacity_;
    return *this;
  }
}
dimkashelk::CompositeShape &dimkashelk::CompositeShape::operator=(CompositeShape &&tmp)
{
  if (&tmp != this)
  {
    free();
    size_ = tmp.size_;
    capacity_ = tmp.capacity_;
    shapes_ = tmp.shapes_;
    tmp.shapes_ = nullptr;
    tmp.size_ = 0;
  }
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
  free();
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
  if (empty())
  {
    throw std::logic_error("CompositeShape empty");
  }
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
  return makeRectangle(point_t{x_min, y_min}, point_t{x_max, y_max});
}
void dimkashelk::CompositeShape::move(point_t point)
{
  point_t center = getFrameRect().pos;
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
  if (empty())
  {
    throw std::logic_error("CompositeShape empty");
  }
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; i++)
  {
    dimkashelk::isotropicScaling(shapes_[i], center, k);
  }
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
  shapes_[size_] = shp;
  size_++;
}
void dimkashelk::CompositeShape::push_back(const Shape *shp)
{
  try
  {
    push_back(shp->clone());
  }
  catch (...)
  {}
}
void dimkashelk::CompositeShape::pop_back()
{
  delete shapes_[size_ - 1];
  size_--;
}
dimkashelk::Shape* dimkashelk::CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shapes_[id];
}
const dimkashelk::Shape* dimkashelk::CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
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
void dimkashelk::CompositeShape::isotropicScaling(point_t point, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("Coefficient below zero");
  }
  point_t point_1 = getFrameRect().pos;
  move(point);
  point_t point_2 = getFrameRect().pos;
  scale(k);
  move(-k * (point_2.x - point_1.x), -k * (point_2.y - point_1.y));
}
void dimkashelk::CompositeShape::free()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}
