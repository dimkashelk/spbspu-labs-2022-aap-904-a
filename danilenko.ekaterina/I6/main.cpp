#include <iostream>
#include "printTable.h"

int main()
{
  double left = 0.0;
  double right = 0.0;
  size_t numberMax = 0;
  const double absError = 0.00000001;//??????
  const double k = 0.1;

  std::cout << "Enter left and right border: ";
  std::cin >> left >> right;
  if (!std::cin)
  {
    std::cerr << "\nError!\n";
    return 1;
  }
  if (left >= right)
  {
    std::cerr << "\nError! Incorrect interval\n";
    return 1;
  }
  std::cout << "Enter the maximum number of variables: ";
  std::cin >> numberMax;
  if (!std::cin)
  {
    std::cerr << "\nError!\n";
    return 1;
  }
  try
  {
    printTable(std::cout, left, right, numberMax, absError, k);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  return 0;
}
