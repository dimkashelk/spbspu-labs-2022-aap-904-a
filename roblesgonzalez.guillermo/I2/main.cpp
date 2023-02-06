#include <iostream>
#include "SumofMinandMaxElements.h"
#include "count_ascending_pairs.h"
#include <stdexcept>
#include <cstddef>
#include <ctime>
#include <fstream>

int main(int argc, char *argv[])
{
  if (argc > 2)
   {
    std::cout << "Too much parameters ";
    return 1;
   }
  int arr1[] = {2, 4, 6, 8, 10, 12, 14};
  try
  {
   std::cout << SumofMinandMaxElements(arr1, 7) << std::endl;
   std::cout << count_ascending_pairs(arr1, 7) << std::endl;
  }
  catch (const std::overflow_error &e)
  {
   std::cout << e.what();
   return 2;
  }
  size_t n = 0;
  std::cin >> n;
  int *arr2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
   arr2[i] = std::rand();
  }
   try
   {
    std::cout << SumofMinandMaxElements(arr2, n) << std::endl;
    std::cout << count_ascending_pairs(arr2, n) << std::endl;
   }
   catch (const std::overflow_error &e)
   {
    std::cout << e.what();
    delete[] arr2;
    return 2;
   }
    delete[] arr2;
    std::ifstream in(argv[1]);
    if (!in.is_open())
    {
      std::cout << "Error while opening file";
      return 1;
    }
    while (!in.eof())
    {
     size_t size = 0;
     in >> size;
     if (!in)
      {
        std::cout << "Error...";
        return 1;
      }
       int *arr3 = new int[size]; for (size_t i = 0; i < size; i++)
       {
        in >> arr3[i];
         if (!in)
         {
          std::cout << "Error... ";
          delete[] arr3;
          return 1;
         }
       }
       try
       {
        std::cout << SumofMinandMaxElements(arr3, size) << "\n";
        std::cout << count_ascending_pairs(arr3, size) << "\n";
       }
       catch (const std::overflow_error &e)
       {
        std::cout << e.what();
        delete[] arr3;
        return 2;
       }
      delete[] arr3;
    }
    return 0;
}
