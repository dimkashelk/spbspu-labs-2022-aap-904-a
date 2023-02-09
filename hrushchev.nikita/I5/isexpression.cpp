#include "isexpression.hpp"

bool isLetter(const char* str)
{
    return (*str >= 'a') && (*str <= 'e');
}

bool isDigit(const char* str)
{
    return (*str >= '0') && (*str <= '9');
}

bool isUnsignedInteger(const char* str)
{
  if (*str == '\0')
  {
    return false;
  }

  if (!isDigit(str))
  {
    return false;
  }

  return isUnsignedInteger(str + 1);
}

bool isIdentifier(const char* str)
{
  if (*str == '\0')
  {
    return false;
  }

  if (!isLetter(str))
  {
    return false;
  }

  return isIdentifier(str + 1);
}

bool isMultiplier(const char* str)
{
  return isUnsignedInteger(str) || isIdentifier(str);
}

bool isTerm(const char* str)
{
  if (*str == '\0')
  {
    return false;
  }

  if (!isMultiplier(str))
  {
    return false;
  }

  if (*str == '*')
  {
    return isTerm(str + 1);
  }

  return true;
}

bool isExpression(const char* str)
{
  if (*str == '\0')
  {
    return false;
  }

  if (!isTerm(str))
  {
    return false;
  }

  if (*str == '+' || *str == '-')
  {
    return isExpression(str + 1);
  }

  return true;
}

