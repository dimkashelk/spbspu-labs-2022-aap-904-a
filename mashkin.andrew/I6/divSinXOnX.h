#ifndef DIVSINXONX_H
#define DIVSINXONX_H
#include <cstddef>

double divSinXOnX(double x, double absError, size_t numberMax);

class NewMemb
{
public:
  explicit NewMemb(double x);
  double operator()();
private:
  double x;
  double powX;
  size_t factorial;
  size_t var;
  short int sign;
};
#endif
