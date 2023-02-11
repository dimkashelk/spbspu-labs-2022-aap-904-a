#include <iostream>
#include <cstddef>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"
#include "createStringFromInput.h"


int main()
{
  char* source1 = nullptr;
  size_t capacity = 10;
  std::cout << "Enter string: ";
  try
  {
    source1 = createStringFromInput(std::cin);
  }
  catch (...)
  {
    return 1;
  }

  //1
  char source2[] = "abcd";
  size_t size2 = sizeof source2;
  char* destination1 = nullptr;
  try
  {
    destination1 = new char[capacity + size2 + 1];
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
