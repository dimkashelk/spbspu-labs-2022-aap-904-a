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
bool continueWithNextDigit(const char * data)
{
  return isDigit(*data) && (continueWithNextDigit(data + 1) || isEnd(*(data + 1)));
}
bool continueWithUnsignedInteger(const char * data)
{
  return isDigit(*data) && (isDigit(*(data + 1)) || continueWithUnsignedInteger(data + 1));
}
bool continueWithOrder(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && continueWithNextDigit(data + 2);
}
bool continueWithDotAndUnsignedDigit(const char * data)
{
  return isDot(*data) && continueWithUnsignedInteger(data + 1 );
}
bool continueWithUnsignedDigitDotAndUnsignedDigit(const char * data)
{
  return continueWithUnsignedInteger(data) && isDot(*(data + 1)) && continueWithUnsignedInteger(data + 2);
}
bool isMantisa(const char * data)
{
  return continueWithDotAndUnsignedDigit(data) || continueWithUnsignedDigitDotAndUnsignedDigit(data) || continueWithUnsignedInteger (data);
}
bool isFloat(const char * data)
{
  return ((isMantisa(data) && continueWithOrder(data + 1)) || (isSign(*data) && isMantisa(data + 1) && continueWithOrder(data + 2)));
}
