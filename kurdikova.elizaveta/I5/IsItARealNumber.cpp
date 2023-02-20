#include "IsItARealNumber.h"
#include <cstddef>
#include <cctype>

bool isSign(char c)
{
  return c == '-' || c == '+';
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isDot(char c)
{
  return c == '.';
}

bool isEChar(char c)
{
  return c == 'E';
}

bool isEnd(char c)
{
  return c == '\0';
}

bool isUnsignedInteger(char* data, size_t& shift)
{
  if (!isEnd(*data) && isDigit(*data))
  {
    if (isDot(*(data + 1)) || isEChar(*(data + 1)) || isEnd(*(data + 1)))
    {
      return true;
    }
    return isUnsignedInteger(++data, ++shift);
  }
  return false;
}

bool isInOrder(char* data, size_t& shift)
{
  shift += 2;
  return isEChar(*data) && isSign(*(++data)) && isUnsignedInteger((++data), shift);
}

bool isMantissa(char* data, size_t& shift)
{
  bool firstNumber = isUnsignedInteger(data, shift);
  data += shift;
  if (firstNumber)
  {
    if (isDot(*(++data)))
    {
      shift += 2;
      bool secondNumber = isUnsignedInteger(++data, shift);
      shift++;
      return secondNumber;
    }
    else if (isEChar(*(data)))
    {
      shift++;
      return true;
    }
  }
  return false;
}

bool isRealNumber(char* data)
{
  size_t shift = 0;
  char* currVal = data;
  if (isSign(*currVal))
  {
    currVal++;
  }
  return isMantissa(currVal, shift) && isInOrder(currVal + shift, shift) && isEnd(*(currVal + (++shift)));
}
