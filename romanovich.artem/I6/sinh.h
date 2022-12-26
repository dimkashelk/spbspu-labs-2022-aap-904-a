#ifndef I6_SINH_H
#define I6_SINH_H
#include <cstddef>
class NextSinhEl
{
public:
  explicit NextSinhEl(double x);
  double operator()();
  size_t numberSummand;
private:
  double x;
};
double countSinh(double x, double absError, size_t numberMax);
#endif
