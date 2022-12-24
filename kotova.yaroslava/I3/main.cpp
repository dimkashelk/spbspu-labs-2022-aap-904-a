#include <iostream>
#include <cctype>
#include "DelNumbers.h"
#include "RepLetters.h"
#include "FormingCstring.h"

int main()
{
  size_t capacity = 10;
  char * cstring1 = new char[capacity];
  size_t size = 0;
  cstring1 = formingCstring(capacity, cstring1, size);
  if (cstring1[0] == '\0')
  {
    std::cout "Empty string";
    delete[] cstring1;
    return 1;
  }
  cstring1[capacity - 1] = '\0';
  char* destination1 = new char [capacity];
  destination1[0] = '\0';
  try
  {
    destination1 = deleteNumbers(cstring1, destination1);
    std::cout<< destination1 << " ";
    delete[] destination1;
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
    delete[] destination1, cstring1;
    return 1;
  }
  char * cstring2 = new char[capacity]
  cstring2 = formingCstring(capacity, cstring2, size);
  cstring2[capacity - 1] = '\0';
  try
  {
    destination2 = replacingLetters(cstring2, destination2)
    std::cout << destination2 << " ";
    delete[] destination2;
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
    delete[] destination2, cstring2;
    return 1;
  }
  return 0;
}
