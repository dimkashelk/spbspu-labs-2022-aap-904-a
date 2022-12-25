#include "IsExpression.hpp"
#include <cctype>

bool isOpenBrace(const char x)
{
  return x == '(';
}

bool isCloseBrace(const char x)
{
  return x == ')';
}

bool isIdentificator(const char x)
{
  return x == 'a' || x == 'b' || x == 'c' || x == 'd' || x == 'e' || x == 'f' || x == 'x' || x == 'y' || x == 'z';
}

bool isDigit(const char x)
{
  return std::isdigit(x);
}

bool isEnd(const char x)
{
  return (x == '\0');
}

bool isSign(const char x)
{
  return x == '+' || x == '-' || x == '*' || x == '/';
}

bool isUnsigned(char *x)
{
  return isDigit(*x) || (isDigit(*x) && isUnsigned(++x));
}

bool isMultiplier(char *x)
{
  return isUnsigned(x) || isIdentificator(*x) || (isOpenBrace(*x) && isExpression(++x) && isCloseBrace(*x));
}

bool isTerm(char *x)
{
  return isMultiplier(x) || (isMultiplier(x) && isSign(*x) && isTerm(++x));
}

bool isExpression(char *x)
{
  return isEnd(*x) || (isTerm(x) && isSign(*(++x)) && isExpression(++x)) || isDigit(*x);
}