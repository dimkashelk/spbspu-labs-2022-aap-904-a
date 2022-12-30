#include "base-types.hpp"

chemodurov::point_t chemodurov::point_t::operator+(const point_t & right) const
{
  point_t temp{x + right.x, y + right.y};
  return temp;
}
chemodurov::point_t chemodurov::point_t::operator*(double k) const
{
  point_t temp{x * k, y * k};
  return temp;
}
chemodurov::point_t chemodurov::point_t::operator-(const point_t & right) const
{
  point_t temp{x - right.x, y - right.y};
  return temp;
}
bool chemodurov::point_t::operator==(const point_t & right) const
{
  return (x == right.x && y == right.y);
}
