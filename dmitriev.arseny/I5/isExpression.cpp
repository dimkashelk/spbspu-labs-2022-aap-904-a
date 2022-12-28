#include "isExpression.h"

bool isLetter(const char val)
{
  return (val >= 'A') and (val <= 'E');
}

bool isDigit(const char val)
{
  return (val >= '0') and (val <= '9');
}

bool isOpenBrace(const char val)
{
  return (val == '(');
}

bool isCloseBrace(const char val)
{
  return (val == ')');
}

bool isMuSi(const char val)
{
  return (val == '*');
}

bool isAdSi(const char val)
{
  return (val == '+');
}

bool isSuSi(const char val)
{
  return (val == '-');
}

bool isEnd(const char val)
{
  return (val == '\0');
}

bool isIdentifier(const char val)
{
  return isLetter(val);
}

bool isUnsignedInteger(char* c)
{
  return isDigit(*c) || (isDigit(*c) && isUnsignedInteger(c + 1));
}

bool isMultiplier(char* c)
{
  return isUnsignedInteger(c) || isIdentifier(*c) || (isOpenBrace(*c) && isExpr(c + 1) && isCloseBrace(*c));
}

bool isTerm(char* c)
{
  return isMultiplier(c) || (isMultiplier(c) && isMuSi(*c) && isTerm(c + 1));
}

bool isExpr(char* c)
{
  return isEnd(*c) || isTerm(c) || (isTerm(c) && isAdSi(*c) && isExpr(c + 1)) || (isTerm(c) && isSuSi(*c) && isExpr(c + 1));
}