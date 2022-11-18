#include <limits>
#include <stdexcept>
#include <iostream>
#include <fstream>
unsigned int count_ordered_elements(int *arr, size_t size)
{
  unsigned int count = 0;
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (size_t i = 0; i < size - 1; i++)
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
  int maximum = std::numeric_limits< int >::min();
  for (size_t i = 0; i < size; i++)
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
  constexpr unsigned int max_int = std::numeric_limits< unsigned int >::max();
  for (size_t i = 0; i < size; i++)
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
  try
  {
    std::cout << count_maximum_elements(arr1, 7)
              << count_ordered_elements(arr1, 7) << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  int n = 0;
  std::cin >> n;
  int *arr2 = new int[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    arr2[i] = rand();
  }
  try
  {
    std::cout << count_maximum_elements(arr2, n)
              << count_ordered_elements(arr2, n) << std::endl;
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
    int size = 0;
    in >> size;
    if (!in)
    {
      std::cout << "Error... =(";
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
        return 1;
      }
    }
    try
    {
      std::cout << count_maximum_elements(arr3, size)
                << count_ordered_elements(arr3, size) << std::endl;
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
