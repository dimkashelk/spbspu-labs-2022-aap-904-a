#include "recursion.h"
bool sign(char *number);
bool mantissa(char *number);
bool order(char *number);
bool is_digit(char digit);
bool is_real_number(char *number)
{
  return sign(number) && mantissa(number) && order(number);
}
bool sign(char* number)
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
