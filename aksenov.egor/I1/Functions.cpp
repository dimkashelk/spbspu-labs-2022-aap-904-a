#include <iostream>
#include "Functions.h"
bool notZero(int numb)
{
  return numb != 0;
};
bool isMore(int dad, int son)
{
  return dad < son;
};
void out(int count, int sum, int compare_count, int min_count)
{
  std::cout << "Count: " << count;
  std::cout << "\nSum: " << sum;
  std::cout << "\nCOmpare count: " << compare_count - 1;
  std::cout << "\nMin count" << min_count;
}


