#include "printTable.h"
#include <ostream>
#include <iomanip>
#include <cmath>
#include <cstddef>
#include "countArth.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned k)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << countArth() << " ";
  out << std::setw(10) << std::setprecision(5) << atanh(x) << '\n';
}

void printTable(std::ostream& out, double left, double right, double numberMax, double absError, unsigned k)
{
  if (left > right)
  {
    throw (std::logic_error("Check the borders"));
  }
  for (double x = left; x + k <= right; x += k)
  {
    printTableRow(out, x, absError, k);
  }
  printTableRow(out, right, absError, k);
}