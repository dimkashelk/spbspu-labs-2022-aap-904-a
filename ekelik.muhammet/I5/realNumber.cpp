#include "realNumber.h"
#include <cctype>

bool UnsignedInteger(const char* data, size_t& shift)
{
  if (isdigit(*(data + shift)))
  {
    shift++;
    if (*(data + shift) == '.' || *(data + shift) == 'E' || *(data + shift) == '\0')
    {
      return true;
    }
    return UnsignedInteger(data, shift);
  }
  return false;
}

bool Sign(const char* data, size_t& shift)
{
  if (*(data + shift) == '-' || *(data + shift) == '+')
  {
    shift++;
    return true;
  }
  return false;
}

bool Mantissa(const char* data, size_t& shift)
{
  if (UnsignedInteger(data, shift))
  {
    if (*(data + shift) == '.')
    {
      shift++;
      return UnsignedInteger(data, shift);
    }
    else if (*(data + shift) == 'E')
    {
      return true;
    }
  }
  return false;
}

bool InOrder(const char* data, size_t& shift)
{
  if (*(data + shift) == 'E')
  {
    shift++;
    return Sign(data, shift) && UnsignedInteger(data, shift);
  }
  return true;
}

bool RealNumber(const char* data)
{
  size_t shift = 0;
  const char* currVal = data;
  if (Sign(currVal, shift))
  {
    currVal++;
  }
  return Mantissa(currVal, shift) && InOrder(currVal + shift, shift) && *(currVal + shift) == '\0';
}
