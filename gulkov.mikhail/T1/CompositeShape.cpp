#include "CompositeShape.hpp"
#include "IsoScale.hpp"

CompositeShape::CompositeShape(size_t capacity):
  shapes(new Shape *[capacity]),
  capacity_(capacity),
  size_(0)
{}

void CompositeShape::push_back(const Shape *shape)
{
  Shape *clone = shape->clone();
  push_back(clone);
}

void CompositeShape::push_back(Shape *shape)
{
  if (capacity_ == size_)
  {
    Shape **extendShapes = new Shape *[capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; i++)
    {
      extendShapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = extendShapes;
  }
  shapes[size_++] = shape;
}

void CompositeShape::pop_back()
{
  delete shapes[--size_];
}

const Shape *CompositeShape::at(size_t i) const
{
  return shapes[i];
}

Shape *CompositeShape::at(size_t i)
{
  return shapes[i];
}

Shape *CompositeShape::operator[](size_t i)
{
  return shapes[i];
}

const Shape *CompositeShape::operator[](size_t i) const
{
  return shapes[i];
}

bool CompositeShape::empty() const
{
  return size_ == 0;
}

size_t CompositeShape::size() const
{
  return size_;
}

CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
}

void CompositeShape::scale(scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    doIsoScale(shapes[i], scale);
  }
}

void CompositeShape::move(point_t position)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(position.x - getFrameRect().pos.x, position.y - getFrameRect().pos.y);
  }
}

void CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(delta_x, delta_y);
  }
}

double CompositeShape::getArea() const
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  return sum;
}

rectangle_t CompositeShape::getFrameRect() const
{
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;
  double d = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle_t temp = shapes[i]->getFrameRect();
    a = (a > temp.pos.x + temp.width / 2.0) ? a : temp.pos.x + temp.width / 2.0;
    b = (b > temp.pos.y + temp.height / 2.0) ? b : temp.pos.y + temp.height / 2.0;
    c = (c < temp.pos.x - temp.width / 2.0) ? c : temp.pos.x - temp.width / 2.0;
    d = (d < temp.pos.y - temp.height / 2.0) ? d : temp.pos.y - temp.height / 2.0;
  }
  return {{(a + c) / 2.0, (b + d) / 2.0}, c - a, d - b};
}
