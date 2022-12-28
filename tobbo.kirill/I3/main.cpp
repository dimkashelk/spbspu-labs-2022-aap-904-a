#include <iostream>
#include <limits>
#include "cstrfnc.h"

void remove_latin_vowel_helper(const char* str)
{
  size_t size = strLength(str);
  char* destination = new char[size + 1];
  char* res = removeLatinVowelSymbols(destination, str);
  std::cout << str << " => " << res << "\n";
  delete[] destination;
}

int main()
{
  int rc = 0;
  char* str1 = nullptr, * str2 = nullptr;
  try
  {
    std::cout << "Enter string#1: ";
    str1 = getCString(std::cin);
    std::cout << "Enter string#2: ";
    str2 = getCString(std::cin);

    bool res = isIntersectedStrings(str1, str2);
    std::cout << "There is " << (res ? "" : "NO") << " intersect symbols\n";

    remove_latin_vowel_helper(str1);
    remove_latin_vowel_helper(str2);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    rc = 1;
  }
  if (str1)
  {
    delete[] str1;
  }
  if (str2)
  {
    delete[] str2;
  }
  return rc;
}
