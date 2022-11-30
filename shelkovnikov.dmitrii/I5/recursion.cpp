#include "recursion.h"
bool sign(char number);
bool mantissa(char *number, size_t ind);
bool order(char *number);
bool is_digit(char digit);
size_t index_E(char *number, size_t ind);
size_t index_point(char *number, size_t ind);
bool unsigned_integer(char *number, size_t start, size_t ind);
bool is_real_number(char *number, size_t size)
{
  if (size == 0)
  {
    return false;
  }
  size_t ind = index_E(number, 0);
  if (ind == size)
  {
    return false;
  }
  return sign(number[0]) && mantissa(number, ind) && order(number);
}
bool sign(char number)
{
  return number[0] == '+' || number[0] == '-';
}
bool mantissa(char *number, size_t ind)
{
  bool res = true;
  size_t count_point = 0;
  size_t index_point = index_point(number, 0);
  return res;
}
bool is_digit(char number)
{
  return number >= '0' && number <= '9';
}
bool order(char *number)
{
  bool res = true;
  bool contains_E = false;
  for (size_t i = 0; number[i]; i++)
  {
    if (number[i] == 'E')
    {
      contains_E = true;
    }
    if (contains_E)
    {

    }
  }
  return res;
}
size_t index_E(char *number, size_t ind)
{
  if (!number[ind])
  {
    return ind + 1;
  }
  if (number[ind] == 'E')
  {
    return ind;
  }
  return index_E(number, ++ind);
}
size_t index_point(char *number, size_t ind)
{
  if (!number[ind])
  {
    return ind + 1;
  }
  if (number[ind] == '.')
  {
    return ind;
  }
  return index_point(number, ++ind);
}
bool unsigned_integer(char *number, size_t start, size_t ind)
{
  if (start == ind)
  {
    return true;
  }
  return is_digit(number[start]) && unsigned_integer(number, start + 1, ind);
}
