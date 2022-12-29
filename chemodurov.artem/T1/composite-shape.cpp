#include "composite-shape.hpp"
#include "iso-scale.hpp"

chemodurov::CompositeShape::CompositeShape():
 shape_(new chemodurov::Shape*[1]),
 size_(0),
 capacity_(1)
{}
chemodurov::CompositeShape::CompositeShape(chemodurov::Shape ** shape, size_t size, size_t capacity):
 shape_(shape),
 size_(size),
 capacity_(capacity)
{}
chemodurov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete shape_[i];
  }
  delete [] shape_;
}
double chemodurov::CompositeShape::getArea() const
{
  double summ_area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    summ_area += shape_[i]->getArea();
  }
  return summ_area;
}
chemodurov::rectangle_t chemodurov::CompositeShape::getFrameRect() const
{
  chemodurov::rectangle_t temp = shape_[0]->getFrameRect();
  double max_x = temp.pos.x + 0.5 * temp.width;
  double min_x = max_x;
  double max_y = temp.pos.y + 0.5 * temp.height;
  double min_y = max_y;
  for (size_t i = 0; i < size_; ++i)
  {
    chemodurov::rectangle_t temp1 = shape_[i]->getFrameRect();
    if (max_x < temp1.pos.x + 0.5 * temp1.width)
    {
      max_x = temp1.pos.x + 0.5 * temp1.width;
    }
    if (min_x > temp1.pos.x - 0.5 * temp1.width)
    {
      min_x = temp1.pos.x - 0.5 * temp1.width;
    }
    if (max_y < temp1.pos.y + 0.5 * temp1.height)
    {
      max_y = temp1.pos.y + 0.5 * temp1.height;
    }
    if (min_y > temp1.pos.y - 0.5 * temp1.height)
    {
      min_y = temp1.pos.y - 0.5 * temp1.height;
    }
  }
  chemodurov::point_t center{(max_x + min_x) / 2, (max_y + min_y) / 2};
  chemodurov::rectangle_t frame{center, max_x - min_x, max_y - min_y};
  return frame;
}
void chemodurov::CompositeShape::move(const chemodurov::point_t & position)
{
  chemodurov::rectangle_t frame = chemodurov::CompositeShape::getFrameRect();
  double dx = position.x - frame.pos.x;
  double dy = position.y - frame.pos.y;
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}
void chemodurov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}
void chemodurov::CompositeShape::scale(double k)
{
  chemodurov::rectangle_t frame = chemodurov::CompositeShape::getFrameRect();
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], frame.pos, k);
  }
}
void chemodurov::CompositeShape::scale(const chemodurov::point_t & position, double k)
{
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], position, k);
  }
}
chemodurov::Shape * chemodurov::CompositeShape::operator[](size_t id)
{
  return shape_[id];
}
const chemodurov::Shape * chemodurov::CompositeShape::operator[](size_t id) const
{
  return shape_[id];
}
chemodurov::Shape * chemodurov::CompositeShape::at(size_t id)
{
  return shape_[id];
}
const chemodurov::Shape * chemodurov::CompositeShape::at(size_t id) const
{
  return shape_[id];
}
bool chemodurov::CompositeShape::empty() const
{
  return size_ == 0;
}
size_t chemodurov::CompositeShape::size() const
{
  return size_;
}
void chemodurov::CompositeShape::push_back(const chemodurov::Shape * shp)
{
  if (capacity_ == size_)
  {
    chemodurov::Shape ** new_shape = new chemodurov::Shape * [capacity_ + 1];
    ++capacity_;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
  *shape_[size_++] = *shp;
}
void chemodurov::CompositeShape::push_back(chemodurov::Shape * shp)
{
  if (capacity_ == size_)
  {
    chemodurov::Shape ** new_shape = new chemodurov::Shape * [capacity_ + 1];
    ++capacity_;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
    shape_[size_++] = shp;
}
void chemodurov::CompositeShape::pop_back()
{
  delete shape_[size_];
  shape_[size_--] = nullptr;
}
