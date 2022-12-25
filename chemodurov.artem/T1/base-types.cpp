#include "base-types.hpp"

chemodurov::point_t chemodurov::point_t::operator+(const chemodurov::point_t & right) const
{
  chemodurov::point_t temp{this->x + right.x, this->y + right.y};
  return temp;
}

chemodurov::point_t chemodurov::point_t::operator*(double k) const
{
  chemodurov::point_t temp{this->x * k, this->y * k};
  return temp;
}

chemodurov::point_t chemodurov::point_t::operator-(const chemodurov::point_t & right) const
{
  chemodurov::point_t temp{this->x - right.x, this->y - right.y};
  return temp;
}

bool chemodurov::point_t::operator==(const chemodurov::point_t & right) const
{
  return (this->x == right.x && this->y == right.y);
}
