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