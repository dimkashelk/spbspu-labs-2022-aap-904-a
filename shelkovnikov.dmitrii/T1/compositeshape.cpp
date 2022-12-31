#include "compositeshape.h"
#include <algorithm>
#include <limits>
#include "vector_t.h"
CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shapes_(new Shape*[capacity_])
{}
CompositeShape::CompositeShape(Shape **shapes, size_t size):
  size_(size),
  capacity_(size_),
  shapes_(new Shape*[capacity_])
{
  shapes_ = new Shape*[capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = shapes[i]->clone();
  }
}
CompositeShape::CompositeShape(const CompositeShape &compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(new Shape*[capacity_])
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = compositeShape.shapes_[i]->clone();
  }
}
CompositeShape::CompositeShape(CompositeShape &&compositeShape):
  size_(compositeShape.size_),
  capacity_(compositeShape.capacity_),
  shapes_(new Shape*[capacity_])
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = compositeShape.shapes_[i];
  }
  delete[] compositeShape.shapes_;
}
CompositeShape &CompositeShape::operator=(const CompositeShape &other)
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  shapes_ = new Shape*[capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i] = other.shapes_[i]->clone();
  }
  return *this;
}
CompositeShape &CompositeShape::operator=(CompositeShape &&tmp)
{
  operator=(tmp);
  for (size_t i = 0; i < size_; i++)
  {
    delete tmp.shapes_[i];
  }
  delete[] tmp.shapes_;
  return *this;
}
Shape *CompositeShape::operator[](size_t id)
{
  return shapes_[id];
}
const Shape *CompositeShape::operator[](size_t id) const
{
  return shapes_[id];
}
CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; i++)
  {
    delete shapes_[i];
  }
  delete[] shapes_;
}
double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}
rectangle_t CompositeShape::getFrameRect() const
{
  rectangle_t rectangle = shapes_[0]->getFrameRect();
  double x_min = rectangle.getLeftDownPoint().x;
  double y_min = rectangle.getLeftDownPoint().y;
  double x_max = rectangle.getRightUpPoint().x;
  double y_max = rectangle.getRightUpPoint().y;
  for (size_t i = 0; i < size_; i++)
  {
    rectangle = shapes_[i]->getFrameRect();
    x_min = std::min(x_min, rectangle.getLeftDownPoint().x);
    y_min = std::min(y_min, rectangle.getLeftDownPoint().y);
    x_max = std::max(x_max, rectangle.getRightUpPoint().x);
    y_max = std::max(y_max, rectangle.getRightUpPoint().y);
  }
  return rectangle_t(point_t(x_min, y_min), point_t(x_max, y_max));
}
void CompositeShape::move(point_t point)
{
  point_t center = getCenter();
  vector_t direction(point, center);
  move(direction.x, direction.y);
}
void CompositeShape::move(double delta_x, double delta_y)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(delta_x, delta_y);
  }
}
void CompositeShape::scale(double k)
{
  point_t center = getCenter();
  for (size_t i = 0; i < size_; i++)
  {
    point_t shape_center = shapes_[i]->getFrameRect().point;
    vector_t direction(shape_center, center);
    direction *= k;
    shapes_[i]->scale(k);
    shapes_[i]->move(direction.x, direction.y);
  }
}
point_t CompositeShape::getCenter() const
{
  return getFrameRect().point;
}
void CompositeShape::push_back(Shape *shp)
{
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  if (size_ == capacity_)
  {
    if (max_size_t == capacity_)
    {
      throw std::overflow_error("Stack overflow");
    }
    if (max_size_t - 10 < capacity_)
    {
      capacity_ = max_size_t;
    }
    else
    {
      capacity_ += 10;
    }
    Shape **new_shapes = new Shape*[capacity_];
    for (size_t i = 0; i < size_; i++)
    {
      new_shapes[i] = shapes_[i];
    }
    delete[] shapes_;
    shapes_ = new_shapes;
  }
  shapes_[size_] = shp->clone();
  size_++;
}
void CompositeShape::pop_back()
{
  if (!empty())
  {
    delete shapes_[size_ - 1];
    size_--;
  }
}
Shape* CompositeShape::at(size_t id)
{
  return shapes_[id];
}
const Shape* CompositeShape::at(size_t id) const
{
  return shapes_[id];
}
bool CompositeShape::empty() const noexcept
{
  return size_ == 0;
}
size_t CompositeShape::size() const noexcept
{
  return size_;
}
std::istream& operator>>(std::istream &in, CompositeShape &compositeShape)
{
  size_t count = 0;
  in >> count;
  std::string line = "";
  std::string name = "";
  compositeShape = CompositeShape();
  for (size_t i = 0; i < count; i++)
  {
    std::getline(in, line);
    std::istringstream stream(line);
    stream >> name;
    if (name == "RECTANGLE")
    {}
    else if (name == "REGULAR")
    {
    }
    else if (name == "POLYGON")
    {
    }
  }
  return in;
}
