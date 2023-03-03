#include "isFloat.h"
#include <cctype>
bool isDigit(char symbol)
{
  return std::isdigit(symbol);
}
bool isSign(char symbol)
{
  return (symbol == '+' || symbol == '-');
}
bool isPoint(char symbol)
{
  return (symbol == '.');
}
bool isEnd(char symbol)
{
  return (symbol == '\0');
}
bool isE(char symbol)
{
  return (symbol == 'E');
}

