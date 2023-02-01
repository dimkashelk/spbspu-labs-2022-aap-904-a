#include "workWithStrFuncs.h"
#include <iostream>
#include <cstddef>
#include <exception>

char* reallocMem(char* str, const size_t& size, const size_t& new_capasity)
{

}

void pushBack(char*& str, size_t& str_size, size_t& str_capasity, const char& new_char)
{
  if (str_size == str_capasity)
  {
    str_capasity += capasity_block;
    str = reallocMem(str, str_size, str_capasity);
  }
  str[str_size++] = new_char;
  str[str_size] = '\0';
}

strCopy(const char* str)
{
  char* result;
  try
  {
    result = new char[capasity_block];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }
  size_t result_size = 0;
  size_t result_capasity = capasity_block;

  while (*str != '\0')
  {
    pushBack()
  }
}
