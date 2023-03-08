#include "realNumber.h"

#include <cctype>
#include <stdexcept>

bool isSign(char c)
{
  return (c == '-' || c == '+');
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isDot(char c)
{
  return (c == '.');
}

bool isEChar(char c)
{
  return (c == 'e' || c == 'E');
}

bool isEnd(char c)
{
  return (c == '\0');
}

bool isUnsignedInteger(const char* data, size_t& shift)
{
  bool result = false;
  while (!isEnd(*(data + shift)) && isDigit(*(data + shift)))
  {
    shift++;
    result = true;
  }
  return result;
}

bool isInOrder(const char* data, size_t& shift)
{
  if (isEChar(*data) && isSign(*(data + 1)))
  {
    shift += 2;
    return isUnsignedInteger(data + 2, shift);
  }
  return false;
}

bool isMantissa(const char* data, size_t& shift)
{
  if (isUnsignedInteger(data, shift))
  {
    if (isDot(*(data + shift)))
    {
      shift++;
      if (isUnsignedInteger(data, shift))
      {
        return true;
      }
    }
    else if (isEChar(*(data + shift)))
    {
      shift++;
      return isInOrder(data + shift, shift);
    }
    return true;
  }
  return false;
}

bool myRealNumber(const char* data)
{
  size_t shift = 0;
  const char* currVal = data;

  if (isSign(*currVal))
  {
    currVal++;
  }

  if (!isMantissa(currVal, shift) || !isEnd(*(currVal + shift)))
  {
    return false;
  }
  return true;
}
