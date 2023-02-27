#include "getMostCommonSyms.h"

char* getMostCommonSyms(char* dest, const char* str)
{
  size_t counts[127];
  for (size_t& count : counts)
  {
    count = 0;
  }
  std::pair< char, size_t > ans_syms_with_counts[3];
  for (; *str != '\0'; ++str)
  {
    std::pair< char, size_t > cur_elem_with_count(*str, ++counts[static_cast<size_t>(*str)]);
    for (auto& ans_sym_with_count : ans_syms_with_counts)
    {
      if (cur_elem_with_count.first == ans_sym_with_count.first)
      {
        break;
      }
      if (cur_elem_with_count.second > ans_sym_with_count.second)
      {
        std::swap(ans_sym_with_count, cur_elem_with_count);
      }
    }
  }
  const std::pair< char, size_t >* ans_sym_with_count_ptr = ans_syms_with_counts;
  for (char* dest_sym_ptr = dest;
    ans_sym_with_count_ptr < ans_syms_with_counts + 3;
    ++ans_sym_with_count_ptr, ++dest_sym_ptr)
  {
    *dest_sym_ptr = ans_sym_with_count_ptr->first;
  }
  dest[3] = '\0';
  return dest;
}
