#include "recursion.h"
#include <cstddef>
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
bool order(char *number, size_t start, size_t end)
{
  if (start >= end - 1)
  {
    return false;
  }
  return number[start] == 'E' && ((is_sign(number[start + 1]) && is_unsigned_integer(number, start + 2, end))
    || is_unsigned_integer(number, start + 1, end));
}
size_t index_E(char *number, size_t start, size_t end)
{
  if (start == end)
  {
    return start;
  }
  if (number[start] == 'E')
  {
    return start;
  }
  return index_E(number, ++start, end);
}
bool is_real_number(char *number, size_t size)
{
  size_t index_of_E = index_E(number, 0, size);
  if (index_of_E == size)
  {
    return false;
  }
  return is_sign(number[0]) && mantissa(number, 1, index_of_E) && order(number, index_of_E, size);
}
