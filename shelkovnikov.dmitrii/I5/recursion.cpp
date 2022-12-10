#include "recursion.h"
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
  if (!number[0] || number[0] == '.' || number[0] == 'E')
  {
    return true;
  }
  return is_digit(number[0]) && is_unsigned_integer(number + 1);
}
bool mantissa(const char *number, const bool contains_point, const bool is_prev_point)
{
  if (number[0] == '.')
  {
    if (contains_point)
    {
      return false;
    }
    return mantissa(number + 1, true, true);
  }
  else if (number[0] == 'E')
  {
    if (is_prev_point)
    {
      return false;
    }
    return true;
  }
  else
  {
    return is_digit(number[0]) && mantissa(number + 1, contains_point, false);
  }
}
bool is_real_number(const char *number)
{
  return is_sign(number[0]) && mantissa(number + 1, false, false);
}
