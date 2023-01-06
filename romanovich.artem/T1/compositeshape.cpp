#include "compositeshape.h"
#include <stdexcept>
void CompositeShape::push_back(Shape *shp)
{
  size_t capAdd = 2;
  Shape **newShape = new Shape *[capacity_ + capAdd];
  capacity_ += capAdd;
  for (size_t i = 0; i <= size_; ++i)
  {
    newShape[i] = shape_[i];
  }
  delete[] shape_;
  shape_ = newShape;
  shape_[size_] = shp;
  size_++;
}
void CompositeShape::push_back(const Shape *shp)
{
  size_t capAdd = 2;
  Shape **newShape = new Shape *[capacity_ + capAdd];
  capacity_ += capAdd;
  for (size_t i = 0; i <= size_; ++i)
  {
    newShape[i] = shape_[i];
  }
  delete[] shape_;
  shape_ = newShape;
  shape_[size_] = shp->clone();
  size_++;
}
void CompositeShape::pop_back()
{
  delete shape_[size_];
  size_--;
}
void CompositeShape::scale(const point_t &position, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling koeff.");
  }
  unsafeScale(position, k);
}
void CompositeShape::unsafeScale(const point_t &position, double k) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    point_t s = shift(position, shape_[i]->getFrameRect().pos);
    shape_[i]->move(s.x, s.y);
    s.x *= -k;
    s.y *= -k;
    shape_[i]->scale(k);
    shape_[i]->move(s.x, s.y);
  }
}
CompositeShape::CompositeShape(size_t capacity):
  shape_(new Shape *[capacity]),
  size_(0),
  capacity_(capacity)
{
}
Shape *CompositeShape::operator[](size_t id)
{
  return at(id);
}
void CompositeShape::move(point_t position)
{
  point_t s = shift(position, getFrameRect().pos);
  move(s.x, s.y);
}
void CompositeShape::scale(double k)
{
  unsafeScale(getFrameRect().pos, k);
}
void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shape_[i]->move(dx, dy);
  }
}
Shape *CompositeShape::at(size_t id)
{
  return shape_[id];
}
size_t CompositeShape::size() const noexcept
{
  return size_;
}
bool CompositeShape::empty() const noexcept
{
  return (size_ == 0);
}
CompositeShape::CompositeShape(const CompositeShape &rhs):
  CompositeShape(rhs.capacity_)
{
  size_ = rhs.size_;
  for (size_t i = 0; i < rhs.size_; ++i)
  {
    shape_[i] = rhs.shape_[i]->clone();
  }
}
CompositeShape::CompositeShape(CompositeShape &&rhs) noexcept:
  CompositeShape(rhs.capacity_)
{
  size_ = rhs.size_;
  for (size_t i = 0; i < rhs.size_; ++i)
  {
    shape_[i] = rhs.shape_[i]->clone();
  }
}
double CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shape_[i]->getArea();
  }
  return area;
}
rectangle_t CompositeShape::getFrameRect()
{
  rectangle_t rectangle = shape_[0]->getFrameRect();
  for (size_t i = 1; i < size_; i++)
  {
    rectangle = shape_[i]->getFrameRect();
  }
  return rectangle;
}
CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete[] shape_;
}
CompositeShape &CompositeShape::operator=(const CompositeShape &rhs)
{
  Shape **newShape = nullptr;
  size_t newSize = 0;
  try
  {
    newShape = new Shape *[rhs.capacity_];
    for (size_t i = 0; i < rhs.size_; ++i)
    {
      newShape[i] = rhs.shape_[i]->clone();
      ++newSize;
    }
  }
  catch (...)
  {
    for (size_t i = 0; i < newSize; ++i)
    {
      delete newShape[i];
    }
    delete[] newShape;
    throw;
  }
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete[] shape_;
  shape_ = newShape;
  capacity_ = rhs.capacity_;
  size_ = newSize;
  return *this;
}
CompositeShape &CompositeShape::operator=(CompositeShape &&rhs) noexcept
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete[] shape_;
  shape_ = rhs.shape_;
  capacity_ = rhs.capacity_;
  size_ = rhs.size_;
  return *this;
}
