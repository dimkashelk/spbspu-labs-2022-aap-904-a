#include <iostream>
#include <cstddef>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"

int main()
{
  size_t capacity = 10;
  char* source1 = new char[capacity];
  size_t size = 0;
  std::cout << "Enter string: ";
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* new_string = new char[capacity + 20];
        for (auto i = source1, j = new_string; i != source1 + size; i++, j++)
        {
          *j = *i;
        }
        delete[] source1;
        source1 = new_string;
        capacity += 20;
      }
      catch (...)
      {
        delete[] source1;
        return 1;
      }
    }
    std::cin >> source1[size];
  }
  while (std::cin && source1[size++] != '\n');
  if (!std::cin && !size)
  {
    std::cout << "Error...";
    delete[] source1;
    return 1;
  }

  //1
  char source2[] = "ahleptgsl";
  char* destination1 = new char[capacity];
  destination1 = makeNewStringWithoutRepeat(destination1, source1, source2, size);
  std::cout << "New string without repeating letters from two strings: " << destination1 << "\n";

  //2
  char* destination2 = nullptr;
  try
  {
    destination2 = new char[27];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] source1;
    return 1;
  }
  destination2 = makeNewStringWithMissingLetters(destination2, source1);
  std::cout << "New string with missing letters in first string: " << destination2;

  delete[] destination1;
  delete[] destination2;
  return 0;
}
