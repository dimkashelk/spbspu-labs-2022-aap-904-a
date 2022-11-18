#include "countermaximumelements.h"
#include "counterorderedelements.h"
#include <iostream>
#include <fstream>
unsigned int count_ordered_elements(int *arr, size_t size)
{
  unsigned int count = 0;
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (int i = 0; i < length - 1; i++)
  {
    if (arr[i] < arr[i + 1])
    {
      if (count == max_int)
      {
        throw std::overflow_error("Too much numbers....");
      }
      count++;
    }
  }
  return count;
}
int get_maximum(int *arr, size_t size)
{
  int maximum = std::numeric_limits<int>::min();
  for (int i = 0; i < length; i++)
  {
    if (maximum < arr[i])
    {
      maximum = arr[i];
    }
  }
  return maximum;
}
unsigned int count_maximum_elements(int *arr, size_t size)
{
  unsigned int count = 0;
  int maximum = get_maximum(arr, size);
  constexpr unsigned int max_int = std::numeric_limits<unsigned int>::max();
  for (int i = 0; i < length; i++)
  {
    if (maximum == arr[i])
    {
      if (count == max_int)
      {
        throw std::overflow_error("Too much numbers....");
      }
      count++;
    }
  }
  return count;
}
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