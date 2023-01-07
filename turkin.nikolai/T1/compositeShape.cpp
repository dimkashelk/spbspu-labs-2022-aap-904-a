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
    shapes[i]->move(position.x - getFrameRect().pos.x, position.y - getFrameRect().pos.y);
  }
}

double turkin::CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  return sum;
}

turkin::Shape * turkin::CompositeShape::at(size_t id) const
{
  return shapes[id];
}

turkin::rectangle_t turkin::CompositeShape::getFrameRect() const
{
  double A = 0.0;
  double B = 0.0;
  double C = 0.0;
  double D = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t buffer = shapes[i]->getFrameRect();
    A = (A > buffer.pos.x + buffer.width / 2.0) ? A : buffer.pos.x + buffer.width / 2.0;
    B = (B > buffer.pos.y + buffer.height / 2.0) ? B : buffer.pos.y + buffer.height / 2.0;
    C = (C < buffer.pos.x - buffer.width / 2.0) ? C : buffer.pos.x - buffer.width / 2.0;
    D = (D < buffer.pos.y - buffer.height / 2.0) ? D : buffer.pos.y - buffer.height / 2.0;
  }
  return {{(A + C) / 2.0, (B + D) / 2.0}, C - A, D - B};
}

turkin::Shape * turkin::CompositeShape::operator[](size_t id) const
{
  return shapes[id];
}

void turkin::CompositeShape::push_back(const turkin::Shape * shp)
{
  Shape * clone = shp->clone();
  push_back(clone);
}

void turkin::CompositeShape::push_back(Shape * shp)
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
  shapes[size_++] = shp;
}

