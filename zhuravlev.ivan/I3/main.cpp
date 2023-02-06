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
    return 1;
  }
  cstring[size - 1] = '\0';
  try
  {
    char* destination = new char[size + size_of_static];
    std::cout << finderThreeSameElementsInTwoStrings(destination, cstring, static_string) << "\n";
    delete[] destination;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  try
  {
    char* destination = new char[size + 1];
    std::cout << finderThreeSameElements(destination, cstring) << "\n";
    delete[] destination;
  }
  catch (const std::bad_alloc &e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  delete[] cstring;
  return 0;
}
