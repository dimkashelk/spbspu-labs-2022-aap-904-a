#include "compositeshape.h"
#include <stdexcept>
void CompositeShape::push_back(Shape *shp)
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
  shape_[size_] = shp;
  size_++;
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
CompositeShape::CompositeShape(size_t capacity)
{
  shape_ = new Shape *[capacity];
  capacity_ = capacity;
  size_ = 0;
}
Shape *CompositeShape::operator[](size_t id)
{
  return shape_[id];
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
Shape *CompositeShape::at(size_t)
{
  return nullptr;
}
CompositeShape *CompositeShape::clone() const
{
  return nullptr;
}
size_t CompositeShape::size()
{
  return size_;
}
bool CompositeShape::empty()
{
  return false;
}
CompositeShape::CompositeShape(const CompositeShape &)
{
}
CompositeShape::CompositeShape(CompositeShape &)
{
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
rectangle_t CompositeShape::getFrameRect() const
{
  return rectangle_t();
}
void CompositeShape::pop_back()
{
}
CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete[] shape_;
}
