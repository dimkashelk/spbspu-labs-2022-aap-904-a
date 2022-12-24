#include "lnxplusonedivxminusone.hpp"
#include <cmath>
#include "pow.hpp"

LnXPlusOneDivXMinusOne::LnXPlusOneDivXMinusOne(double x):
  x_(x);
  member_(0.0);
  number_(1.0);
  {
    if (x <= 2 || x >= 3)
    {
      throw std::invalid_argument("x out the interval (2; 3)");
    }
  }

double LnXPlusOneDivXMinusOne::operator()()
{
  member_ = 2 / ((2 * number_ - 1) * pow(x_, 2 * number_ - 1));
  number_++;
  return member_;
}
