#include "createNewStringFromThreeOfenLetters.h"
#include "createNewStringFromTwoOther.h"
#include "createCString.h"
#include <iostream>
#include <cstddef>
#include <stdexcept>

int main()
{
  char* string1 = nullptr;
  size_t capacity = 10;
  size_t size = 0;
  size_t endIndex = 0;
  try
  {
    string1 = new char[capacity];
    std::cin >> std::noskipws;
    do
    {
      if (size == capacity)
      {
        try
        {
          char* newStr = new char[capacity + 20];
          string1 = createCString(string1, newStr, size);
          string1 = newStr;
          capacity += 20;
        }
        catch (...)
        {
          throw;
        }
      }
      std::cin >> string1[size];
    } while (std::cin && string1[size++] != '\n');
    if (size <= 1)
    {
      throw std::logic_error("empty input");
    }
    else
    {
      string1[size - 1] = '\0';
    }
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string1;
    return 1;
  }
  char string2[] = "0123456789abcdef";
  char* newStringFromTwoOther = nullptr;
  try
  {
    newStringFromTwoOther = new char[capacity + 1];
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string1;
    return 1;
  }
  char* fromThreeLetters = nullptr;
  try
  {
    fromThreeLetters = new char[4];
    for (char* i = string1, *j = fromThreeLetters; endIndex != 3; ++i, ++j, endIndex++)
    {
      *j = *i;
    }
    fromThreeLetters[endIndex] = '\0';
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    delete[] string1;
    delete[] newStringFromTwoOther;
    return 1;
  }
  newStringFromTwoOther = createNewStringFromTwoOther(newStringFromTwoOther, string1, string2, size);
  std::cout << newStringFromTwoOther << "\n";
  fromThreeLetters = createNewStringFromThreeOftenLetters(fromThreeLetters, string1, endIndex);
  std::cout << fromThreeLetters << "\n";
  delete[] string1;
  delete[] newStringFromTwoOther;
  delete[] fromThreeLetters;
  return 0;
}
