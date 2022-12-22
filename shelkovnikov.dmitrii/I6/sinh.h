#ifndef SPBSPU_LABS_2022_AAP_904_A_SINH_H
#define SPBSPU_LABS_2022_AAP_904_A_SINH_H
#include <iostream>
struct Sinh
{
  Sinh(double x);
  double operator()();
  double x;
  double error;
  unsigned count;
};
void print_table(std::ostream &out, double left, double right, double step, double error, unsigned k);
#endif
