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

bool isExpr(char* c)
{
  return
}