#ifndef SHENANIGANS_H
#define SHENANIGANS_H
#include <iostream>

struct term {
  double x;
  double value = 1;
  size_t n = 0;
  double operator()();
};

double customCos(double x, double error, double maxNum);

#endif
