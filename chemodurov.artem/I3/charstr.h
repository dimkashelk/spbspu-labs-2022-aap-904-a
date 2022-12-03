#ifndef CHARSTR_H
#define CHARSTR_H
#include <cstddef>

namespace chemodurov
{
  char * extendCString(const char * c_string, size_t capacity, size_t new_capacity);
  char * addNumbersToFirst(char * str_result, const char * str_first, const char * str_second);
  bool isRepeatingNumbers(const char * c_string);
  char * deleteVowels(char * str_result, const char * c_string);
}
#endif
