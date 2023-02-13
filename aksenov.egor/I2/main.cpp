#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "countAmountOfRightPairs.h"
#include "repeatingPositiveNumbers.h"
#include "fillArrayWithRandomNumbers.h"
#include "readingFile.h"
int main(int argc, char *argv[])
{
  std::srand(std::time(nullptr));
  int filled_arr[6] = {-1, 3, 3, 4, 5, 6};
  std::cout << countAmountOfRightPairs(filled_arr, 6) << "\n";
  std::cout << isRepeatingPositiveNumbers(filled_arr, 6) << "\n";
  size_t line = 0;
  std::cin >> line;
  if (!std::cin)
  {
    std::cout << "error input" << "\n";
    return 2;
  }
  int *dynamic_arr = new int[line];
  if (line > 0)
  {
    dynamic_arr = fillArrayWithRandomNumbers(dynamic_arr, line);
    std::cout << countAmountOfRightPairs(dynamic_arr, line) << "\n";
    std::cout << isRepeatingPositiveNumbers(dynamic_arr, line) << "\n";
    delete [] dynamic_arr;
  }
  else
  {
    std::cout << "ERROR " << "\n";
    delete [] dynamic_arr;
  }
  line = 0;
  if (argc != 2)
  {
    std::cerr << "Not correct amount of parameters" << "\n";
  }
  int *f_arr = new int[line];
  std::string fname = argv[1];
  std::ifstream input(fname);
  try
  {
    f_arr = readFile(input, line, f_arr);
  }
  catch (const std::length_error & e)
  {
    std::cout << e.what() << "\n";
    delete [] f_arr;
    return 2;
  }
  std::cout << countAmountOfRightPairs(f_arr, line) << "\n";
  std::cout << isRepeatingPositiveNumbers(f_arr, line) << "\n";
  delete [] f_arr;
}
