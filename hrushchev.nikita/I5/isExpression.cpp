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