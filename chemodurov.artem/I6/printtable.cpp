#include "printtable.h"
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include "sqrt1minusxsquare.h"

void printRowInTable(std::ostream & out, double x, size_t max_members, double error)
{
  if (std::abs(x) < 1e-9)
  {
    out << std::setw(10) << std::setprecision(4) << 0.0 << ' ';
    out << std::setw(10) << std::setprecision(5) << 1 << ' ';
    out << std::setw(10) << std::setprecision(5) << 1;
  }
  else
  {
    Sqrt1MinusXSquare sqrt1{0, 0};
    double sqrt_in_x = 0.0;
    sqrt_in_x = sqrt1(x, max_members, error);
    out << std::setw(10) << std::setprecision(4) << x << ' ';
    out << std::setw(10) << std::setprecision(5) << sqrt_in_x << ' ';
    out << std::setw(10) << std::setprecision(5) << 1 / (std::sqrt(1 - x * x));
  }
}

void chemodurov::printTable(std::ostream & out, double left, double right, double step, size_t max_mem, double err)
{
  for (double i = left; i + step < right; i += step)
  {
    if (i >= left && i < right)
    {
      printRowInTable(out << "\n", i, max_mem, err);
    }
    else
    {
      throw std::out_of_range("X is out of range");
    }
  }
  printRowInTable(out << "\n", right, max_mem, err);
  out << "\n";
}
