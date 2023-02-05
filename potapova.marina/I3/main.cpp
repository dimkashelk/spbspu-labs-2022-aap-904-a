#include "inputStr.h"
#include "getMostCommonSyms.h"
#include "addAllLatinLetters.h"

int main()
{
  size_t input_size;
  char* input_str;
  inputStr(input_size, input_str);
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
