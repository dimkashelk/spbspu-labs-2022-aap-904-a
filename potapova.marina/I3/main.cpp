#include "workWithIO.h"
#include "getMostCommonSyms.h"
#include "addAllLatinLetters.h"

int main()
{
  const char* input_str;
  try
  {
    input_str = getLineFromFile();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    return 1;
  }
  if (input_str == nullptr)
  {
    std::cerr << "Empty input\n";
    return 1;
  }
  char most_common_syms[4];
  std::cout << getMostCommonSyms(most_common_syms, input_str) << '\n';
  delete[] input_str;

  size_t str1_size;
  char* str1;
  size_t str2_size;
  char* str2;
  try
  {
    str1 = getLineFromFile(str1_size);
    str2 = getLineFromFile(str2_size);
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
  }
  if (str1 == nullptr || str2 == nullptr)
  {
    std::cerr << "One of the strings is empty";
  }
  char* result;
  try
  {
    result = new char[str1_size + str2_size + 1];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    return 1;
  }
  std::cout << addAllLatinLets(result, str1, str2) << '\n';
  delete[] str1;
  delete[] str2;
  delete[] result;
  return 0;
}
