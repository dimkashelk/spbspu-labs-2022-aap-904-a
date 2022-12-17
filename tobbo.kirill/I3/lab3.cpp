#include <iostream>
#include <limits>
#include "cstrfnc.h"

void remove_latin_vowel_letters_(const char* str)
{
  size_t size = str_length(str);
  char* destination = new char[size + 1];
  char* res = remove_latin_vowel_letters(destination, str);
  std::cout << str << " => " << res << "\n";
  delete[] destination;
}

int main()
{
  int rc = 0;
  char* str1 = NULL, * str2 = NULL;
  try
  {
    std::cout << "Enter string#1: ";
    str1 = get_cstring(std::cin);
    std::cout << "Enter string#2: ";
    str2 = get_cstring(std::cin);

    bool res = is_intersected_strings(str1, str2);
    std::cout << "There is " << (res ? "" : "NO") << " intersect symbols\n";

    remove_latin_vowel_letters_(str1);
    remove_latin_vowel_letters_(str2);
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
