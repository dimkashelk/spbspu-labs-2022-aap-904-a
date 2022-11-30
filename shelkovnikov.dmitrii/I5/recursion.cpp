#include "recursion.h"
bool sign(char *number);
bool mantissa(char *number);
bool order(char *number);
bool is_real_number(char *number)
{
  return sign(number) && mantissa(number) && order(number);
}
bool sign(char* number)
{
  return number[0] == '+' || number[0] == '-';
}
