#include <iostream>
#include <cstddef>
#include "makeNewStringWithoutRepeat.h"
#include "makeNewStringWithMissingLetters.h"

int main()
{
  size_t size1 = 0;
  size_t capacity = 10;
  char* source1 = new char[capacity];
  char inp = '\0';
  std::cout << "Enter string: ";
  std::cin >> std::noskipws;

  do
  {
    if (size1 == capacity)
    {
      try
      {
        char* new_string = new char[capacity + 20];
        for (auto i = source1, j = new_string; i != source1 + size1; i++, j++)
        {
          *j = *i;
        }
        delete[] source1;
        source1 = new_string;
        capacity += 20;
      }
      catch (const std::bad_alloc& e)
      {
        std::cout << e.what() << '\n';
        delete[] source1;
        return 1;
      }
    }
    std::cin >> source1[size1];
  }
  while (std::cin && source1[size1++] != '\n');
  
  if (size1 <= 1) 
  {
    delete[] source1;
    std::cerr << "Error. Empty string.";
    return 1;
  }
  
  source1[size1 - 1] = '\0';

  //1
  const char source2[] = "abcd";
  size_t size_source2 = sizeof(source2 + 1);
  char* destination1 = nullptr;
  try
  {
    destination1 = new char[capacity + size_source2 + 1];
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
