#include "compositeshape.h"
#include <stdexcept>
#include <cstddef>
#include "isoscale.h"

CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shape_(new Shape*[capacity_])
{}

CompositeShape::CompositeShape(const CompositeShape & rhs):
  CompositeShape(rhs.capacity_)
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

bool CompositeShape::empty()
{
  return size_ == 0;
}

size_t CompositeShape::size()
{
  return size_;
}

CompositeShape::CompositeShape(size_t capacity):
 size_(0),
 capacity_(capacity),
 shape_(new Shape*[capacity_])
{}

void CompositeShape::deleteshape_(Shape **shape, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shape[i];
  }
  delete[] shape;
}

CompositeShape & CompositeShape::operator=(const CompositeShape & rhs)
{
  Shape ** new_data = new Shape*[rhs.capacity_];
  size_t new_size = 0;
  try
  {
    for (size_t i = 0; i < rhs.size_; ++i)
    {
      new_data[i] = rhs.shape_[i]->clone();
      new_size++;
    }
  }
  catch (...)
  {
    deleteshape_(new_data, new_size);
    throw;
  }
  deleteshape_(shape_, size_);
  shape_ = new_data;
  size_ = new_size;
  capacity_ = rhs.capacity_;
  return *this;
}
CompositeShape & CompositeShape::operator=(CompositeShape && rhs)
{
  deleteshape_(shape_, size_);
  shape_ = rhs.shape_;
  rhs.shape_ = nullptr;
  size_ = rhs.size_;
  rhs.size_ = 0;
  capacity_ = rhs.capacity_;
  return *this;
}

CompositeShape::~CompositeShape()
{
  deleteshape_(shape_, size_);
}

Shape * CompositeShape::operator[](size_t i)
{
  return shape_[i];
}

const Shape * CompositeShape::operator[](size_t i) const
{
  return shape_[i];
}

double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shape_[i]->getArea();
  }
  return area;
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
  for (size_t i = 1; i < size_; i++)
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

void CompositeShape::scale(double k)
{
  rectangle_t frame = CompositeShape::getFrameRect();
  scale(frame.pos, k);
}


Shape* CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shape_[id];
}

const Shape* CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shape_[id];
}


size_t CompositeShape::size() const
{
  return size_;
}

void CompositeShape::push_back(const Shape * shp)
{
  Shape * cloned = shp->clone();
  if (capacity_ == size_)
  {
    Shape ** new_shape = nullptr;
    try
    {
      new_shape = new Shape * [capacity_ + 10];
    }
    catch (...)
    {
      delete cloned;
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
  shape_[size_++] = cloned;
}

void CompositeShape::push_back(Shape * shp)
{
  if (capacity_ == size_)
  {
    Shape ** new_shape = new Shape * [capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
  shape_[size_++] = shp;
}

void CompositeShape::pop_back()
{
  delete shape_[size_ - 1];
  size_--;
}
