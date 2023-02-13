#include "IsItARealNumber.h"
#include <iostream>

bool isSign(char c)
{
  return c == '-' || c == '+';
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isUnsignedInteger(char* data, size_t& move)
{
  bool result = isDigit(*data) && isUnsignedInteger(++data, move) || isDigit(*data);
  return result, ++move;
}

bool isInOrder(char* data, size_t& move)
{
  bool result = (*data) == 'E' && isSign(*(++data)) && isUnsignedInteger((++data), move);
  return result;
}

bool isMantissa(char* data, size_t& move)
{
  bool integer = (*data) != '-' && isUnsignedInteger(data, move);
  bool fractional =  integer && (*(data + (--move))) == '.' && isUnsignedInteger(data + (++move), move);
  return fractional || integer;
}

bool isEnd(char c)
{
  return c == '\0';
}

bool isRealNumber(char* data)
{
  size_t move = 0;
  bool wthSign = false;
  bool wotSign = false;
  wthSign = isMantissa(data, move) && isInOrder(data + (--move), move) && isEnd(*(data + (++move)));
  move = 0;
  wotSign = isSign(*data) && isMantissa(++data, move) && isInOrder(data + (--move), move) && isEnd(*(data + (++move)));
  return wthSign || wotSign;
}
