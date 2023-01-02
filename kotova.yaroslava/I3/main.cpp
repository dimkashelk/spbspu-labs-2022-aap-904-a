#include <iostream>
#include <stdexcept>
#include "DelNumbers.h"
#include "RepLetters.h"
#include "FormingCstring.h"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  char* cstring = nullptr;
  try
  {
    cstring = new char[capacity];
  }
  catch (const std::exception& e)
  {
    delete[] cstring;
    std::cout << e.what();
    return 3;
  }
  cstring[0] = '\0';

  try
  {
    cstring = formingCstring(size, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    delete[] cstring;
    return 2;
  }

  char* destination1 = nullptr;
  try
  {
    destination1 = new char[capacity];
  }
  catch (const std::exception& e)
  {
    delete[] destination1;
    delete[] cstring;
    std::cout << e.what();
    return 1;
  }
  destination1 = deleteNumbers(destination1, cstring);
  std::cout << destination1 << "\n";

  char* destination2 = nullptr;
  try
  {
    destination2 = new char[capacity];
  }
  catch (const std::exception& e)
  {
    delete[] cstring;
    delete[] destination1;
    delete[] destination2;
    std::cout << e.what();
    return 1;
  }
  destination2 = replacingLetters(cstring, destination2);
  std::cout << destination2 << "\n";
  delete[] cstring;
  delete[] destination1;
  delete[] destination2;
}
