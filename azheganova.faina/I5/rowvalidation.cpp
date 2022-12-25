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
bool continueWithNextDigit(const char * data)
{
  return isDigit(*data) && (continueWithNextDigit(data + 1) || isEnd(*(data + 1)));
}
bool continueWithOrder(const char * data)
{
  return isE(*data) && continueWithSign(data + 1) && (continueWithDigit(data + 1) || finishedWithDigit(data + 1));
}
bool continueWithSign(const char * data)
{
  return isSign(*data) && (continueWithSign(data + 1) || continueWithDigit(data + 1));
}
bool continueWithDigit(const char * data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || finishedWithDigit(data + 1));
}
bool finishedWithDigit(const char * data)
{
  return isDigit(*data) && isEnd(*(data + 1));
}
bool continueWithMantisaPartOne(const char * data)
{
  return isDot(*data) && continueWithDigit(data + 1);
}
bool continueWithMantisaPartTwo(const char * data)
{
  return continueWithDigit(data) && isDot(*(data + 1)) && continueWithDigit(data + 2);
}
bool continueWithMantisa(const char * data)
{
  return continueWithMantisaPartOne(data) || continueWithMantisaPartTwo(data) || continueWithDigit(data);
}
bool isFloat(const char * data)
{
  return ((continueWithMantisa(data) && continueWithOrder(data + 1)) || (isSign(*data) && continueWithMantisa(data + 1) && continueWithOrder(data + 2)));
}
