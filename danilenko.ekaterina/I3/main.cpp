#include <iostream>
#include <cstddef>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"
#include "createStringFromInput.h"


int main()
{
  char* source1 = nullptr;
  size_t capacity = 10;
  size_t size = 0;

  try
  {
    source1 = createStringFromInput(std::cin, size, capacity);
  }
  catch (const std::exception& e)
  {
    delete[] source1;
    std::cout << e.what() << "\n";
    return 1;
  }

  //1
  char source2[] = "abcd";
  char* destination1 = nullptr;
  try
  {
    destination1 = new char[capacity + 1];
    destination1[0] = '\0';
    destination1 = makeNewStringWithoutRepeat(destination1, source1, source2);
    std::cout << "New string without repeating letters from two strings: " << destination1 << "\n";
    delete[] destination1;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] source1;
    std::cout << e.what() << '\n';
    return 1;
  }

  //2
  char* destination2 = nullptr;
  try
  {
    destination2 = new char[28];
    destination2 = makeNewStringWithMissingLetters(destination2, source1);
    std::cout << "New string with missing letters in first string: " << destination2;
    delete[] destination2;
  }
  catch (const std::bad_alloc& e)
  {
    delete[] source1;
    std::cout << e.what() << '\n';
    return 1;
  }

  delete[] source1;
  return 0;
}
