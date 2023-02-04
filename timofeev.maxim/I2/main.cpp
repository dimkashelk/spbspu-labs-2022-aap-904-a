#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "decrease.h"
#include "order.h"

int main(int argc, char *argv[])
{
  int ready_array[5] = {4, 5, 3, 2, 1};
  try
  {
    std::cout << "Length of Decrease1: " << length_of_decrease_value(ready_array, 5) << "\n";
    std::cout << "divider " << *partition(ready_array, 5) << "\n";
  }
  catch (const std::length_error & e)
  {
    std::cout << e.what() << "\n";
    return 0;
  }

  size_t line = 0;
  std::cin >> line;
  if (!std::cin)
  {
    std::cout << "Input error" << "\n";
    return 2;
  }

  std::srand(time(nullptr));
  int *dyn_array = new int[line];
  if (line > 0)
  {
    for (size_t i = 0; i < line; i++)
    {
      dyn_array[i] = std::rand() % 100;
    }
    std::cout << "Length of Decrease2: " << length_of_decrease_value(dyn_array, line) << "\n";
    std::cout << "divider " << *partition(dyn_array, line) << "\n";
  }
  else
  {
    std::cout << "Error " << "\n";
  }
  delete [] dyn_array;

  if (argc != 2)
  {
    std::cerr << "Not correct amount of CML argc" << "\n";
    return 2;
  }

  size_t fsize = 0;
  int *File_Array = new int[fsize];
  std::string fname = argv[1];
  std::ifstream input(fname);
  input >> fsize;
  if (!input)
  {
    std::cerr << "File error" << "\n";
    input.close();
    delete [] File_Array;
    return 2;
  }
  for (size_t i = 0; i < fsize; ++i)
  {
    input >> File_Array[i];
    if (!input)
    {
      std::cout << "File error" << "\n";
      input.close();
      delete [] File_Array;
      return 2;
    }
  }
  try
  {
    std::cout << "Length of Decrease3: " << length_of_decrease_value(File_Array, fsize) << "\n";
    std::cout << "divider " << *partition(File_Array, fsize) << "\n";
  }
  catch (const std::length_error & e)
  {
    std::cout << e.what() << "\n";
    input.close();
    delete [] File_Array;
    return 0;
  }
  delete [] File_Array;
  input.close();
}
