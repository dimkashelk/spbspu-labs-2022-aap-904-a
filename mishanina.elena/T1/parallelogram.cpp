#include "parallelogram.h"

Parallelogram::Parallelogram(const point_t& A, const point_t& B, const point_t& C)
{
}

std::string Parallelogram::getName() const
{
  return std::string();
}

double Parallelogram::getArea() const
{
  return 0.0;
}

rectangle_t Parallelogram::getFrameRect() const
{
  return rectangle_t{ };
}

void Parallelogram::move(point_t point)
{
}

void Parallelogram::scale(double k)
{
}

void Parallelogram::move(double dx, double dy)
{
}

Shape* Parallelogram::clone() const
{
  return nullptr;
}
