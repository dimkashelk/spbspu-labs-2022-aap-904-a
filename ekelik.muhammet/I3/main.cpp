#include <iostream>
#include <cstddef>
<<<<<<< HEAD
#include <myString.h>
#include "commonSymbols.h"
#include "uncommonSymbols.h"
=======
#include <my_String.h>
#include "common_symbols.h"
#include "uncommon_symbols.h"
>>>>>>> origin/ekelik.muhammet/I4

int main()
{
  size_t size = 0;
  size_t capacity = 10;

<<<<<<< HEAD
  char* source1 = makeMyString(size, capacity, std::cin);
  if (source1[0] == '\n')
  {
    delete[] source1;
=======
  char* my_string = makeMyString(size, capacity, std::cin);

  if (my_string[0] == '\n')
  {
    delete[] my_string;
>>>>>>> origin/ekelik.muhammet/I4
    std::cerr << "Error: empty string \n";
    return 2;
  }

  // Task 5
<<<<<<< HEAD
  char source2[] = "0123456789abcdefglmn";
  char* mySymbols = nullptr;
  try
  {
    mySymbols = new char[size + 1];
    mySymbols[size] = '\0';
=======
  char* my_symbols = nullptr;
  try
  {
    my_symbols = new char[size + 1];
    my_symbols[size] = '\0';
>>>>>>> origin/ekelik.muhammet/I4
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
<<<<<<< HEAD
    delete[] source1;
    return 1;
  }
  findUncommonSymbols(mySymbols, source1, source2);
  std::cout << "Uncommon symbols: " << mySymbols << '\n';

  // Task 19
  size_t symbols = 0;
  char* myCommonSymbols = nullptr;
  try
  {
    myCommonSymbols = new char[4];
    myCommonSymbols[symbols] = '\0';
=======
    delete[] my_string;
    return 1;
  }
  find_uncommon_symbols(my_symbols, my_string);
  std::cout << "Uncommon symbols: " << my_symbols << '\n';

  // Task 19
  size_t symbols = 0;
  char* my_common_symbols = nullptr;
  try
  {
    my_common_symbols = new char[4];
    my_common_symbols[symbols] = '\0';
>>>>>>> origin/ekelik.muhammet/I4
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: \n" << e.what();
<<<<<<< HEAD
    delete[] source1;
    delete[] mySymbols;
    return 1;
  }
  findCommonSymbols(myCommonSymbols, source1);
  std::cout << "Common symbols: " << myCommonSymbols << '\n';

  delete[] source1;
  delete[] mySymbols;
  delete[] myCommonSymbols;
=======
    delete[] my_string;
    delete[] my_symbols;
    return 1;
  }
  find_common_symbols(my_common_symbols, my_string, symbols);
  std::cout << "Common symbols: " << my_common_symbols << '\n';

  delete[] my_string;
  delete[] my_symbols;
  delete[] my_common_symbols;
>>>>>>> origin/ekelik.muhammet/I4
  return 0;
}
