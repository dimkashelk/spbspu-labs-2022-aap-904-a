#include <iostream>
#include "recursion.h"

int main()
{
  std::cout << std::boolalpha << chemodurov::isRealNumber("+100.9E3") << "\n";
  std::cout << std::boolalpha << chemodurov::isRealNumber("+.9E-3") << "\n";
  std::cout << std::boolalpha << chemodurov::isRealNumber("100.9E+3") << "\n";
  std::cout << std::boolalpha << chemodurov::isRealNumber("+100.9E-3") << "\n";
  std::cout << std::boolalpha << chemodurov::isRealNumber("+.8E3") << "\n";
  std::cout << std::boolalpha << chemodurov::isRealNumber("+8E3") << "\n";
  std::cout << std::boolalpha << chemodurov::isRealNumber("+3.E3") << "\n";
  return 0;
}
