#include "CompositeShape.h"

CompositeShape::CompositeShape()
{
}

CompositeShape::~CompositeShape()
{
}

Shape* CompositeShape::operator[](size_t index)
{
  return nullptr;;
}

const Shape* CompositeShape::operator[](size_t index) const
{
  return nullptr;;
}

std::string CompositeShape::getName() const
{
  return std::string();
}

double CompositeShape::getArea() const
{
  return 0.0;
}

void CompositeShape::push_back(Shape* shape)
{
}

void CompositeShape::pop_back()
{
}

Shape* CompositeShape::at(size_t index)
{
  return nullptr;
}

const Shape* CompositeShape::at(size_t index) const
{
  return nullptr;
}

bool CompositeShape::empty() const
{
  return false;
}

size_t CompositeShape::size() const
{
  return std::size_t();
}

void CompositeShape::remove(Shape** shapes, size_t size) const
{
}

void CompositeShape::move(double dx, double dy)
{
}

void CompositeShape::move(point_t point)
{
}

void CompositeShape::scale(double k)
{
}

rectangle_t CompositeShape::getFrameRect() const
{
  return rectangle_t{ };
}

CompositeShape* CompositeShape::clone() const
{
  return nullptr;
}

CompositeShape::CompositeShape(Shape** shapes, size_t capacity, size_t size)
{
}

CompositeShape::CompositeShape(const CompositeShape& compositeShape)
{
}

CompositeShape::CompositeShape(CompositeShape&& compositeShape) noexcept
{
}

CompositeShape& CompositeShape::operator = (const CompositeShape& compositeShape)
{
  return *this;
}

CompositeShape& CompositeShape::operator = (CompositeShape&& compositeShape) noexcept
{
  return *this;
}
