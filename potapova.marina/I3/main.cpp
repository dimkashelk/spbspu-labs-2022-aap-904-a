#include "workWithIO.h"
#include "getMostCommonSyms.h"
#include "addAllLatinLetters.h"

int main(int argc, char* argv[])
{
  std::string inp;
  std::getline(std::cin, inp);

  std::cout << inp << '\n';

  return 1;

  if (argc != 3)
  {
    std::cerr << "Incorrect count of main arguments\n";
    return 1;
  }

  size_t input_size;
  char* input_str;
  inputStr(input_size, input_str, argv[1]);
  char* most_common_syms;

  try
  {
    most_common_syms = new char[4];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }

  printAnswer(getMostCommonSyms(most_common_syms, input_str), argv[2]);
  delete[] input_str;
  delete[] most_common_syms;
  size_t str1_size;
  char* str1;
  inputStr(str1_size, str1, argv[1]);
  size_t str2_size;
  char* str2;
  inputStr(str2_size, str2, argv[1]);
  char* all_latin_letters;
  try
  {
    all_latin_letters = new char[str1_size + str2_size + 2];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }

  printAnswer(addAllLatinLetters(all_latin_letters, str1, str2), argv[2]);
  delete[] str1;
  delete[] str2;
  delete[] all_latin_letters;
  return 0;
}
