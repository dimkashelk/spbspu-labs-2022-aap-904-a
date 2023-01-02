#include <stdexcept>
#include "compositeshape.h"
void CompositeShape::push_back(Shape *shp)
{
  size_t capAdd = 2;
  if (capacity_ < size_)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
  Shape **newShape = new Shape *[capacity_ + capAdd];
  capacity_ += capAdd;
  for (size_t i = 0; i < size_; ++i)
  {
    newShape[i] = shape_[i];
  }
  delete[] shape_;
  shape_ = newShape;
  shape_[size_++] = shp;
}
CompositeShape::CompositeShape(size_t capacity)
{
}
