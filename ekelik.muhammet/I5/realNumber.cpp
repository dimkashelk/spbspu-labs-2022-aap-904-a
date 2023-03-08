#include "realNumber.h"

#include <cstddef>
#include <cctype>

bool myIsSign(char sym)
{
  return (sym == '-' || sym == '+');
}

bool myIsDigit(char sym)
{
  return std::isdigit(sym);
}

bool myIsDot(char sym)
{
  return (sym == '.');
}

bool myIsEChar(char sym)
{
  return (sym == 'e' || sym == 'E');
}

bool myIsEnd(char sym)
{
  return (sym == '\0');
}

bool myIsUnsignedInteger(const char* data, size_t& shift)
{
  while (myIsDigit(*(data + shift)))
  {
    shift++;
    if (myIsDot(*(data + shift)) || myIsEChar(*(data + shift)) || myIsEnd(*(data + shift)))
    {
      return true;
    }
  }
  return false;
}

bool myIsInOrder(const char* data, size_t& shift)
{
  if (myIsEChar(*data) && myIsSign(*(data + 1)))
  {
    shift += 2;
    bool isUnsignedInteger = myIsUnsignedInteger(data + shift, shift);
    shift--;
    return isUnsignedInteger;
  }
  return false;
}

bool myIsMantissa(const char* data, size_t& shift)
{
  if (myIsUnsignedInteger(data, shift))
  {
    if (myIsDot(*(data + shift)))
    {
      shift++;
      if (myIsUnsignedInteger(data, shift))
      {
        return myIsEnd(*(data + shift));
      }
      return false;
    }
    else if (myIsEChar(*(data + shift)))
    {
      shift++;
      bool isInOrder = myIsInOrder(data + shift, shift);
      shift--;
      return isInOrder;
    }
    return true;
  }
  return false;
}

bool myRealNumber(const char* data)
{
  size_t shift = 0;
  const char* currVal = data;

  if (myIsSign(*currVal))
  {
    currVal++;
  }
  return myIsMantissa(currVal, shift) && myIsEnd(*(data + shift));
}
