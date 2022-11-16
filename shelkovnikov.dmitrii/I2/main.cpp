#include "countermaximumelements.h"
#include "counterorderedelements.h"
#include <iostream>
#include <fstream>
int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  if (argc == 1)
  {
    std::cout << "No file name....";
    return 1;
  }
  int arr1[] = {1, 2, 3, 4, 5, 6, 7};
  CounterMaximumElements counterMaximumElements1(arr1, 7);
  CounterOrderedElements counterOrderedElements1(arr1, 7);
  try
  {
    std::cout << counterMaximumElements1.get_maximum_count() << std::endl;
    std::cout << counterOrderedElements1.get_count() << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  int n;
  std::cin >> n;
  int *arr2 = new int[n];
  for (int i = 0; i < n; i++)
  {
    arr2[i] = rand();
  }
  CounterMaximumElements counterMaximumElements2(arr2, n);
  CounterOrderedElements counterOrderedElements2(arr2, n);
  try
  {
    std::cout << counterMaximumElements2.get_maximum_count() << std::endl;
    std::cout << counterOrderedElements2.get_count() << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] arr2;
    return 2;
  }
  delete[] arr2;
  std::ifstream in;
  in.open(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  while (!in.eof())
  {
    int size;
    in >> size;
    if (!in)
    {
      std::cout << "Error... =(";
      in.close();
      return 1;
    }
    int *arr3 = new int[size];
    for (int i = 0; i < size; i++)
    {
      in >> arr3[i];
      if (!in)
      {
        std::cout << "Error... =(";
        delete[] arr3;
        in.close();
        return 1;
      }
    }
    CounterMaximumElements counterMaximumElements3(arr3, size);
    CounterOrderedElements counterOrderedElements3(arr3, size);
    try
    {
      std::cout << counterMaximumElements3.get_maximum_count() << std::endl;
      std::cout << counterOrderedElements3.get_count() << std::endl;
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
