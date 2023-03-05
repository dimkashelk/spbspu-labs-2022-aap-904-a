#include <iostream>
#include <exception>
#include <cstring>
#include "finder_three_same_elements.h"
#include "finder_same_elements_in_two_string.h"
#include <makeString.h>

int main()
{
  char* cstring = makeCstring(std::cin);
  size_t size = sizeof(cstring);
  size_t size_of_static = 18;
  const char* static_string = "ABCDFEabcdef135790";
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
