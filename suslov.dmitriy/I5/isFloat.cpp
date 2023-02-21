#include "isFloat.h"
bool isSign(const char *arr);
bool isDigit(const char *arr);
bool isNumber(const char *arr);
bool isExponent(const char *arr);
bool isMantissa(const char *arr);
bool isSign(const char *arr)
{
  if (*arr == '+' || *arr == '-')
  {
    return true;
  }
  return false;
}
bool isDigit(const char *arr)
{
  if ((*arr >= '0' && *arr <= '9') || !(*arr))
  {
    return true;
  }
  return false;
}
bool isNumber(const char *arr)
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
bool isExponent(const char *arr)
{
  if (*arr == 'E')
  {
    return sign(arr + 1) && number(arr + 2);
  }
  return false;
}
bool isMantissa(const char *arr)
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
