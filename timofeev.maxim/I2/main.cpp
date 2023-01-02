#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "decrease.h"
#include "OrderMethod.h"

int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cerr << "File error" << "\n";
    return 2;
  }
  if (argc > 2)
  {
    std::cerr << "File error" << "\n";
    return 2;
  }
  int ready_array[5] = {4,5,3,2,1};
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

  size_t line;
  std::cin >> line;
  if (!std::cin)
  {
    std::cout << "Input error" << "\n";
    return 2;
  }
  std::srand(time(NULL));
  int * dyn_array = new int[line];
  size_t i;
  for (i = 0; i < line; i++)
  {
    dyn_array[i] = rand() % 100;
  }
  try
  {
    std::cout << "Length of Decrease2: " << LengthOfDecreaseVal(dyn_array, line) << "\n";
    std::cout << "Sorted array2: " ;
    Sort_Array(dyn_array,line);
    std::cout << "\n";
  }
  catch (std::overflow_error & e)
  {
    std::cout << e.what() << "\n";
    delete [] dyn_array;
    return 2;
  }
  delete [] dyn_array;

  size_t fsize = 0;
  int * File_Array = new int[fsize];
  std::string fname =argv[1];
  std::ifstream input(fname);
  while (!input.is_open())
  {
    input >> fsize;
    if (!input)
    {
      std::cout << "File error" << "\n";
      delete [] File_Array;
      return 2;
    }
    if (fsize == 0)
    {
      std::cerr << "File is empty" << "\n";
      return 2;
    }
    for (size_t i = 0; i < fsize; ++i)
    {
      input >> File_Array[i];
      if (!input)
      {
        std::cout << "File error" << "\n";
        delete [] File_Array;
        return 2;
      }
    }
    try
    {
      std::cout << "Length of Decrease3: " << LengthOfDecreaseVal(File_Array, fsize) << "\n";
      std::cout << "Sorted array3: " ;
      Sort_Array(File_Array, fsize);
      std::cout << "\n";
    }
    catch (std::overflow_error & e)
    {
      std::cout << e.what() << "\n";
      delete [] File_Array;
      return 0;
    }
    catch (std::length_error & e)
    {
      std::cout << e.what() << "\n";
      delete [] File_Array;
      return 0;
    }
    delete [] File_Array;
  }
}
