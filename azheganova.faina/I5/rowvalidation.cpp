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
bool isNotZero(char c)
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
bool continueWithDigit(const char * data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || continueWithDot(data + 1));
}
bool continueWithDot(const char * data)
{
  return isDot(*data);
}
bool continueWithUnsignedInteger(const char * data)
{
  return continueWithDigit(data) || (continueWithDigit(data) && continueWithUnsignedInteger(data + 1));
}
bool isOrder(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && continueWithUnsignedInteger(data + 2);
}
bool isMantisaFirstPart(const char * data)
{
  return isDot(*data) && continueWithUnsignedInteger(data + 1);
}
bool isMantisaSecondPart(const char * data)
{
  return continueWithUnsignedInteger(data) && isDot(*(data + 1)) && continueWithUnsignedInteger(data + 2);
}
bool isMantisaThirdPart(const char * data)
{
  return continueWithUnsignedInteger(data);
}
bool isMantisa(const char * data)
{
  return isMantisaFirstPart(data) || isMantisaSecondPart(data) || isMantisaThirdPart(data);
}
bool isRealNumber(const char * data)
{
  return (isMantisa(data) && isOrder(data + 1)) || (isSign(*data) && isMantisa(data + 1) && isOrder(data + 2));
}
