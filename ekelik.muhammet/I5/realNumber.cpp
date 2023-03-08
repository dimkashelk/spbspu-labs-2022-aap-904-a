#include "realNumber.h"

#include <cstddef>
#include <cctype>

#include "RealNumber.h"
#include <cstddef>
#include <cctype>

bool isSigned(char c)
{
  return c == '-' || c == '+';
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isDecimalPoint(char c)
{
  return c == '.';
}

bool isExponentialChar(char c)
{
  return c == 'E';
}

bool isEndOfString(char c)
{
  return c == '\0';
}

bool isUnsignedInteger(const char* data, size_t& shift)
{
  if (!isEndOfString(*(data + shift)) && isDigit(*(data + shift)))
  {
    shift++;
    if (isDecimalPoint(*(data + shift)) || isExponentialChar(*(data + shift)) || isEndOfString(*(data + shift)))
    {
      return true;
    }
    return isUnsignedInteger(data, shift);
  }
  return false;
}

bool isExponentialNotation(const char* data, size_t& shift)
{
  size_t a = 0;
  bool result =  isExponentialChar(*data) && isSigned(*(data + 1)) && isUnsignedInteger(data + 2, a);
  shift += a + 2;
  return result;
}

bool isMantissa(const char* data, size_t& shift)
{
  bool firstNumber = isUnsignedInteger(data, shift);
  if (firstNumber)
  {
    if (isDecimalPoint(*(data + shift)))
    {
      shift += 1;
      bool secondNumber = isUnsignedInteger(data, shift);
      return secondNumber;
    }
    else if (isExponentialChar(*(data + shift)))
    {
      return true;
    }
  }
  return false;
}

bool myRealNumber(const char* data)
{
  size_t shift = 0;
  const char* currVal = data;
  if (isSigned(*currVal))
  {
    currVal++;
  }
  return isMantissa(currVal, shift) && isExponentialNotation(currVal + shift, shift) && isEndOfString(*(currVal + shift));
}
