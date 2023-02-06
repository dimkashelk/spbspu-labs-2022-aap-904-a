#include "isExpression.hpp"
#include <cctype>

bool isDigit(const char* str) 
{
  return std::isdigit(str);
}

bool isLetter(const char* str) 
{
  return std::isalpha(str);
}

bool isUnsignedInteger(const char* str) 
{
  if (str[0] == '\0') 
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
  if (str[0] == '\0')
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
  if (str[0] == '\0') 
  {
    return false;
  }

  if (!isMultiplier(str)) 
  {
    return false;
  }

  if (str[0] == '*') {
    return isTerm(str + 1);
  }

  return true;
}