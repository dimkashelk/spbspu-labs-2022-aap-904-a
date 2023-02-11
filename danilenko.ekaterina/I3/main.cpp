#include <iostream>
#include <cstddef>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"
#include "createStringFromInput.h"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  size_t new_capacity = capacity + 20;
  char* source1 = nullptr;
  std::cout << "Enter string: ";

  try
  {
    source1 = createStringFromInput(std::cin, size, new_capacity);
    if (size > new_capacity)
    {
      throw std::length_error("Long input string");
    }
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << "\n";
    delete[] source1;
    return 1;
  }

  //1
  char source2[] = "abcd";
  size_t string_size1 = capacity + size + 1;
  char* destination1 = new char[string_size1];
  try
  {
    destination1 = makeNewStringWithoutRepeat(destination1, source1, source2);
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] destination1;
    delete[] source1;
    return 1;
  }
  std::cout << "New string without repeating letters from two strings: " << destination1 << "\n";

  //2
  size_t string_size2 = 28;
  char* destination2 = new char[string_size2];
  try
  {
    destination2 = makeNewStringWithMissingLetters(destination2, source1);
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] destination2;
    delete[] source1;
    return 1;
  }
  std::cout << "New string with missing letters in first string: " << destination2;

  delete[] destination1;
  delete[] destination2;
  delete[] source1;
  return 0;
}
