#include <iostream>
#include <cstddef>
#include <myString.h>
#include "commonSymbols.h"
#include "uncommonSymbols.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;

  char* myString = makeMyString(size, capacity, std::cin);

  if (myString[0] == '\n')
  {
    delete[] myString;
    std::cerr << "Error: empty string \n";
    return 2;
  }

  // Task 5
  char* mySymbols = nullptr;
  try
  {
    mySymbols = new char[size + 1];
    mySymbols[size] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
    delete[] myString;
    return 1;
  }
  findUncommonSymbols(mySymbols, myString);
  std::cout << "Uncommon symbols: " << mySymbols << '\n';

  // Task 19
  size_t symbols = 0;
  char* myCommonSymbols = nullptr;
  try
  {
    myCommonSymbols = new char[4];
    myCommonSymbols[symbols] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
    delete[] myString;
    delete[] mySymbols;
    return 1;
  }
  findCommonSymbols(myCommonSymbols, myString, symbols);
  std::cout << "Common symbols: " << myCommonSymbols << '\n';

  delete[] myString;
  delete[] mySymbols;
  delete[] myCommonSymbols;
  return 0;
}
