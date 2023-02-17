#include "is_float.h"
#include <iostream>
bool isDigit(char c)
{
  return std::isdigit(c);
}
bool isSign(char c)
{
  return (c== '+' || c == '-');
}
bool isDot(char c)
{
  return (c == '.');
}
bool isE(char c)
{
  return (c == 'E');
}
bool isEndString(char c)
{
  return (c == '\0');
}
bool isFloat(const char * data)
{

}
