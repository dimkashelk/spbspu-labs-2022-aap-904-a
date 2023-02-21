#include "isFloat.h"
bool sign(const char *arr);
bool digit(const char *arr);
bool number(const char *arr);
bool exponent(const char *arr);
bool mantissa(const char *arr);
bool sign(const char *arr)
{
  if (*arr == '+' || *arr == '-')
  {
    return true;
  }
  return false;
}
bool digit(const char *arr)
{
  if ((*arr >= '0' && *arr <= '9') || !(*arr))
  {
    return true;
  }
  return false;
}
bool number(const char *arr)
{
  if (!(*arr))
  {
    return true;
  }
  if (*arr == 'E')
  {
    return exponent(arr);
  }
  return digit(arr) && number(arr + 1);
}
bool exponent(const char *arr)
{
  if (*arr == 'E')
  {
    return sign(arr + 1) && number(arr + 2);
  }
  return false;
}
bool mantissa(const char *arr)
{
  if (*arr == '.')
  {
    return number(arr + 1);
  }
  return false;
}
bool isReal(const char *arr)
{
  if (sign(arr))
  {
    return mantissa(arr + 1);
  }
  return false;
}
