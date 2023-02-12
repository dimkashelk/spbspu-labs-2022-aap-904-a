#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "countAmountOfRightPairs.h"
#include "repeatingPositiveNumbers.h"
#include "fillArrayWithRandomNumbers.h"
int main(int argc, char *argv[])
{
  int filled_arr[6] = {-1, 2, 3, 4, 5, 6};
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
  dynamic_arr = fillArrayWithRandomNumbers(line);
  if (line > 0)
  {
    std::cout << countAmountOfRightPairs(dynamic_arr, line) << "\n";
    std::cout << isRepeatingPositiveNumbers(dynamic_arr, line) << "\n";
  }
  else
  {
    std::cout << "ERROR " << "\n";
    delete [] dynamic_arr;
  }
  delete [] dynamic_arr;
  if (argc != 2)
  {
    std::cerr << "Not correct amount of parameters" << "\n";
  }
  int *f_arr = new int[line];
  std::string fname = argv[1];
  std::ifstream input(fname);
  input >> line;
  if (!input)
  {
    std::cout << "File error" << "\n";
    input.close();
    delete [] f_arr;
    return 2;
  }
  for (size_t i = 0; i < line; ++i)
  {
    input >> f_arr[i];
    if (!input)
    {
      std::cout << "ERROR" << "\n";
      input.close();
      delete [] f_arr;
      return 2;
    }
    std::cout << countAmountOfRightPairs(f_arr, line) << "\n";
    std::cout << isRepeatingPositiveNumbers(f_arr, line) << "\n";
    delete [] f_arr;
    input.close();
  }
  delete [] f_arr;
}
