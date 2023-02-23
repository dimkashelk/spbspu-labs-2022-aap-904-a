#include "isFloat.h"
bool isSign(const char *arr);
bool isDigit(const char *arr);
bool isNumber(const char *arr);
bool isExponent(const char *arr);
bool isMantissa(const char *arr);
bool isSign(const char *arr)
{
  return (*arr == '+' || *arr == '-');
}
bool isDigit(const char *arr)
{
  return ((*arr >= '0' && *arr <= '9') || !(*arr));
}
bool isNumber(const char *arr)
{
  if (!(*arr))
  {
    return true;
  }
  if (*arr == 'E')
  {
    return isExponent(arr);
  }
  return isDigit(arr) && isNumber(arr + 1);
}
bool isExponent(const char *arr)
{
  if (*arr == 'E')
  {
    return isSign(arr + 1) && isNumber(arr + 2);
  }
  return false;
}
bool isMantissa(const char *arr)
{
  if (*arr == '.')
  {
    return isNumber(arr + 1);
  }
  return false;
}
bool isReal(const char *arr)
{
  if (isSign(arr))
  {
    return isMantissa(arr + 1);
  }
  return false;
}
