#include <iostream>
#include <exception>
#include <cstring>
#include "finder.three.same.elements.h"
#include "finder_same_elements_in_two_string.h"
#include "array.expansion.h"

int main()
{
  size_t capacity = 10;
  char* cstring = new char[capacity];
  size_t size = 0;
  size_t size_of_static = 18;
  size_t max_size_t;
  const char* static_string = "ABCDFEabcdef135790";
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        if (capacity != max_size_t - 1)
        {
          capacity += 20;
          *cstring = arrayExpansion(cstring, capacity);
        }
        else
        {
          std::cout << "ERROR\n";
        }
      }
      catch (const std::bad_alloc &e)
      {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size == 0)
  {
    std::cout << "Empty string!" << "\n";
  }
  cstring[0] = '\0';
  try
  {
    char* destination = new char[size + size_of_static];
    std::cout << finderThreeSameElementsInTwoStrings(destination, cstring, static_string) << "\n";
    delete [] cstring;
    delete [] destination;
  }
  catch (const std::bad_alloc &e)
  {
    delete [] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }

  try
  {
    char* destination = new char[size];
    std::cout << finderThreeSameElements(destination, cstring) << "\n";
    delete [] cstring;
    delete [] destination;
  }
  catch (const std::bad_alloc &e)
  {
    delete [] cstring;
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
