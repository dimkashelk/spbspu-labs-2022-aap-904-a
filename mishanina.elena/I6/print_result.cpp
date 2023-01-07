#include "print_result.h"

void printResult(std::ostream& out, double x, unsigned members, double error)
{
  out << std::fixed << std::setw(5) << std::setprecision(2) << x;
  out << std::setw(10) << std::setprecision(5);
  out << std::setw(10) << std::setprecision(5) << 1 / (std::sqrt(1 - x * x)) << '\n';
}
