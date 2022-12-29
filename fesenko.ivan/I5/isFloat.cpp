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
  return isDigit(x) && x != '0';
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

bool finishesWithNonZero(const char *x)
{
  return isNonZero(*x);
}

bool continueInFloatWithDigit(const char *x)
{
  return isDigit(*x) && (continueInFloatWithDigit(x + 1) || finishesWithNonZero(x + 1));
}

bool continueWithDot(const char *x)
{
  return isDot(*x) && (continueInFloatWithDigit(x + 1) || finishesWithNonZero(x + 1));
}

bool continueWithDigit(const char *x)
{
  return isDigit(*x) && (continueWithDigit(x + 1) || continueWithDot(x + 1));
}

bool isSimpleFloat(const char *x)
{
  return isNonZero(*x) && (continueWithDigit(x + 1) || continueWithDot(x + 1));
}

bool isFloat(const char *x)
{
  return isSimpleFloat(x);
}
