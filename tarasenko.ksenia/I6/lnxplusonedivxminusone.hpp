#ifndef LNXPLUSONEDIVXMINUSONE_HPP
#define LNXPLUSONEDIVXMINUSONE_HPP
#include <cstddef>

class LnXPlusOneDivXMinusOne
{
  public:
   explicit LnXPlusOneDivXMinusOne(double x);
   double operator()();
  private:
   double x_;
   double member_;
   size_t number_;
}

#endif
