#include "rowvalidation.h"
#include <cctype>

bool isSign(char c)
{
  return (c == '+' || c == '-');
}
bool isDigit(char c)
{
  return std::isdigit(c);
}
bool isNonZero(char c)
{
  return isDigit(c) && (c != '0');
}
bool isEnd(char c)
{
  return (c == '\0');
}