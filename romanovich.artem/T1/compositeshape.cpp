#include "compositeshape.h"
#include <stdexcept>
void CompositeShape::push_back(Shape *shp)
{
  size_t capAdd = 2;
  if (capacity_ < size_)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
  Shape **newShape = nullptr;
  try
  {
    newShape = new Shape *[capacity_ + capAdd];
  }
  catch (...)
  {
    throw std::invalid_argument("Error while adding figure.");
  }
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
  if (capacity_ < size_)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
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
}
void CompositeShape::isoScale(Shape &shape, double secondPosX, double secondPosY, double k)
{
  double firstPosX = shape.getFrameRect().pos.x;
  double firstPosY = shape.getFrameRect().pos.y;
  double dx = secondPosX - firstPosX;
  double dy = secondPosY - firstPosY;
  shape.move(dx, dy);
  dx *= -k;
  dy *= -k;
  shape.scale(k);
  shape.move(dx, dy);
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
void CompositeShape::move(point_t)
{
}
void CompositeShape::scale(double)
{
}
void CompositeShape::move(double, double)
{
}
Shape *CompositeShape::at(size_t id)
{
  return shape_[id];
}
CompositeShape *CompositeShape::clone()
{
  return nullptr;
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
  return rectangle_t{};
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
    throw std::invalid_argument("Error while coping figure.");
  }
  delete[] shape_;
  shape_ = newShape;
  capacity_ = rhs.capacity_;
  size_ = newSize;
  return *this;
}
