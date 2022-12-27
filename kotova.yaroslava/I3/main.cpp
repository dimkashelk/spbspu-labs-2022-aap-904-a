#include <iostream>
#include <cctype>
#include <stdexcept>
#include "DelNumbers.h"
#include "RepLetters.h"
#include "FormingCstring.h"

int main()
{
  size_t capacity = 10;
  char* cstring1 = new char[capacity];
  size_t size = 0;
  cstring1 = formingCstring(cstring1, capacity, size);
  char* destination1 = nullptr;
  try
  {
    destination1 = deleteNumbers(cstring1, destination1);
    std::cout<< destination1 << " ";
  }
  catch(const std::bad_alloc& e)
  {
    std::cout << e.what();
    delete[] destination1;
    delete[]  cstring1;
    return 1;
  }
  char* cstring2 = new char[capacity];
  cstring2 = formingCstring(cstring2, capacity, size);
  cstring2[capacity - 1] = '\0';
  char* destination2 = nullptr;
  try
  {
    destination2 = replacingLetters(cstring2, destination2);
    std::cout << destination2 << " ";
  }
  catch(const std::bad_alloc& e)
  {
    std::cout << e.what();
    delete[] destination2;
    delete[]  cstring2;
    return 1;
  }
  try
  {
    if (cstring1[0] == '\0')
    {
      std::cout << "Empty string";
      delete[] cstring1;
      return 1;
    }
    cstring1[capacity - 1] = '\0';
  }
  catch(invalid_argument& e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] cstring2;
    delete[] destination1;
    delete[] destination2;
    return 1;
  }
  return 0;
}
