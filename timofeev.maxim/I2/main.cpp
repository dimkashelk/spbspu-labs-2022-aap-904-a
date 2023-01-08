#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "decrease.h"
#include "order.h"

int main(int argc, char *argv[])
{
  int ready_array[5] = {4,5,3,2,1};
  try
  {
    std::cout << "Length of Decrease1: " << length_of_decrease_value(ready_array, 5) << "\n";
    std::cout << "Sorted array1: " ;
    partition(ready_array, 5);
    for (int p = 0; p < 5; p++)
    {
      if (p != 5)
      {
        std::cout << ready_array[p] << " ";
      }
      else
      {
        std::cout << ready_array[p];
      }
    }
    std::cout << "\n";
    if (partition(ready_array, 5))
    {
      std::cout << "divider " << *partition(ready_array, 5) << "\n";
    }
    else
    {
      return 0;
    }
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
    std::cout << "Sorted array2: " ;
    partition(dyn_array,line);
    for (size_t w = 0; w < line; w++)
    {
      if (w != line)
      {
        std::cout << dyn_array[w] << " ";
      }
      else
      {
        std::cout << dyn_array[w];
      }
    }
    std::cout << "\n";
    if (partition(dyn_array, line))
    {
      std::cout << "divider " << *partition(dyn_array, line) << "\n";
    }
    else
    {
      return 0;
    }
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
    delete [] File_Array;
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
    std::cout << "Length of Decrease3: " << length_of_decrease_value(File_Array, fsize) << "\n";
    std::cout << "Sorted array3: " ;
    partition(File_Array, fsize);
    for (size_t q = 0; q < fsize; q++)
    {
      if (q != fsize)
      {
        std::cout << ready_array[q] << " ";
      }
      else
      {
        std::cout << ready_array[q];
      }
    }
    std::cout << "\n";
    if (partition(File_Array, 5))
    {
      std::cout << "divider " << *partition(File_Array, line) << "\n";
    }
    else
    {
      return 0;
    }
  }
  catch (const std::length_error & e)
  {
    std::cout << e.what() << "\n";
    delete [] File_Array;
    return 0;
  }
  delete [] File_Array;
}
