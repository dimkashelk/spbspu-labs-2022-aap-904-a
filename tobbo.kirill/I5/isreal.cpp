#include "isreal.h"

bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}
bool isSign(char c)
{
  if (c == '+' || c == '-')
    return true;
  return false;
}
bool isNatural(std::string str, int& index)
{
  if (isDigit(str[index]))
  {
    while (isDigit(str[++index]));
    return true;
  }
  return false;
}
bool isOrder(std::string str, int& index)
{
  if (str[index] == 'E')
  {
    index++;
    if (isNatural(str, index))
    {
      return true;
    }
    if (isSign(str[index]))
    {
      index++;
      if (isNatural(str, index))
      {
        return true;
      }
    }
  }
  return false;
}
bool isMantissa(std::string str, int& index)
{
  return (str[index] == '.' && isNatural(str, ++index) || (isNatural(str, index) && str[index] == '.' && isNatural(str, ++index)));
}
bool isReal(const std::string str)
{
  int i = 0;
  return (isMantissa(str, i) && isOrder(str, i) || (isSign(str[i]) && isMantissa(str, ++i) && isOrder(str, i)));
}
