#include <iostream>
#include "inputStr.h"
#include "removeAlphabet.h"
#include "addNumbersFromSecondToFirst.h"
int main()
{
  char *str = nullptr;
  size_t size = 0;
  try
  {
    str = inputStr(std::cin, size);
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  const char *str2 = "1111";
  if (str[0] == '\0')
  {
    std::cout << "Empty string" << "\n";
    return 1;
  }
  else
  {
    for (char *p = str; *p != '\0'; p++)
    {
      size++;
    }
    size++;
  }
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
    return 1;
  }
  char *outstring2 = new char[size];
  try
  {
    addNumbers(outstring2, str, str2);
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
    return 1;
  }
  delete [] str;
}

