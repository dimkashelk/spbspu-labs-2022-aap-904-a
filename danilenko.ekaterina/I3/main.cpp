﻿#include <iostream>
#include <cstddef>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"

int main()
{
  size_t capacity = 10;
  size_t size1 = 0;
  char *source1 = new char[capacity + 1];
  char inp = '\0';
;
  std::cout << "Enter string: ";

  std::cin >> std::noskipws;

  for (std::cin >> inp; (std::cin && inp) && (inp != '\n'); std::cin >> inp)
  {
    if (size1 == capacity)
    {
      capacity = capacity + 20;
      try
      {
        char *new_string = new char[capacity];
        for (size_t i = 0; i < size1; i++)
        {
          new_string[i] = source1[i];
        }
        delete[] source1;
        source1 = new_string;
        new_string = nullptr;
      }
      catch (const std::bad_alloc& e)
      {
        std::cout << e.what() << '\n';
        delete[] source1;
        return 1;
      }
    }
    source1[size1++] = inp;
  }

  if (size1 == 0)
  {
    std::cerr << "Empty string" << '\n';
    delete[] source1;
    return 1;
  }

  source1[size1] = '\0';

  //1
  const char source2[] = "abcd";
  size_t size_source1 = sizeof(source1 + 1);
  size_t size_source2 = sizeof(source2 + 1);
  char* destination1 = nullptr;
  try
  {
    destination1 = new char[size_source1 + size_source2 + 1];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] source1;
    return 1;
  }
  destination1 = makeNewStringWithoutRepeat(destination1, source1, source2);
  std::cout << "New string without repeating letters from two strings: " << destination1 << "\n";
  delete[] destination1;

  //2
  char* destination2 = nullptr;
  try
  {
    destination2 = new char[28];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] source1;
    return 1;
  }
  destination2 = makeNewStringWithMissingLetters(destination2, source1);
  std::cout << "New string with missing letters in first string: " << destination2;
  delete[] destination2;

  delete[] source1;
  return 0;
}
