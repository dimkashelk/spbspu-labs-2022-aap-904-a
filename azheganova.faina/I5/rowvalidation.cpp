#include "rowvalidation.h"

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