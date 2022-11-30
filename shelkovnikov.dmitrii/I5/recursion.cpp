#include "recursion.h"
bool sign(char number);
bool mantissa(char *number);
bool order(char *number);
bool is_digit(char digit);
size_t index_E(char *number);
bool is_real_number(char *number, size_t size)
{
  if (size == 0)
  {
    return false;
  }
  return sign(number[0]) && mantissa(number + 1) && order(number);
}
bool sign(char number)
{
  return number[0] == '+' || number[0] == '-';
}
bool mantissa(char *number)
{
  bool res = true;
  size_t count_point = 0;
  for (size_t i = 1; number[i] && number[i] != 'E'; i++)
  {
    if (!is_digit(number[i]) && number[i] != '.' && count_point < 2)
    {
      res = false;
      break;
    }
    else if (number[i] == '.')
    {
      count_point++;
    }
  }
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
  return index_E(number, ind++);
}
