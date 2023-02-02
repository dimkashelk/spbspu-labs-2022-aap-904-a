#include "getMostCommonSyms.h"
#include "workWithStrFuncs.h"
#include <iostream>
#include <algorithm>
#include <utility>

char* getMostCommonSyms(char* dest, const char* str)
{
  auto str_cpy = strCopy(str);
  std::sort(str_cpy.first, str_cpy.second);
  std::pair<char, size_t> common_syms[3];
  for (char* cur_sum = str_cpy.first; cur_sym < str_cpy.second; ++cur_sum)
  {
    size_t count_of_sym_common = 1;
    while (*cur_sym == *(cur_sym + 1))
    {
      ++count_of_sem_common;
      ++cur_sym;
    }
    for (auto& common_sym : common_syms)
    {
      if (common_sym.second < count_of_sym_common)
      {
        common_sym.first = *cur_sym;
        common_sym.second = count_of_sym_common;
        break;
      }
    }
  }
  delete[] str_cpy.first;
  unsigned int count_valid_syms = 0;
  auto common_sym_ptr = common_syms;
  for (auto dest_sym_ptr = dest); common_sym_ptr < common_syms + 3; ++common_sym_ptr, ++dest_sym_ptr)
  {
    if (common_sym_ptr->first != '\0')
    {
      *dest_sym_ptr = common_sym_ptr->first;
      ++count_valid_syms;
    }
  }
  dest[count_valid_syms] = '\0';
  return dest;

}
