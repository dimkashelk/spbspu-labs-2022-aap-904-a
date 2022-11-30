#include "methods.h"

turkin::Array turkin::deleteNumbers(const turkin::Array & string)
{
  turkin::Array result(string.size);
  for (size_t i = 0; i < string.size; i++)
  {
    if (!turkin::isNumber(string.data[i]))
    {
      result.push(string.data[i]);
    }
  }
  result.push('\0');
  return result;
}

bool turkin::isRepeat(const turkin::Array & string)
{
  size_t amount;
  for (size_t i = 0; i < string.size; i++)
  {
    amount = 0;
    for (size_t k = 0; k < string.size; k++)
    {
      if (string.data[i] == string.data[k])
      {
        amount++;
      }
    }
    if (amount > 1)
    {
      return true;
    }
  }
  return false;
}

bool turkin::isNumber(char symbol)
{
  size_t amount = 0;
  for (char number = '0'; number <= '9'; number++)
  {
    if (symbol == number)
    {
      amount++;
    }
  }
  if (amount > 0)
  {
    return true;
  }
  return false;
}
