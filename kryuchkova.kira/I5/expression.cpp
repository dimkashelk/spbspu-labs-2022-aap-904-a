#include "expression.h"
#include <cctype>

bool isOpenBrace(const char data)
{
  return data == '(';
}
bool isCloseBrace (const char data)
{
  return data == ')';
}
