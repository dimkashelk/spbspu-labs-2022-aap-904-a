#include "composite_shape.h"
#include <limits>
#include <stdexcept>
#include "base_types.h"
#include "shape.h"

kryuchkova::CompositeShape::CompositeShape():
  size_(0),
  capacity(1),
  shapes(new Shape*[capacity])
{}

kryuchkova::CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  size_(compositeShape.size_),
  capacity(compositeShape.capacity),
  shapes(new Shape*[capacity])
{
  for (size_t i = 0; i < size_; i++)
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
  size_(compositeShape.size_),
  capacity(compositeShape.capacity),
  shapes(compositeShape.shapes)
{
  compositeShape.shapes = nullptr;
  compositeShape.size_ = 0;
}

kryuchkova::CompositeShape &kryuchkova::CompositeShape::operator=(const CompositeShape &compositeShape)
{
  if (std::addressof(compositeShape) != this)
  {
    Shape **shapes = new Shape *[compositeShape.capacity];
    for (size_t i = 0; i < size_; i++)
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
    free(shapes, size_);
    this->shapes = shapes;
    this->size_ = compositeShape.size_;
    this->capacity = compositeShape.capacity;
  }
  return *this;
}

kryuchkova::CompositeShape &kryuchkova::CompositeShape::operator=(CompositeShape &&compositeShape)
{
  if (std::addressof(compositeShape) != this)
  {
    free(shapes, size_);
    size_ = compositeShape.size_;
    capacity = compositeShape.capacity;
    shapes = compositeShape.shapes;
    compositeShape.shapes = nullptr;
    compositeShape.size_ = 0;
  }
  return *this;
}

kryuchkova::Shape *kryuchkova::CompositeShape::operator[](const size_t index)
{
  return shapes[index];
}

const kryuchkova::Shape *kryuchkova::CompositeShape::operator[](const size_t index) const
{
  return shapes[index];
}

kryuchkova::CompositeShape::~CompositeShape()
{
  free(shapes, size_);
}

double kryuchkova::CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; i++)
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
  for (size_t i = 0; i < size_; i++)
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
  return rectangle_t{maxx - minx, maxy - miny, point_t{(maxx + minx) / 2, (maxy + miny) / 2}};
}

void kryuchkova::CompositeShape::move(const point_t point)
{
  for (size_t i = 0; i < size_; i++)
  {
    point_t pos = getFrameRect().pos;
    move (point.x - pos.x, point.y - pos.y);
  }
}

void kryuchkova::CompositeShape::move(const double dx, const double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void kryuchkova::CompositeShape::scale(const double k)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->scale(k);
  }
}

void kryuchkova::CompositeShape::isoScale(const point_t point, const double k)
{
  if (empty())
  {
    throw std::invalid_argument("CompositeShape is empty, nothing to scale");
  }
  for (size_t i = 0; i < size_; i++)
  {
    kryuchkova::isoScale(shapes[i], point, k);
  }
}

void kryuchkova::CompositeShape::push_back(Shape *sh)
{
  if (size_ == capacity)
  {
    Shape **new_shapes = new Shape*[capacity + 2];
    capacity += 2;
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = new_shapes;
  }
  shapes[size_] = sh;
  size_++;
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
  delete shapes[size_ - 1];
  size_--;
}

kryuchkova::Shape* kryuchkova::CompositeShape::at(const size_t index)
{
  if (index > size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes[index];
}

const kryuchkova::Shape* kryuchkova::CompositeShape::at(const size_t index) const
{
  if (index > size_)
  {
    throw std::out_of_range("out of range");
  }
  return shapes[index];
}

bool kryuchkova::CompositeShape::empty() const
{
  return size_ == 0;
}

size_t kryuchkova::CompositeShape::size() const
{
  return size_;
}

void kryuchkova::CompositeShape::free(Shape **shapes, const size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

void kryuchkova::sortByArea(kryuchkova::CompositeShape *comp_sh)
{
  for (size_t i = 0; i < comp_sh->size() - 1; i++)
  {
    if (!(comp_sh->at(i) < comp_sh->at(i + 1)))
    {
      kryuchkova::Shape *temp = comp_sh->at(i);
      *comp_sh->at(i) = *comp_sh->at(i + 1);
      *comp_sh->at(i + 1) = *temp;
    }
  }
}
