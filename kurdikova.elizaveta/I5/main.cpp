#include <iostream>
#include <string>
#include "IsItARealNumber.h"
#include "ReadNumber.h"

int main()
{
  char* number = nullptr;
  number = readNumber(number);
  if (number == nullptr)
  {
    delete[] number;
    std::cerr << "Nothing was entered";
    return 1;
  }
  std::cout << std::boolalpha << isRealNumber(number);
  delete[] number;
  return 0;
}
