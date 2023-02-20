#include "isFloat.h"
bool sign(char *arr);
bool digit(char *arr);
bool number(char *arr);
bool exponent(char *arr);
bool mantissa(char *arr);
bool sign(char *arr)
{
  if (*arr == '+' || *arr == '-')
  {
    return true;
  }
  return false;
}
bool digit(char *arr)
{
  if (*arr >= '0' and *arr <= '9')
  {
    return true;
  }
  return false;
}
bool number(char *arr)
{
  if (*arr == 'E')
  {
    return exponent(arr);
  }
  return digit(arr) && number(arr + 1);
}
bool exponent(char *arr)
{
  if (*arr == 'E')
  {
    return sign(arr + 1) && number(arr + 2);
  }
  return false;
}
bool mantissa(char *arr)
{
  if (*arr == '.')
  {
    return number(arr + 1);
  }
  return false;
}
bool real(char *arr)
{
  if (sign(arr))
  {
    return mantissa(arr + 1);
  }
  return false;
}
