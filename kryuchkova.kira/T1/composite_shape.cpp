#include "composite_shape.h"
#include <limits>
#include <stdexcept>
#include "base_types.h"
#include "shape.h"

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

kryuchkova::Shape *kryuchkova::CompositeShape::operator[](size_t index)
{
  return shapes[index];
}

const kryuchkova::Shape *kryuchkova::CompositeShape::operator[](size_t index) const
{
  return shapes[index];
}

kryuchkova::CompositeShape::~CompositeShape()
{
  free(shapes, size);
}

double kryuchkova::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size; i++)
  {
    area += shapes[i]->getArea();
  }
  return area;
}

kryuchkova::rectangle_t kryuchkova::CompositeShape::getFrameRect() const
{
  double minx = std::numeric_limits< double >::max();
  double miny = std::numeric_limits< double >::max();
  double maxx = std::numeric_limits< double >::min();
  double maxy = std::numeric_limits< double >::min();
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t rectangle = shapes[i]->getFrameRect();
    double lb_x = rectangle.pos.x - rectangle.width / 2;
    double lb_y = rectangle.pos.y - rectangle.height / 2;
    double ru_x = rectangle.pos.x + rectangle.width / 2;
    double ru_y = rectangle.pos.y + rectangle.height / 2;

    if (lb_x < minx)
    {
      minx = lb_x;
    }
    if (lb_y < miny)
    {
      miny = lb_y;
    }
    if (ru_x > maxx)
    {
      maxx = ru_x;
    }
    if (ru_y > maxy)
    {
      maxy = ru_y;
    }
  }
  return rectangle_t(maxx - minx, maxy - miny, point_t((maxx + minx) / 2, (maxy + miny) / 2));
}

void kryuchkova::CompositeShape::move(point_t point)
{
  for (size_t i = 0; i < size; i++)
  {
    point_t pos = getFrameRect().pos;
    move (point.x - pos.x, point.y - pos.y);
  }
}

void kryuchkova::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void kryuchkova::CompositeShape::scale(double k)
{
  for (size_t i = 0; i < size; i++)
  {
    shapes[i]->scale(k);
  }
}

void kryuchkova::CompositeShape::isoScale(point_t point, double k)
{
  for (size_t i = 0; i < size; i++)
  {
    kryuchkova::isoScale(shapes[i], point, k);
  } 
}

void kryuchkova::CompositeShape::push_back(Shape *sh)
{
  if (size == capacity)
  {
    Shape **new_shapes = new Shape*[capacity + 20];
    capacity += 20;
    for (size_t i = 0; i < size; i++)
    {
      new_shapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = new_shapes;
  }
  shapes[size] = sh;
  size++;
}

void kryuchkova::CompositeShape::push_back(const Shape *sh)
{
  Shape *clone = sh->clone();
  try
  {
    push_back(clone);
  }
  catch(...)
  {
    delete clone;
    throw;
  }
}

void kryuchkova::CompositeShape::pop_back()
{
  delete shapes[size - 1];
  size--;
}
