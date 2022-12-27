#include <iostream>
#include <stdexcept>
#include "DelNumbers.h"
#include "RepLetters.h"
#include "FormingCstring.h"

int main()
{
  size_t capacity1 = 10;
  size_t capacity2 = 10;
  size_t size1 = 0;
  size_t size2 = 0;
  char* cstring1 = new char[capacity1];
  cstring1[0] = '\0';

  try
  {
    cstring1 = formingCstring(cstring1, capacity1, size1);
    if (cstring1[0] == '\0')
    {
      std::cout << " Empty string ";
      delete[] cstring1;
      return 2;
    }
    cstring1[size1-1] = '\0';
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    return 1;
  }

  char*  destination1 = new char[capacity1];
  destination1[0] = '\0';
  try
  {
    destination1 = deleteNumbers(destination1, cstring1);
    std::cout << destination1 << "\n";
  }
  catch(const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] destination1;
    return 1;
  }
  char* cstring2 = new char[capacity2];
  cstring2[0] = '\0';
  try
  {
    cstring2 = formingCstring(cstring2, capacity2, size2);
    cstring2[size2-1] = '\0';
  }
  catch(const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] destination1;
    delete[] cstring2;
    return 1;
  }
  char* destination2 = new char[capacity2];
  destination2[0] = '\0';
  try
  {
    destination2 = replacingLetters(cstring2, destination2);
    std::cout << destination2 << "\n";
  }
  catch (const std::exception &e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] cstring2;
    delete[] destination1;
    delete[] destination2;
    return 1;
  }
  delete[] cstring1;
  delete[] cstring2;
  delete[] destination1;
  delete[] destination2;
  return 0;
}
