#include <iostream>
#include "scanStr.h"
#include "isFloat.h"
int main()
{
  char *arr = scanStr(c, std::cin);
  std::cout << std::boolalpha << real(arr) << "\n";
  delete[] arr;
  return 0;
}
