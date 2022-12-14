#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "decrease.h"
#include "OrderMethod.h"

int main(int argc, char **argv)
{
  int x;
  std::cin >> x;
  if (!std::cin)
  {
    std::cout << "input error" << "\n";
  }
  int ready_array[5] = {1,2,3,4,5};
  try
  {
    std::cout << "Length of Decrease: " << LengthOfDecreaseVal(ready_array, 5) << "\n";
    std::cout << "Sorted array: " << Sort_Array(ready_array,5) << "\n";
  }
  catch (std::overflow_error & e)
  {
    std::cout << e.what() << "\n";
    return 0;
  }

  size_t line = x;
  std::srand(time(nullptr));
  int * dyn_array = new int[line];
  size_t i;
  for (i = 0; i < line; i++)
  {
    dyn_array[i] = std::rand() % 10;
  }
  try
  {
    std::cout << "Length of Decrease: " << LengthOfDecreaseVal(dyn_array, line) << "\n";
    std::cout << "Sorted array: " << Sort_Array(dyn_array,line) << "\n";
  }
  catch (std::overflow_error & e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  delete [] dyn_array;


  if (argc != 2)
  {
    std::cerr << "Not correct amount of CML args" << "\n";
    return 2;
  }
  std::ifstream input(argv[1]);
  if (!input)
  {
    std::cout << "File Error\n" ;
  }
  else
  {
    size_t size = 0;
    int * File_Array = new int[size];
    input >> size;
    if (!input)
    {
      std::cout << "File error\n";
    }
    while (input.eof())
    {
      for (i = 0; i < size; ++i)
      {
        input >> File_Array[i];
      }
      try
      {
        std::cout << "Length of Decrease" << LengthOfDecreaseVal(File_Array, size) << "\n";
        std::cout << "Sorted array: " << Sort_Array(File_Array, size) << "\n";
      }
      catch (std::overflow_error & e)
      {
        std::cout << e.what() << "\n";
        return 0;
      }
    }
    delete [] File_Array;
  }
}
