#include <iostream>
#include "recursion.h"
#include "extendCString.h"

int main()
{
  size_t capacity = 20;
  char * c_string = new char[capacity];
  c_string[0] = '\0';
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        size_t new_capacity = capacity + 20;
        char * new_string = chemodurov::extendCString(c_string, capacity, new_capacity);
        delete [] c_string;
        c_string = new_string;
        new_string = nullptr;
        capacity = new_capacity;
      }
      catch (const std::exception & e)
      {
        std::cerr << e.what() << "\n";
        delete [] c_string;
        return 1;
      }
    }
    std::cin >> c_string[size];
  }
  while (std::cin && c_string[size] != '\0' && c_string[size++] != '\n');

  if (c_string[0] == '\n' || c_string[0] == '\0')
  {
    std::cerr << "Empty string\n";
    delete [] c_string;
    return 1;
  }
  c_string[size - 1] = '\0';

  std::cout << std::boolalpha << chemodurov::isRealNumber(c_string) << "\n";
  delete [] c_string;
  return 0;
}
