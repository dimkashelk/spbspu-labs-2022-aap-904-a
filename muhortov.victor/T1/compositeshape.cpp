#include "compositeshape.hpp"
#include "iscale.hpp"

CompositeShape::CompositeShape(size_t capacity):
  shapes(new Shape * [capacity]),
  capacity_(capacity),
  size_(0)
{}

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
    delete [] shapes;
    shapes = extendShapes;
  }
  shapes[size_] = shape;
  size_ = size_ + 1;
}

void CompositeShape::pop_back()
{
  delete shapes[--size_];
  shapes[size_] = nullptr;
}

Shape *CompositeShape::at(size_t i)
{
  return shapes[i];
}

Shape *CompositeShape::operator[](size_t i)
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
  delete [] shapes;
}

void CompositeShape::scale(scale_t scale)
{
  for (size_t i = 0; i < size_; i++)
  {
    iScale(shapes[i], scale);
  }
}

void CompositeShape::move(point_t position)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(position);
  }
}

void CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(delta_x, delta_y);
  }
}

double CompositeShape::getArea()
{
  double sum = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  return sum;
}

rectangle_t CompositeShape::getFrameRect()
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
