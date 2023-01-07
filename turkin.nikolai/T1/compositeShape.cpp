#include "compositeShape.h"
#include "isoscale.h"

turkin::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes[i];
  }
  delete [] shapes;
}

turkin::CompositeShape::CompositeShape(size_t capacity):
  shapes(new Shape * [capacity]),
  capacity_(capacity),
  size_(0)
{}

size_t turkin::CompositeShape::size() const
{
  return size_;
}

bool turkin::CompositeShape::empty() const
{
  return size_ == 0;
}

void turkin::CompositeShape::scale(turkin::scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    turkin::isoScale(shapes[i], scale);
  }
}

void turkin::CompositeShape::pop_back()
{
  delete shapes[--size_];
  shapes[size_] = nullptr;
}

void turkin::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void turkin::CompositeShape::move(turkin::point_t position)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(position);
  }
}

double turkin::CompositeShape::getArea()
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  return sum;
}

turkin::Shape * turkin::CompositeShape::at(size_t id)
{
  return shapes[id];
}

turkin::rectangle_t turkin::CompositeShape::getFrameRect()
{
  double width = 0.0;
  double height = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    width = (width > shapes[i]->getFrameRect().width) ? width : shapes[i]->getFrameRect().width;
    height = (height > shapes[i]->getFrameRect().height) ? height : shapes[i]->getFrameRect().height;
  }
  return {{width / 2, height / 2}, width, height};
}

turkin::Shape * turkin::CompositeShape::operator[](size_t id)
{
  return shapes[id];
}

void turkin::CompositeShape::push_back(turkin::Shape * shp)
{
  if (capacity_ == size_)
  {
    Shape ** extendShapes = new Shape * [capacity_ + 10];
    capacity_ = capacity_ + 10;
    for (size_t i = 0; i < size_; i++)
    {
      extendShapes[i] = shapes[i];
    }
    delete [] shapes;
    shapes = extendShapes;
  }
  shapes[size_] = shp;
  size_ = size_ + 1;
}
