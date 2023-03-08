#include "printTable.h"
#include <ostream>
#include <iomanip>
#include <cmath>
#include <cstddef>
#include "countArth.h"

void printTableRow(std::ostream& out, double x, double absError, unsigned members)
{
  out << std::setw(5) << x << ' ';
  out << std::setw(10) << std::setprecision(5) << countArth(x, absError, members) << ' ';
  out << std::setw(10) << std::setprecision(5) << std::atanh(x) << '\n';
}

void printTable(std::ostream& out, double left, double right, size_t members, double absError, double step)
{
  for (double x = left; x + step <= right; x = x + step)
  {
    printTableRow(out << "\n", x, absError, members);
    if (x + step >= right)
    {
      printTableRow(out << "\n", right, absError, members);
    }
  }
}
