#include <iostream>
#include <cctype>
#include <exception>
#include "DelNumbers.h"
#include "RepLetters.h"
#include "FormingCstring.h"

int main()
{
  size_t capacity1 = 10;
  size_t capacity2 = 10;
  size_t size = 0;

  char* cstring1 = new char[capacity1];
  cstring1[0] = '\0';

  try
  {
    cstring1 = formingCstring(cstring1, capacity1, size);
    if (cstring1[0] == '\0')
    {
      std::cout << " Empty string ";
      delete[] cstring1;
      return 2;
    }
    cstring1[size-1] = '\0';
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    return 1;
  }

  char* destination1 = nullptr;
  try
  {
    destination1 = new char[capacity1];
  }
  catch(const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] destination1;
    return 1;
  }
  try
  {
    destination1 = deleteNumbers(destination1, cstring1);
  }
  catch(const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] destination1;
    return 1;
  }
  std::cout << destination1 << "\n";

  char* destination2 = nullptr;
  try
  {
    destination2 = new char[capacity2];
  }
  catch(const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] destination1;
    delete[] destination2;
    return 1;
  }
  try
  {
    destination2 = replacingLetters(cstring1, destination2);
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] destination1;
    delete[] destination2;
    return 1;
  }
  std::cout << destination2 << "\n";
  delete[] cstring1;
  delete[] destination2;
}
