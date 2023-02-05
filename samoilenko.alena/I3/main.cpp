#include<iostream>
#include <fstream>
#include "latin_letters.h"
#include "most_common_characters.h"
int main()
{
  std::ifstream input;
  input.open("input.txt");
  if (!input)
  {
    std::cout << "Error during opening the file";
    return 1;
  }
  int max_len;
  input >> max_len >> std::ws;
  char* str = new char[max_len + 1];
  input.getline(str, max_len);
  char* res = new char[27];
  printNewLatinLetters(res, str);
  countMostCommonCharacters(res, str);
  std::ofstream output;
  output.open("output.txt");
  if (!output)
  {
    std::cout << "Error during opening the file";
  }
  output << res;
  input.close();
  output.close();
  delete[] str;
  delete[] res;
}
