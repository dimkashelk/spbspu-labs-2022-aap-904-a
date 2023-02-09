#include <iostream>
#include <exception>
#include <cstring>
#include "finder_three_same_elements.h"
#include "finder_same_elements_in_two_string.h"
#include "string_expansion.h"

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
        cstring[size] = '\0';
        capacity += 20;
        char* str = new char[capacity];
        std::strcpy(str, cstring);
        cstring = stringExpansion(str, capacity);
        delete[] str;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\n' || cstring[0] == '\0')
  {
    delete[] cstring;
    std::cerr << "Empty string!" << "\n";
    return 2;
  }
  cstring[size - 1] = '\0';
  try
  {
    char* destination = new char[size + size_of_static];
    destination[0] = '\0';
    destination = finderThreeSameElementsInTwoStrings(destination, cstring, static_string);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  try
  {
    char* destination = new char[size];
    destination[0] = '\0';
    destination = finderThreeSameElements(destination, cstring);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }

  delete[] cstring;
  return 0;
}
