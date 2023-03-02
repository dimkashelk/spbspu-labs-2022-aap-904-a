#include <iostream>
#include "createCString.h"
#include "deleteLatinLetters.h"
#include "createStringCommonSymbols.h"

int main()
{
  size_t size = 27;
  size_t capacity = 10;
  char* source_1 = nullptr;
  try
  {
    source_1 = createCString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  char* destination1 = nullptr;
  try
  {
    destination1 = new char[capacity];
    destination1 = deleteLatinLetters(destination1, source_1);
    std::cout << destination1 << '\n';
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] destination1;
    return 1;
  }

  destination1[size - 1] = '\0';
  for (size_t i = 0; i < size - 1; i++)
  {
    destination1[i] = '.';
  }

  char* destination2 = nullptr;
  char source_2[] = "abcdefg";
  try
  {
    destination2 = new char[capacity];
    destination2 = createStringCommonSymbols(destination2, source_1, source_2);
    std::cout << destination2 << '\n';
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] source_1;
    delete[] destination2;
    return 1;
  }
  return 0;
}
