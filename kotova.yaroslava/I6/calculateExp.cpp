#include "calculateExp.hpp"
#include <iomanip>
#include <cmath>
void printRow(std::ostream& out, double x, double absError, unsigned numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << exp(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << std::exp(x * (-1)) << "\n";
}
void printTable(std::ostream& out, double left, double right, double step, double absError, unsigned numberMax)
{
  for (double x = left; x + step <= right; x += step)
  {
    printRow(out, x, absError, numberMax);
  }
  printRow(out, right, absError, numberMax);
}

double exp(double x, double absError, unsigned numberMax)
{
  double result = 0.0;
  double sum = 0.0;
  double members = 0;
  double numerator = x * (-1);
  unsigned factorial = 2;
  unsigned denominator = 1;
  do
  {
    sum = numerator / denominator;
    result += sum;
    members++;
    numerator *= x * (-1);
    denominator *= factorial;
    factorial++;
  } while (members != numberMax || sum > absError);
  return result;
}
