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
size_t index_point(char *number, size_t start, size_t end)
{
  if (start == end)
  {
    return start;
  }
  if (number[start] == '.')
  {
    return start;
  }
  return index_point(number, ++start, end);
}
size_t count_point(char *number, size_t start, size_t end)
{
  if (start == end)
  {
    return start;
  }
  if (number[start] == '.')
  {
    return 1 + index_point(number, ++start, end);;
  }
  return index_point(number, ++start, end);
}
bool mantissa(char *number, size_t start, size_t end)
{
  size_t count_of_point = count_point(number, start, end);
  if (count_of_point > 1)
  {
    return false;
  }
  if (count_of_point == 0)
  {
    return is_unsigned_integer(number, start, end);
  }
  size_t index_of_point = index_point(number, start, end);
  return is_unsigned_integer(number, start, index_of_point) && is_unsigned_integer(number, index_of_point + 1, end);
}
bool is_real_number(char *number, size_t size)
{
}
