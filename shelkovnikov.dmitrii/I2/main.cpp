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
  std::ifstream in;
  in.open(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file";
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
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    if (in.eof())
    {
      std::cout << "There are fewer numbers in file";
      return 1;
    }
    in >> arr[i];
  }
  CounterMaximumElements counterMaximumElements(arr, n);
  CounterOrderedElements counterOrderedElements(arr, n);
  try
  {
    std::cout << counterMaximumElements.get_maximum_count() << std::endl;
    std::cout << counterOrderedElements.get_count() << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  delete[] arr;
  return 0;
}
