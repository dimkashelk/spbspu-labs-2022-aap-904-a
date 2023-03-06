#include "isExpression.h"

bool isDigit(const char c)
{
  return std::isdigit(c);
}
bool isIdentificator(const char c)
{
  return c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'x' || c == 'y' || c == 'z';
}
bool isEnd(const char c)
{
  return (c == '\0');
}
bool isSign(const char c)
{
  c == '+' || c == '-' || c == '*' || c == '/';
}
bool isCloseBar(const char c)
{
  return (c == ')');
}
bool isOpenBar(const char c)
{
  return (c == '(');
}
bool isUnsigned(const char *data)
{
  return isDigit(*data) || (isDigit(*data) &&  isUnsigned(data + 1));
}
bool isMultiplier(const char *data)
{
  return isUnsigned(data) || isIdentificator(*data) || (isOpenBar(*data) && isExpression(data + 1) && isCloseBar(*data));
}

bool isTerm(const char *data)
{
  return isMultiplier(data) || (isMultiplier(data) && isSign(*data) && isTerm(data + 1));
}

bool isExpression(const char *data)
{
  return isEnd(*data) || isTerm(data) && isSign(*(data + 1)) && isExpression(data + 1) || isDigit(*data);
}

