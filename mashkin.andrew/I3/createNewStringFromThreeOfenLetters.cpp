#include <iostream>
#include <cstddef>
#include "createNewStringFromThreeOfenLetters.h"

char* createNewStringFromThreeOftenLetters(char* fromThreeLetters, const char* cstring)
{
  const size_t SIZE = 3;
  int countyOfSymbols[128]{};
  int threeOftenLetters[SIZE]{};
  int indexOfThreeLetters[SIZE]{};
  for (const char* i = cstring; *i; i++)
  {
    countyOfSymbols[static_cast<int> (*i)]++;
  }
  for (size_t i = 127; i > 0; i--)
  {
    for (size_t j = 0; j < 3; j++)
    {
      if (threeOftenLetters[j] <= countyOfSymbols[i])
      {
        for (size_t k = 2; k > j; k--)
        {
          threeOftenLetters[k] = threeOftenLetters[k - 1];
          indexOfThreeLetters[k] = indexOfThreeLetters[k - 1];
        }
        threeOftenLetters[j] = countyOfSymbols[i];
        indexOfThreeLetters[j] = static_cast<int> (i);
        break;
      }
    }
  }
  for (size_t i = 0; i < SIZE; i++)
  {
    int var = indexOfThreeLetters[i];
    for (size_t j = i + 1; j < SIZE; j++)
    {
      if (indexOfThreeLetters[i] > indexOfThreeLetters[j])
      {
        indexOfThreeLetters[i] = indexOfThreeLetters[j];
        indexOfThreeLetters[j] = var;
        var = indexOfThreeLetters[i];
      }
    }
  }
  for (size_t i = 0; i < SIZE; i++)
  {
    fromThreeLetters[i] = static_cast<char> (indexOfThreeLetters[i]);
  }
  fromThreeLetters[SIZE] = '\0';
  return fromThreeLetters;
}
