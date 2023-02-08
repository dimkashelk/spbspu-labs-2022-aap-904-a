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
    return 2;
  }
  const size_t size2 = 5;
  char *str2 = new char[size2];
  for (size_t i = 0; i < size2 - 1; ++i)
  {
    str2[i] = '1';
  }
  str2[size2 - 1] = '\0';
  char *outstring1 = new char[size];
  try
  {
    removeAlphabet(outstring1, str);
    std::cout << outstring1 << "\n";
    delete [] outstring1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete [] str;
    return 2;
  }
  char *outstring3 = new char[size];
  try
  {
    mergingStr(outstring3, str, str2);
    std::cout << outstring3 << "\n";
    delete [] outstring3;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete [] str;
    delete [] str2;
    return 2;
  }
  delete [] str;
  delete [] str2;
}

