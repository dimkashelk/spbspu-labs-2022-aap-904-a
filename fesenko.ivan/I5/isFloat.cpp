#include "isFloat.h"
#include <cctype>

bool isSign(char x)
{
  return x == '+' || x == '-';
}
bool isDigit(char x)
{
  return std::isdigit(x);
}
bool isNonZero(char x)
{
  return x != '0';
}
bool isEnd(char x)
{
  return x == '\0';
}

bool isDot(char x)
{
  return x == '.';
}

bool isE(char x)
{
  return x == 'E';
}


bool isFloat(const char *x)
{
  return *x == '\0';
}
