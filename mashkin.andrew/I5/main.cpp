#include "createCString.h"
#include <iostream>

int main()
{
  char* string = nullptr;
  size_t capacity = 10;
  size_t size = 0;
  size_t endIndex = 0;
  try
  {
    string = createCString(std::cin, size, capacity);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string;
    return 1;
  }
  return 0;
}