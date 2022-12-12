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
      catch (const std::exception& e)
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
    std::cout << "Error while reading the string\n";
    delete [] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }

  char* destination = nullptr;
  char* string_source = nullptr;
  const size_t size_source = size;

  try
  {
    string_source = new char[size_source];
    for (size_t i = 0; i < size_source - 1; i++)
    {
      string_source[i] = '1';
    }
    string_source[size_source - 1] = '\0';
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] string_source;
    delete[] cstring;
    return 1;
  }

  try
  {
    destination = new char[size_source + size];
    destination = addDecimalDigits(destination, cstring, string_source);
    if (destination[0] != '\0')
    {
      std::cout << destination << "\n";
    }
    else std::cout << "Error while making first function \n";
    delete[] destination;
    destination = nullptr;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] destination;
    delete[] cstring;
    return 1;
  }

  try
  {
    destination = new char[size_source + size];
    destination = makeStringCommonSymbols(destination, cstring, string_source);
    if (destination[0] != '\0')
    {
      std::cout << destination << "\n";
    }
    else std::cout << "There are no common symbols \n";
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << e.what() << "\n";
    delete[] destination;
    delete[] cstring;
    return 1;
  }

  delete[] destination;
  delete[] string_source;
  delete[] cstring;
}
