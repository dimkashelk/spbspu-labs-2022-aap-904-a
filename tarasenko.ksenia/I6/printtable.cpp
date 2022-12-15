#include <cmath>

void printTable(std::ostream & out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << log(x, absError(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << std::log((x + 1) / (x - 1));
}

void printTableRow(std::ostream & out, double leftBorder, double rightBorder, double step, double absError, unsigned numberMax)
{
  //for
}
