#include "printTable.h"
#include <iomanip>
#include <cmath>
#include "findExp.h"

void printRow(std::ostream& out, double x, double absError, unsigned int numberMax)
{
  out << std::setw(10) << std::fixed << std::setprecision(5) << x << " ";
  out << std::setw(15) << std::scientific << std::setprecision(5)
      << exp(x, absError, numberMax) << " "
      << std::exp(x * (-1)) << "\n";
}

void printTable(std::ostream& out, double left, double right, double step, double absError, unsigned int numberMax)
{
  out << std::setw(10) << std::left << "x" << " ";
  out << std::setw(15) << std::left << "exp(x)" << " ";
  out << std::setw(15) << std::left << "exp(-x)" << "\n";
  for (double x = left; x <= right; x += step)
  {
    printRow(out, x, absError, numberMax);
  }
}
