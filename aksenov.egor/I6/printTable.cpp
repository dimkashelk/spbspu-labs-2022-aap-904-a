#include "printTable.h"
#include "coshinus.h"
#include <iostream>
#include <iomanip>
#include <cmath>
void printTableRow(std::ostream &out, double x, double absError, size_t numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << calculateCoshinus(x, absError, numberMax) << " ";
  out << std::setw(10) << std::cosh(x) << "\n";
}
void printTable(std::ostream &out, double l, double r, double step, double absError, size_t numberMax)
{
  for (double x = r; x - step >= l; x = x - step)
  {
    printTableRow(out << "\n", x, absError, numberMax);
  }
}
