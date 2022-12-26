#include "rowvalidation.h"
#include <cctype>

bool isSign(char data)
{
  return (data == '+' || data == '-');
}
bool isDigit(char data)
{
  return std::isdigit(data);
}
bool isEnd(char data)
{
  return (data == '\0');
}
bool isDot(char data)
{
  return (data == '.');
}
bool isE(char data)
{
  return (data == 'E');
}
bool continueWithDigit(const char * data)
{
  return isDigit(*data) && (isDigit(*(data + 1)) || isEnd(*(data + 1)));
}
bool continueWithE(const char * data)
{
  return isDigit(*data) && (isDigit(*(data + 1)) || isE(*(data + 1)));
}
bool continueWithSign(const char * data)
{
  return isSign(*data) && continueWithDigit(data + 1);
}
bool continueWithD(const char * data)
{
  return isDigit(*data) && (continueWithD(data + 1) || isDot(*(data + 1)));
}
bool isOrder(const char * data)
{
  return isE(*data) && isSign(*(data + 1)) && continueWithDigit(data + 2);
}
bool continueWithDot(const char * data)
{
  return isDigit(*data) && (isDot(*(data + 1)) || continueWithDot(data + 1));
}
bool isFloat(const char * data)
{
  return (isSign(*data) && continueWithD(data + 1) && continueWithE(data + 2) && continueWithSign(data + 3));
}
