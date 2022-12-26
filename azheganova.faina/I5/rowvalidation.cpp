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
  return isDigit(*data) && (continueWithDigit(data + 1) || isEnd(*(data + 1)));
}
bool continueWithSign(const char * data)
{
  return isSign(*data) && (continueWithSign(data + 1) || continueWithDigit(data + 1));
}
bool isOrder(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && continueWithDigit(data + 2);
}
bool continueWithDot(const char * data)
{
  return continueWithDigit(data) && (isDot(*(data + 1)) || continueWithDot(data + 1));
}
bool isFloat(const char * data)
{
  return ((continueWithDot(data) && isOrder(data + 1)) || (isSign(*data) && continueWithDot(data + 1) && isOrder(data + 2)));
}
