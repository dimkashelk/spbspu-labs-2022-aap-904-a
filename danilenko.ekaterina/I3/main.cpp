#include <iostream>
#include <cstddef>
#include <cstring>
#include <createStringFromInput.h>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  size_t new_capacity = capacity + 20;
  char* string = nullptr;
  std::cout << "Enter string: ";

  try
  {
    string = createStringFromInput(std::cin, string, size, capacity);
    if (size > new_capacity)
    {
      throw std::length_error("Long input string");
    }
  }
  catch (const std::exception& e)
  {
    delete[] string;
    std::cout << e.what() << "\n";
    return 1;
  }

  //1
  char source2[] = "abcd";
  size_t size1 = std::strlen(string);
  size_t size2 = std::strlen(source2);
  size_t string_size1 = size1 + size2 + 1;
  char* destination1 = nullptr;
  try
  {
    destination1 = new char[string_size1 + 20];
    destination1 = makeNewStringWithoutRepeat(destination1, string, source2);
  }
  catch (const std::bad_alloc& e)
  {
    delete[] destination1;
    delete[] string;
    std::cout << e.what() << '\n';
    return 1;
  }
  std::cout << "New string without repeating letters from two strings: " << destination1 << "\n";

  //2
  char* destination2 = nullptr;
  try
  {
    destination2 = new char[26];
    destination2 = makeNewStringWithMissingLetters(destination2, string);
  }
  catch (const std::bad_alloc& e)
  {
    delete[] destination2;
    delete[] string;
    std::cout << e.what() << '\n';
    return 1;
  }
  std::cout << "New string with missing letters in first string: " << destination2;

  delete[] destination1;
  delete[] destination2;
  delete[] string;
  return 0;
}
