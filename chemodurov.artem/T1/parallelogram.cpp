#include "parallelogram.hpp"
#include <stdexcept>

namespace chemodurov
{
  chemodurov::point_t * makeArray(const chemodurov::point_t & fst, const point_t & sec, const point_t & trd)
  {
    const size_t x = 4;
    chemodurov::point_t * arr = new chemodurov::point_t[x];
    arr[0] = fst;
    arr[1] = sec;
    arr[2] = trd;
    arr[3] = {fst.x - sec.x + trd.x, fst.y - sec.y + trd.y};
    return arr;
  }
}

chemodurov::Parallelogram::Parallelogram(const chemodurov::point_t & fst, const point_t & sec, const point_t & trd):
 p(chemodurov::makeArray(fst, sec, trd), 4ull)
{
  if (fst.y != sec.y && sec.y != trd.y)
  {
    throw std::invalid_argument("Not correct parameters");
  }
}
chemodurov::Parallelogram::~Parallelogram()
{}
double chemodurov::Parallelogram::getArea() const
{
  return p.getArea();
}
chemodurov::rectangle_t chemodurov::Parallelogram::getFrameRect() const
{
  return p.getFrameRect();
}
void chemodurov::Parallelogram::move(const chemodurov::point_t & pos)
{
  p.move(pos);
}
void chemodurov::Parallelogram::move(double dx, double dy)
{
  p.move(dx, dy);
}
void chemodurov::Parallelogram::scale(double k)
{
  p.scale(k);
}
chemodurov::Shape * chemodurov::Parallelogram::clone() const
{
  return p.clone();
}
