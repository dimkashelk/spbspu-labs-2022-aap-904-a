#include <iostream>
#include "scanStr.h"
#include "isFloat.h"
int main()
{
  size_t c = 0;
  char *arr = scanStr(c, std::cin);
  std::cout << std::boolalpha << real(arr, c) << "\n";
  delete[] arr;
  return 0;
}
