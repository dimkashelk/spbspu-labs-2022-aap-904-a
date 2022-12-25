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

bool turkin::isMultiplier(const turkin::CharArray & array, size_t i)
{
  if (isSign(array.data[i]) || isEnd(array.data[i]))
  {
    return true;
  }
  return (isDigit(array.data[i]) || isID(array.data[i])) && isMultiplier(array, ++i);
}

bool turkin::isTerm(const turkin::CharArray & array, size_t i)
{
  if (isSign(array.data[i]) || isEnd(array.data[i]))
  {
    return true;
  }
  return isMultiplier(array, i) && isTerm(array, ++i);
}

bool turkin::isExpression(const turkin::CharArray & array, size_t i)
{
  if (isEnd(array.data[i]))
  {
    return true;
  }
  return isTerm(array, i) && isExpression(array, ++i);
}
