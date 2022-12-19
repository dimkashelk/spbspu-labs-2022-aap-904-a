#include <iomanip>
#include <cmath>
#include "log.hpp"

void printTableRow(std::ostream & out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << ln(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << std::log((x + 1) / (x - 1)) << "\n";
}

void printTable(std::ostream & out, double leftBorder, double rightBorder, double step, double absError, unsigned numberMax)
{
  for (double i = leftBorder; i <= rightBorder; i += step)
  {
    printTableRow(out, i, absError, numberMax);
  }
}
