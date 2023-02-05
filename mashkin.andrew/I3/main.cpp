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
  try
  {
    string1 = new char[capacity];
    string1 = createCString(string1, capacity, size);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
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
    size_t index = 3;
    for (char* i = string1, *j = fromThreeLetters; index != 3; i++, j++, index++)
    {
      *j = *i;
    }
    fromThreeLetters[index] = '\0';
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
  fromThreeLetters = createNewStringFromThreeOftenLetters(fromThreeLetters, string1);
  std::cout << fromThreeLetters << "\n";
  delete[] string1;
  delete[] newStringFromTwoOther;
  delete[] fromThreeLetters;
  return 0;
}
