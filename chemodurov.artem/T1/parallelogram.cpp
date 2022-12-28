#include "parallelogram.hpp"

namespace chemodurov
{
  chemodurov::point_t * makeArray(const chemodurov::point_t & fst, const chemodurov::point_t & sec, const chemodurov::point_t trd)
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

chemodurov::Parallelogram::Parallelogram(const chemodurov::point_t & fst, const chemodurov::point_t & sec, const chemodurov::point_t trd)
 p(chemodurov::makeArray(fst, sec, trd), 4ull)
{
  
}
