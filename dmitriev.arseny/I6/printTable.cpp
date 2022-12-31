#include "printTable.h"
#include "defineArcSin.h"
#include <iomanip>

void printRowInTable(std::ostream& out, double x, double absError, unsigned numberMax)
{
  double result = 0.0;
  try
  {
    result = defineArcSin(x, absError, numberMax);
  }
  catch (const std::exception& e)
  {
    throw;
  }

  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << result << " ";
  out << std::setw(10) << std::setprecision(5) << std::asin(x) << "\n";
}

void printTable(std::ostream& out, double leftBorder, double rightBorder, double step, unsigned numberMax, double absError)
{
  for (double x = leftBorder; x + step < rightBorder; x = x + step)
  {
    try
    {
      printRowInTable(out << "\n", x, absError, numberMax);
    }
    catch (const std::exception& e)
    {
      throw;
    }
  }
  try
  {
    printRowInTable(out << "\n", rightBorder, absError, numberMax);
  }
  catch (const std::exception& e)
  {
    throw;
  }
}
