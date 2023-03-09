#include "realNumber.h"

#include <cstddef>
#include <cctype>

bool isEnd(char s)
{
  return s == '\0';
}

bool isDigit(char s)
{
  return std::isdigit(s);
}

bool isSign(char s)
{
  return s == '+' || s == '-';
}

bool isDot(char s)
{
  return s == '.';
}

bool isE(char s)
{
  return s == 'E' || s == 'e';
}

bool isUnsignInteger(const char* data)
{
  if (isEnd(*data))
  {
    return false;
  }
  if (isDigit(*data))
  {
    return isUnsignInteger(data + 1);
  }
  return isEnd(*data);
}

bool isOrder(const char* data)
{
  if (!isE(*data))
  {
    return false;
  }
  data++;
  if (isSign(*data))
  {
    data++;
  }
  return isUnsignInteger(data);
}

bool isMantissa(const char* data)
{
  if (isDot(*data))
  {
    return isUnsignInteger(data + 1);
  }
  return isUnsignInteger(data);
}

bool isRealNumber(const char* data)
{
  if (isSign(*data))
  {
    data++;
  }
  if (isEnd(*data))
  {
    return false;
  }
  if (isMantissa(data))
  {
    data++;
    return isEnd(*data) || isOrder(data);
  }
  return false;
}
