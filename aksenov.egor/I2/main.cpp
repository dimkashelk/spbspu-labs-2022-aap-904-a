#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "countAmountOfRightPairs.h"
#include "repeatingPositiveNumbers.h"
int main(int argc, char *argv[])
{
  int filled_arr[6] = {-1, 2, 3, 4, 5, 6};
  std::cout << countAmountOfRightPairs(filled_arr, 6) << std::endl;
  std::cout << isRepeatingPositiveNumbers(filled_arr, 6) << std::endl;
  size_t line = 0;
  std::cin >> line;
  if (!std::cin)
  {
    std::cout << "error input" << "\n";
    return 2;
  }
  std::srand(std::time(nullptr));
  int *dynamic_arr = new int[line];
  if (line > 0)
  {
    for (size_t i = 0; i < line; i++)
    {
      dynamic_arr[i] = std::rand();
    }
    std::cout << countAmountOfRightPairs(dynamic_arr, line) << std::endl;
    std::cout << isRepeatingPositiveNumbers(dynamic_arr, line) << std::endl;
  }
  else
  {
    std::cout << "ERROR " << "\n";
  }
  delete [] dynamic_arr;
  if (argc != 2)
  {
    std::cerr << "Not correct amount of parameters" << "\n";
  }
  size_t fsize = 0;
  int *f_arr = new int[fsize];
  std::string fname = argv[1];
  std::ifstream input(fname);
  input >> fsize;
  if (!input)
  {
    std::cout << "File error" << "\n";
    input.close();
    delete [] f_arr;
    return 2;
  }
  for (size_t i = 0; i < fsize; ++i)
  {
    input >> f_arr[i];
    if (!input)
    {
      std::cout << "ERROR" << "\n";
      input.close();
      delete [] f_arr;
      return 2;
    }
  std::cout << countAmountOfRightPairs(f_arr, fsize) << std::endl;
  std::cout << isRepeatingPositiveNumbers(f_arr, fsize) << std::endl; 
    delete [] f_arr;
    input.close();
  }
}
