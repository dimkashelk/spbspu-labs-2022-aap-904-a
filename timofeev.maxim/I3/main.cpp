#include <iostream>
#include "increaseLineSize.h"
#include "ZeroAlphabetString.h"
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
  char *str2 = nullptr;
  try
  {
    str2 = str_input(std::cin, size);
  }
  catch (const std::runtime_error & e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
  char *outstring1 = new char[size];
  char *outstring2 = new char[size];
  try
  {
    remove_alphabet(outstring1, str);
    remove_alphabet(outstring2, str2);
    std::cout << outstring1 << "\n";
    std::cout << outstring2 << "\n";
    delete [] outstring1;
    delete [] outstring2;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what();
    delete [] str;
    delete [] str2;
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
}

