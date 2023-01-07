#include "composite_shape.h"
#include <stdexcept>
#include "base_types.h"

kryuchkova::CompositeShape::CompositeShape():
  size(0),
  capacity(10),
  shapes(new Shape*[capacity])
{}

kryuchkova::CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  size(compositeShape.size),
  capacity(compositeShape.capacity),
  shapes(new Shape*[capacity])
{
  for (size_t i = 0; i < size; i++)
  {
    try
    {
      shapes[i] = compositeShape.shapes[i]->clone();
    }
    catch(...)
    {
      free(shapes, i);
      throw;
    }
  }
}

kryuchkova::CompositeShape::CompositeShape(CompositeShape &&compositeShape):
  size(compositeShape.size),
  capacity(compositeShape.capacity),
  shapes(compositeShape.shapes)
{
  compositeShape.shapes = nullptr;
  compositeShape.size = 0;
}

kryuchkova::CompositeShape &kryuchkova::CompositeShape::operator=(const CompositeShape &compositeShape)
{
  if (&compositeShape != this)
  {
    Shape **shapes = new Shape *[compositeShape.capacity];
    for (size_t i = 0; i < size; i++)
    {
      try
      {
        shapes[i] = compositeShape.shapes[i]->clone();
      }
      catch (...)
      {
        free(shapes, i);
        throw;
      }
    }
    free(shapes, size);
    this->shapes = shapes;
    this->size = compositeShape.size;
    this->capacity = compositeShape.capacity;    
  }
  return *this;
}

kryuchkova::CompositeShape &kryuchkova::CompositeShape::operator=(CompositeShape &&compositeShape)
{
  if (&compositeShape != this)
  {
    free(shapes, size);
    size = compositeShape.size;
    capacity = compositeShape.capacity;
    shapes = compositeShape.shapes;
    compositeShape.shapes = nullptr;
    compositeShape.size = 0;
  }
  return *this;
}
