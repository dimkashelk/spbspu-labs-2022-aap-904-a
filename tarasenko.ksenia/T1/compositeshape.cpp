#include "compositeshape.hpp"
#include <stdexcept>
#include "isoscale.hpp"

tarasenko::CompositeShape::CompositeShape():
  size_(0),
  capacity_(5),
  shapes(new Shape * [capacity_])
{}

size_t tarasenko::CompositeShape::size() const
{
  return size_;
}

double tarasenko::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes[i]->getArea();
  }
  return area;
}

tarasenko::rectangle_t tarasenko::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::invalid_argument("CompositeShape is empty");
  }
  rectangle_t frame_rect = shapes[0]->getFrameRect();
  double min_x = frame_rect.pos_.x_ - 0.5 * frame_rect.width_;
  double min_y = frame_rect.pos_.y_ - 0.5 * frame_rect.height_;
  double max_x = frame_rect.pos_.x_ + 0.5 * frame_rect.width_;
  double max_y = frame_rect.pos_.y_ + 0.5 * frame_rect.height_;
  for (size_t i = 1; i < size_; i++)
  {
    frame_rect = shapes[i]->getFrameRect();
    if (min_x > frame_rect.pos_.x_ - 0.5 * frame_rect.width_)
    {
      min_x = frame_rect.pos_.x_ - 0.5 * frame_rect.width_;
    }
    if (min_y > frame_rect.pos_.y_ - 0.5 * frame_rect.height_)
    {
      min_y = frame_rect.pos_.y_ - 0.5 * frame_rect.height_;
    }
    if (max_x < frame_rect.pos_.x_ + 0.5 * frame_rect.width_)
    {
      max_x = frame_rect.pos_.x_ + 0.5 * frame_rect.width_;
    }
    if (max_y < frame_rect.pos_.y_ + 0.5 * frame_rect.height_)
    {
      max_y = frame_rect.pos_.y_ + 0.5 * frame_rect.height_;
    }
  }
  rectangle_t res(point_t(min_x, min_y),point_t(max_x, max_y));
  return res;
}

void tarasenko::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->move(dx, dy);
  }
}

void tarasenko::CompositeShape::move(point_t pos)
{
  point_t center = getFrameRect().pos_;
  move(pos.x_ - center.x_, pos.y_ - center.y_);
}

void tarasenko::CompositeShape::scale(double k)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes[i]->scale(k);
  }
}

void tarasenko::CompositeShape::push_back(Shape * shp)
{
  if (size_ == capacity_)
  {
    Shape ** new_shapes = new Shape * [capacity_ + 5];
    capacity_ += 5;
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes[i];
    }
    delete[] shapes;
    shapes = new_shapes;
  }
  shapes[size_] = shp;
  size_++;
}

void tarasenko::CompositeShape::pop_back()
{
  delete shapes[size_ - 1];
  size_--;
}

tarasenko::Shape * tarasenko::CompositeShape::at(size_t id)
{
  return shapes[id];
}

tarasenko::Shape * tarasenko::CompositeShape::operator[](size_t id)
{
  return shapes[id];
}

bool tarasenko::CompositeShape::empty() const
{
  return (size_ == 0);
}

tarasenko::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes[i];
  }
  delete [] shapes;
}
