#include "rowvalidation.h"
#include <cctype>

bool isSign(char c)
{
  return (c == '+' || c == '-');
}
bool isDigit(char c)
{
  return std::isdigit(c);
}
bool isNonZero(char c)
{
  return isDigit(c) && (c != '0');
}
bool isEnd(char c)
{
  return (c == '\0');
}
bool isDot(char c)
{
  return (c == '.');
}
bool isE(char c)
{
  return (c == 'E');
}
bool isUnsignedInteger(const char * data)
{
  return isDigit(*data) || (isDigit(*data) && isUnsignedInteger(data + 1));
}
bool isOrder(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && isUnsignedInteger(data + 2);
}
bool isMantisaFirstPart(const char * data)
{
  return isDot(*data) && isUnsignedInteger(data + 1);
}
bool isMantisaSecondPart(const char * data)
{
  return isUnsignedInteger(data) && isDot(*(data + 1)) && isUnsignedInteger(data + 2);
}
bool isMantisaThirdPart(const char * data)
{
  return isUnsignedInteger(data);
}
bool isMantisa(const char * data)
{
  return isMantisaFirstPart(data) || isMantisaSecondPart(data) || isMantisaThirdPart(data);
}
bool isRealNumber(const char * data)
{
  return (isMantisa(data) && isOrder(data + 1)) || (isSign(*data) && isMantisa(data + 1) && isOrder(data + 2));
}
