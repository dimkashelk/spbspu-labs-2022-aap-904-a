#include "compositeshape.h"
CompositeShape::CompositeShape(Shape **shapes, size_t size):
  shapes_(nullptr),
  size_(size)
{
  shapes_ = new Shape*[size_];
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = shapes[i]->clone();
  }
}
const double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}
