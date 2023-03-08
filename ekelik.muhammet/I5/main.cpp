#include <iostream>
#include <cstring>
#include <stdexcept>
#include "myString.h"
#include "realNumber.h"

int main()
{
  char* number = nullptr;
  size_t size = 0, capacity = 10;

  try
  {
    number = makeMyString(size, capacity, std::cin);
    if (!RealNumber(number))
    {
      throw std::invalid_argument("Invalid input: not a real number");
    }
    std::cout << std::boolalpha << RealNumber(number) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
  }

  delete[] number;
  return 0;
}
