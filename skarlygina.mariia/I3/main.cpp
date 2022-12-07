#include <iostream>
#include <exception>
#include "cstring_capacity.h"
#include "decimal_digits.h"
#include "string_common_symbols.h"

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        cstring = makeNewCapacityCString(cstring, capacity, size);
      }
      catch (const std::exception & e)
      {
        std::cerr << e.what() << "\n";
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');

  if (!std::cin && !size)
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }

  char* string_source1 = nullptr;
  char* destination1 = nullptr;
  char* destination2 = nullptr;
  const size_t size_source1 = size;

  try
  {
    string_source1 = new char[size_source1];
    for (size_t i = 0; i < size_source1 - 1; i++)
    {
      string_source1[i] = '1';
    }
    string_source1[size_source1 - 1] = '\0';
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] string_source1;
    delete[] cstring;
    return 1;
  }

  try
  {
    destination1 = new char[size_source1 + size];
    destination1 = addDecimalDigits(destination1, cstring, string_source1);
    if (destination1[0] != '\0')
    {
      std::cout << destination1 << "\n";
    }
    else std::cout << "Error while making first function \n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] destination1;
    delete[] cstring;
    return 1;
  }

  try
  {
    destination2 = new char[size_source1 + size];
    destination2 = makeStringCommonSymbols(destination2, cstring, string_source1);
    if (destination2[0] != '\0')
    {
      std::cout << destination2 << "\n";
    }
    else std::cout << "There are no common symbols \n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] destination2;
    delete[] cstring;
    return 1;
  }

  delete[] destination1;
  delete[] destination2;
  delete[] string_source1;
  delete[] cstring;
}
