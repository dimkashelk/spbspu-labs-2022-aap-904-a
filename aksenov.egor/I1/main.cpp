#include <iostream>
#include "Functions.h"
int main()
{
  int count = 0;
  int value = 0;
  int sum = 0;
  int predv = 0;
  int compare_count = 0;
  int minv = 1000000000;
  int min_count = 0;
  do
  {
    predv = value;
    std::cin >> value;
    count += std::cin ? (value ? 1 : 0) : 0;
    sum += std::cin ? value : 0;
    if (std::cin)
    {
      if (isMore(predv, value))
      {
        compare_count++;
      }
      if (std::cin && notZero(value))
      {
        minv = std::min(minv, value);
      }
    }
    if (minv == value)
    {
      min_count++;
    }
  } while (value && std::cin);
  if (!std::cin)
  {
    std::cout << "Error\n";
  }
  out(count, sum, compare_count, min_count);
}
