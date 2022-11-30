#include "recursion.h"
bool is_sign(char number)
{
  return number == '-' || number == '+';
}
bool is_digit(char number)
{
  return number >= '0' && number <= '9';
}
bool is_unsigned_integer(char *number, size_t start, size_t end)
{
  if (start == end)
  {
    return true;
  }
  return is_digit(number[0]) && is_unsigned_integer(number, ++start, end);
}
bool is_real_number(char *number, size_t size)
{
}
