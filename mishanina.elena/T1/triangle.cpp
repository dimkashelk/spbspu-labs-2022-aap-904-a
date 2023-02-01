#include "triangle.h"

Triangle::Triangle(const point_t& A, const point_t& B, const point_t& C)
{
}

std::string Triangle::getName() const
{
  return std::string();
}

double Triangle::getArea() const
{
  return 0.0;
}

rectangle_t Triangle::getFrameRect() const
{
  return rectangle_t{ };
}

void Triangle::move(point_t point)
{
}

void Triangle::scale(double k)
{
}

void Triangle::move(double dx, double dy)
{
}

Shape* Triangle::clone() const
{
  return nullptr;
}
