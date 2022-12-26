#ifndef I6_SINH_H
#define I6_SINH_H
#include <stddef.h>
class NextSinhEl
{
public:
  explicit NextSinhEl(double x);
  double operator()();
private:
  double x;
  size_t numberSummand;
  size_t factorial;
  double pow;
};

double countSinh(double x, double absError, size_t numberMax);
#endif
