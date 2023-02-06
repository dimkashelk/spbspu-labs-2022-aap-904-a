#include <iostream>
#include <exception>
#include <cstring>
#include "finder_three_same_elements.h"
#include "finder_same_elements_in_two_string.h"
#include "array_expansion.h"

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  size_t size_of_static = 18;
  const char* static_string = "ABCDFEabcdef135790";
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      try
      {
        char* new_str = nullptr;
        cstring[size] = '\0';
        new_str = arrayExpansion(cstring, capacity);
        delete[] cstring;
        cstring = new_str;
        capacity += 20;
      }
      catch (const std::bad_alloc &e)
      {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\n')
  {
    delete[] cstring;
    std::cerr << "Empty string!" << "\n";
    return 2;
  }
  if (cstring[size - 1] == '\n')
  {
    cstring[size - 1] = '\0';
  }

  char* destination = nullptr;

  try
  {
    destination = new char[size + size_of_static];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring;
    delete[] destination;
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::cout << finderThreeSameElementsInTwoStrings(destination, cstring, static_string) << "\n";

  char* destination2 = nullptr;

  try
  {
    destination2 = new char[size];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::cout << finderThreeSameElements(destination2, cstring) << "\n";

  delete[] cstring;
  delete[] destination;
  delete[] destination2;
  return 0;
}
