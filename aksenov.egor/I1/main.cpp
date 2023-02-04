#include <iostream>
#include "notZero.h"
#include "isMore.h"
int main()
{
  int value = 0;
  int predv = 0;
  int compare_count = 0;
  int minv = 0;
  int min_count = 0;
  do
  {
    predv = value;
    std::cin >> value;
    if (std::cin)
    {
      if (isMore(predv, value))
      {
        compare_count++;
      }
      if (std::cin && notZero(value) && minv != 0)
      {
        minv = std::min(minv, value);
      }
      else
      {
        minv = value;
      }
    }
    if (minv == value)
    {
      min_count++;
    }
  }
  while (value && std::cin);
  if (!std::cin)
  {
    std::cout << "Error\n";
  }
  std::cout << "compare count:" << compare_count - 1;
  std::cout << "\nmin count:" << min_count - 1;
}
