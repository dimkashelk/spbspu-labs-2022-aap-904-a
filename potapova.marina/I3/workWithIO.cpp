#include "workWithIO.h"

char* stdinGetLine()
{
  char* result = nullptr;
  result = new char[capasity_block];
  size_t result_size = 0;
  size_t result_capasity = capasity_block;
  char cur_char = '\0';
  std::cin >> std::noskipws;
  while (std::cin >> cur_char && cur_char != '\n')
  {
    pushBack(result, result_size, result_capasity, cur_char);
  }

  if (cur_char == '\0')
  {
    delete[] result;

    return nullptr;
  }

  return result;
}
