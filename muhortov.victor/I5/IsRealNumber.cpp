#include "IsRealNumber.hpp"
#include <cctype>

bool isSign(const char x)
{
  return x == '+' || x == '-';
}

bool isNum(const char x)
{
  return std::isdigit(x);
}

bool isE(const char x)
{
  return x == 'E';
}

bool isDot(const char x)
{
  return x == '.';
}

bool isEnd(const char x)
{
  return x == '\0';
}

bool isNumWithoutSign(const char *x)
{
  return isNum(*x) || (isNum(*x) && isNumWithoutSign(++x));
}

bool isOrder(const char *x)
{
  return (isE(*x) && isSign(*(x + 1)) && isNumWithoutSign(x + 2)) || (isE(*x) && isNumWithoutSign(x + 1));
}

bool isMantis(const char *x)
{
  return (isDot(*x) && isNumWithoutSign(++x)) || (isNumWithoutSign(x) && isDot(*(++x)) && isNumWithoutSign(x + 1));
}

bool beforeE(const char *x)
{
  return (isMantis(x)) || (isSign(*x) && isMantis(++x));
}

bool afterE(const char *x)
{
  return (isOrder(x + 2)) || (isOrder(x + 3));
}

bool isRealNum(const char *x)
{
  return isEnd(*x) || (beforeE(x) && afterE(x));
}
