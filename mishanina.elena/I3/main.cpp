#include <iostream>
#include "inputString.h"
#include "removeExtraSpaces.h"
#include "hasItTheSameSimbols.h"

int main()
{
  size_t capacity1 = 10;
  size_t newsize1 = 0;
  char* cstring1 = new char[capacity1];
  cstring1[0] = '\0';
  try
  {
    cstring1 = inputString(newsize1, capacity1, std::cin);
    if (newsize1 == 1) {
      std::cerr << "ERROR: Empty string\n";
      delete[] cstring1;
      return 1;
    }
    cstring1[newsize1 - 1] = '\0';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring1;
    return 1;
  }

  char* destination = nullptr;
  try
  {
    destination = new char[capacity1];
    destination[0] = '\0';
    destination = removeExtraSpaces(destination, cstring1);
    std::cout << destination << "\n";
    delete[] destination;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] destination;
    delete[] cstring1;
    return 1;
  }

  size_t capacity2 = 10;
  size_t newsize2 = 0;
  char* cstring2 = new char[capacity2];
  cstring2[0] = '\0';
  try
  {
    cstring2 = inputString(newsize2, capacity2, std::cin);
    if (newsize2 == 1) {
      std::cerr << "ERROR: Empty string\n";
      delete[] cstring1;
      delete[] cstring2;
      return 1;
    }
    cstring2[newsize2 - 1] = '\0';
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring1;
    delete[] cstring2;
    return 1;
  }
  bool result = false;
  try
  {
    result = hasItTheSameSimbols(cstring1, cstring2);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    delete[] cstring1;
    delete[] cstring2;
    return 1;
  }
  if (result)
  {
    std::cout << "Strings have the same simbols" << "\n";
  }
  else
  {
    std::cout << "Strings don't have the same simbols" << "\n";
  }
  delete[] cstring1;
  delete[] cstring2;
  return 0;
}
