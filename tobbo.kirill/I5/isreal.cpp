#include "isreal.h"

bool isSign(char c)
{
  return (c == '+' || c == '-');
}
bool isNatural(std::string str, int& index)
{
  if (std::isdigit(str[index]))
  {
    isNatural(str, ++index);
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
  return ((str[index] == '.' && isNatural(str, ++index)) || (isNatural(str, index) && str[index] == '.' && isNatural(str, ++index)));
}
bool isReal(const char* str)
{
  int i = 0;
  return ((isMantissa(str, i) && isOrder(str, i)) || (isSign(str[i]) && isMantissa(str, ++i) && isOrder(str, i)));
}
