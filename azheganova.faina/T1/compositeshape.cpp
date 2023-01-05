#include "compositeshape.h"
#include <algorithm>
#include "isoscale.h"

CompositeShape::CompositeShape(const CompositeShape & rhs):
  size_(rhs.size_),
  capacity_(rhs.capacity_),
  shape_(rhs.shape_)
{
  for (size_t i = 0; i < rhs.size_; ++i)
  {
    shape_[i] = rhs.shape_[i]->clone();
    size_++;
  }
}

CompositeShape::CompositeShape(CompositeShape && rhs):
  size_(rhs.size_),
  capacity_(rhs.capacity_),
  shape_(rhs.shape_)
{
  rhs.shape_ = nullptr;
  rhs.size_ = 0;
}

CompositeShape::CompositeShape(size_t capacity):
 size_(0),
 capacity_(capacity),
 shape_(new shape*[capacity])
{}

shape * CompositeShape::operator[](size_t i)
{
  return shape_[i];
}

shape * CompositeShape::operator[](size_t i) const
{
  return shape_[i];
}

double CompositeShape::getArea() const
{
  double square = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    square += shape_[i]->getArea();
  }
  return square;
}

rectangle_t CompositeShape::getFrameRect() const
{
  rectangle_t rectangle = shape_[0]->getFrameRect();
  double leftdownx = rectangle.pos.x - rectangle.width / 2;
  double leftdowny = rectangle.pos.x - rectangle.height / 2;
  double rightupx = rectangle.pos.x + rectangle.width / 2;
  double rightupy = rectangle.pos.y + rectangle.height / 2;
  double minx = leftdownx;
  double miny = leftdowny;
  double maxx = rightupx;
  double maxy = rightupy;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle = shape_[i]->getFrameRect();
    leftdownx = rectangle.pos.x - rectangle.width / 2;
    leftdowny = rectangle.pos.x - rectangle.height / 2;
    rightupx = rectangle.pos.x + rectangle.width / 2;
    rightupy = rectangle.pos.y + rectangle.height / 2;
    minx = std::min(minx, leftdownx);
    miny = std::min(miny, leftdowny);
    maxx = std::max(maxx, rightupx);
    maxy = std::max(maxy, rightupy);
  }
  point_t center({(minx + maxx) / 2, (miny + maxy) / 2});
  rectangle_t framerect{center, maxx - minx, maxy - miny};
  return framerect;
}

void CompositeShape::move(const point_t position)
{
  rectangle_t framerect = CompositeShape::getFrameRect();
  double dx = position.x - framerect.pos.x;
  double dy = position.y - framerect.pos.y;
  move(dx, dy);
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}

void CompositeShape::scale(const point_t & position, double k)
{
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], position, k);
  }
}

size_t CompositeShape::size() const
{
  return size_;
}

void CompositeShape::push_back(shape * shapes)
{
  if (capacity_ == size_)
  {
    shape ** new_shape = new shape * [capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
    shape_[size_] = shapes;
    size_++;
  }
}
