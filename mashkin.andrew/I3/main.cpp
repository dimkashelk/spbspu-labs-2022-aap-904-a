#include <iostream>
#include <cstddef>
#include "createNewStringFromThreeOfenLetters.h"
#include "createNewStringFromTwoOther.h"
#include "createCString.h"

int main()
{
  char* string1 = nullptr;
  try
  {
    string1 = createCString();
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    return 1;
  }
  char* string2 = nullptr;
  try
  {
    string2 = createCString();
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    return 1;
  }
  char* cstring = nullptr;
  try
  {
    cstring = createCString();
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    return 1;
  }
  char* newStringFromTwoOther = nullptr;
  try
  {
    newStringFromTwoOther = createNewStringFromTwoOther(newStringFromTwoOther, string1, string2);
  }
  catch (const std::exception& ex)
  {
    std::cout << ex.what() << "\n";
    return 1;
  }
  std::cout << newStringFromTwoOther << "\n";
  char* fromThreeLetters = nullptr;
  fromThreeLetters = createNewStringFromThreeOftenLetters(fromThreeLetters, cstring);
  std::cout << fromThreeLetters << "\n";
  delete[] string1;
  delete[] string2;
  delete[] cstring;
  delete[] newStringFromTwoOther;
  delete[] fromThreeLetters;
  return 0;
}
