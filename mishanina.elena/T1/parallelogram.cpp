#include "parallelogram.h"
#include <stdexcept>

Parallelogram::Parallelogram(const point_t& A, const point_t& B, const point_t& C) :
  name_("Parallelogram: "),
  lu_point_(A),
  ru_point_(B),
  rd_point_(C)
{
  if (!isCorrectParallelogram(A, B, C))
  {
    throw std::invalid_argument("invalid rectangle\n");
  }
}

std::string Parallelogram::getName() const
{
  return name_;
}

double Parallelogram::getArea() const
{
  double width = ru_point_.x - lu_point_.x;
  double height = ru_point_.y - rd_point_.y;
  return height * width;
}

rectangle_t Parallelogram::getFrameRect() const
{
  double width = (ru_point_.x - lu_point_.x) + (ru_point_.x - rd_point_.x);
  double height = ru_point_.y - rd_point_.y;
  return { width, height, getCenterParallelogram(lu_point_, rd_point_) };
}

void Parallelogram::move(point_t point)
{
  point_t pos = getCenterParallelogram(lu_point_, rd_point_);
  double dx = point.x - pos.x;
  double dy = point.y - pos.y;
  move(dx, dy);
}

void Parallelogram::scale(double k)
{
  point_t pos = getCenterParallelogram(lu_point_, rd_point_);
  lu_point_ = scalePoint(lu_point_, pos, k);
  ru_point_ = scalePoint(ru_point_, pos, k);
  rd_point_ = scalePoint(rd_point_, pos, k);
}

void Parallelogram::move(double dx, double dy)
{
  point_t dpoint{ dx, dy };
  lu_point_ = movePoint(lu_point_, dpoint);
  ru_point_ = movePoint(ru_point_, dpoint);
  rd_point_ = movePoint(rd_point_, dpoint);
}

Shape* Parallelogram::clone() const
{
  return new Parallelogram(lu_point_, ru_point_, rd_point_);
}
