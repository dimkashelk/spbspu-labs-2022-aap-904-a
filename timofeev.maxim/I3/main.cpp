#include <iostream>
#include "increaseLineSize.h"
#include "removeAlphabet.h"
#include "mergingString.h"
int main()
{
  char *str = nullptr;
  size_t size = 0;
  try
  {
    str = str_input(std::cin, size);
  }
  catch (const std::runtime_error & e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }

  const size_t size2 = 5;
  char *str2 = new char[size2];
  for (size_t i = 0; i < size2 - 1; ++i)
  {
    str2[i] = '1';
  }
  str2[size2 - 1] = '\0';
  for (auto p = str; *p != '\0'; p++)
  {
    size++;
  }
  size++;
  char *outstring1 = new char[size];
  try
  {
    removeAlphabet(outstring1, str);
    if (outstring1[0] != '\0')
    {
      std::cout << outstring1 << "\n";
      delete [] outstring1;
    }
    else
    {
      std::cerr << "Error" << "\n";
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete [] str;
    delete [] str2;
    return 1;
  }

  char *outstring2 = new char[size];
  try
  {
    mergingStr(outstring2, str, str2);
    if (outstring2[0] != '\0')
    {
      std::cout << outstring2 << "\n";
      delete [] outstring2;
    }
    else
    {
      std::cerr << "Error" << "\n";
    }
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete [] str;
    delete [] str2;
    return 1;
  }
  delete [] str;
  delete [] str2;
}

