#include "increasearr.h"
#include <cstddef>
#include "base_types.h"
#include "compositeshape.h"

void increaseArr(shape * shapes, size_t size, size_t new_capacity)
{
  shape ** shape_;
  size_t size_;
  size_t capacity_;
  shape * shape2 = shapes->clone();
  if (capacity_ == size_)
  {
    shape ** new_shape = nullptr;
    try
    {
      new_shape = new shape * [capacity_ + 10];
    }
    catch (...)
    {
      delete shape2;
      throw;
    }
    capacity_ += 10;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
  shape_[size_++] = shape2;
}
