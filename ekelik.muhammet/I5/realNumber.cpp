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
  while (!myIsEnd(*(data + shift)) && myIsDigit(*(data + shift)))
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
  if (!myIsEChar(*data))
  {
    return false;
  }
  ++data;
  ++shift;
  if (!myIsSign(*data))
  {
    return false;
  }
  ++data;
  ++shift;
  size_t a = 0;
  if (!myIsUnsignedInteger(data, a))
  {
    return false;
  }
  shift += a;
  return true;
}

bool myIsMantissa(const char* data, size_t& shift)
{
  bool firstNumber = myIsUnsignedInteger(data, shift);
  if (firstNumber)
  {
    if (myIsDot(*(data + shift)))
    {
      shift += 1;
      bool secondNumber = myIsUnsignedInteger(data, shift);
      return secondNumber;
    }
    else if (myIsEChar(*(data + shift)))
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
  if (myIsSign(*currVal))
  {
    currVal++;
  }
  return myIsMantissa(currVal, shift) && myIsInOrder(currVal + shift, shift) && myIsEnd(*(currVal + shift));
}
