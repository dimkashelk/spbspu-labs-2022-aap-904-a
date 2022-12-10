#include "recursion.h"
#include <cstddef>
#include <cctype>
bool is_sign(const char number)
{
  return number == '-' || number == '+';
}
bool is_digit(const char number)
{
  return std::isdigit(number);
}
bool is_unsigned_integer(const char *number)
{
  if (!number[0])
  {
    return true;
  }
  return is_digit(number[0]) && is_unsigned_integer(number + 1);
}

bool is_real_number(const char *number)
{
  return is_unsigned_integer(number)
}
