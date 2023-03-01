#include <iostream>
#include "CountDifferentLetters.h"
#include "NewStringIndeticalCharacters.h"
#include "CreateCString.h"

int main()
{
  char *source1 = nullptr;
  try
  {
    source1 = createCString(std::cin);
    if (*source1 == '\0')
    {
      delete[] source1;
      throw std::logic_error("Empty string");
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t countDifLett = countDifLetters(source1);
  std::cout << countDifLett << "\n";

  char source2[] = "adfgvbh";
  char *destination = nullptr;
  try
  {
    destination = new char[100];
  }
  catch(const std::bad_alloc& e)
  {
    delete[] source1;
    std::cerr << e.what() << '\n';
    return 1;
  }
  destination = newStringIndeticalCharacters(destination, source1, source2);
  std::cout << destination << "\n";

  delete[] destination;
  delete[] source1;
  return 0;
}