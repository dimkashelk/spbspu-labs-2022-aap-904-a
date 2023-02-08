#include "workWithStrs.h"

char* reallocMem(char* str, const size_t& new_capasity)
{
  char* new_mem_block;

  try
  {
    new_mem_block = new char[new_capasity];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] str;
    std::cerr << "Allocation error: " << e.what() << '\n';
    std::exit(1);
  }

  char* new_char_ptr = new_mem_block;
  for (char* old_char_ptr = str; *old_char_ptr != '\0'; ++old_char_ptr, ++new_char_ptr)
  {
    *new_char_ptr = *old_char_ptr;
  }
  *new_char_ptr = '\0';

  delete[] str;

  return new_mem_block;
}

void pushBack(char*& str, size_t& str_size, size_t& str_capasity, const char& new_char)
{
  if (str_size == str_capasity)
  {
    str_capasity += capasity_block;
    str = reallocMem(str, str_capasity);
  }
  str[str_size++] = new_char;
  str[str_size] = '\0';
}

std::pair<char*, char*> strCopy(const char* str)
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
    pushBack(result, result_size, result_capasity, *str);
    ++str;
  }
  return std::pair<char*, char*>(result, result + result_size);
}
