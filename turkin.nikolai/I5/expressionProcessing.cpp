#include "expressionProcessing.h"
#include <cctype>

bool turkin::isEnd(char c)
{
  return c == '\0';
}

bool turkin::isSign(char c)
{
  return c == '+' || c == '-' || c == '*';
}

bool turkin::isDigit(char c)
{
  return std::isdigit(c);
}

bool turkin::isID(char c)
{
  return c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e';
}

bool turkin::isMultiplier(const char * array)
{
  if (isSign(*array) || isEnd(*array))
  {
    return true;
  }
  return (isDigit(*array) || isID(*array)) && isMultiplier(++array);
}

bool turkin::isTerm(const char * array)
{
  if (isSign(*array) || isEnd(*array))
  {
    return true;
  }
  return isMultiplier(array) && isTerm(++array);
}

bool turkin::isExpression(const char * array)
{
  if (isEnd(*array))
  {
    return true;
  }
  return isTerm(array) && isExpression(++array);
}
