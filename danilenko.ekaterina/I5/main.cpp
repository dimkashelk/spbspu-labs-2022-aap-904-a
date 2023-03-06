#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <createStringFromInput.h>
#include "isRealNumber.h"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  char* string = nullptr;

  try
  {
    string = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }

  try
  {
    string = createStringFromInput(std::cin, string, size, capacity);
    if (string[0] == '\n')
    {
      std::cout << "Nothing was entered!" << '\n';
      delete[] string;
      return 2;
    }
    string[capacity - 1] = '\0';
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << "\n";
    delete[] string;
    return 1;
  }
  std::cout << std::boolalpha << isRealNumber(string) << '\n';
  delete[] string;
  return 0;
}
