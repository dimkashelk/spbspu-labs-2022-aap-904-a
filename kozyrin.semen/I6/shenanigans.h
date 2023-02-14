#ifndef SHENANIGANS_H
#define SHENANIGANS_H
#include <iostream>
#include <cmath>

struct term1 {
  double x = 0;
  double value = 1;
  size_t n = 0;
  double operator()();
};

struct term2 {
  double x = 0;
  double value = 0;
  size_t n = 1;
  double operator()();
};

double customCos(double x, double error, size_t maxNum);

void printTable(std::ostream& stream, double lb, double rb, double error, size_t maxNum, double step);

#endif
