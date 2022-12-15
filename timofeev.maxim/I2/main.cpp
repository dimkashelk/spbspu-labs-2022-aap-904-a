#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "decrease.h"
#include "OrderMethod.h"

int main(int argc, char *argv[])
{
  int x;
  std::cin >> x;
  if (!std::cin)
  {
    std::cout << "input error" << "\n";
  }
  int ready_array[5] = {5,4,3,2,1};
  try
  {
    std::cout << "Length of Decrease1: " << LengthOfDecreaseVal(ready_array, 5) << "\n";
    std::cout << "Sorted array1: " ;
    Sort_Array(ready_array,5);
    std::cout << "\n";
  }
  catch (std::overflow_error & e)
  {
    std::cout << e.what() << "\n";
    return 0;
  }

  size_t line = x;
  std::srand(time(NULL));
  int * dyn_array = new int[line];
  size_t i;
  for (i = 0; i < line; i++)
  {
    dyn_array[i] = rand() % 100 - 10;
  }
  try
  {
    std::cout << "Length of Decrease2: " << LengthOfDecreaseVal(dyn_array, line) + 1 << "\n";
    std::cout << "Sorted array2: " ;
    Sort_Array(dyn_array,line);
    std::cout << "\n";
  }
  catch (std::overflow_error & e)
  {
    std::cout << e.what() << "\n";
    delete [] dyn_array;
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
        std::cout << "Length of Decrease3: " << LengthOfDecreaseVal(File_Array, size) << "\n";
        std::cout << "Sorted array3: " ;
        Sort_Array(File_Array, size);
        std::cout << "\n";
      }
      catch (std::overflow_error & e)
      {
        std::cout << e.what() << "\n";
        delete [] File_Array;
        return 0;
      }
    }
    delete [] File_Array;
  }
}
