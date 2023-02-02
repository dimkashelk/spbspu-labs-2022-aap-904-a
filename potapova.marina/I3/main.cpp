#include <iostream>
#include "getMostCommonSyms.h"
#include "addAllLatinLetters.h"
#include "inputStr.h"

int main()
{
  size_t count;
  if (!(std::cin >> count))
  {
    std::cerr << "Input error\n";
  }
  char* input_str;
  try
  {
    input_str = new char[count + 1];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }
  if (!(std::cin >> input_str))
  {
    std::cerr << "Input error\n";
  }
  char* result;
  try
  {
    result = new char[4];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }
  std::cout << getMostCommonSyms(result, input_str) << '\n';
  delete[] input_str;
  delete[] result;

  size_t str1_size;
  char* str1;
  inputStr(str1_size, str1);
  size_t str2_size;
  char* str2;
  inputStr(str2_size, str2);
  char* result2;
  try
  {
    result2 = new char[str1_size + str2_size + 2];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }
  std::cout << addAllLatinLetters(result2, str1, str2) << '\n';
  delete[] str1;
  delete[] str2;
  delete[] result2;
  return 0;
}
o
