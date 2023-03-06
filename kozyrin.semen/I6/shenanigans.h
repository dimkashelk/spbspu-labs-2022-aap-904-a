#ifndef SHENANIGANS_H
#define SHENANIGANS_H
#include <iostream>
#include <cmath>

struct term1 {
public:
  double operator()();
  double x = 0;
private:
  double value = 1;
  size_t n = 0;
};

struct term2 {
public:
  double operator()();
  double x = 0;
  double value = 0;
private:
  size_t n = 1;
};

double getCustomCos(double x, double error, size_t maxNum);
double getCustomArth(double x, double error, size_t maxNum);

void printTable(std::ostream& stream, double lb, double rb, double error, size_t maxNum, double step);

#endif
