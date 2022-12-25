#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "count_of_maxes.h"
#include "shift_part_to_end.h"

void print_array(std::ostream& out, std::string prefix, int* arr, size_t size);
void process_array(std::string prefix, int* arr, size_t size);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong number of parameters. Should be 1";
    return 1;
  }
  try
  {
    /*********************************************/
    int arr_st[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 10 };
    process_array("Static array", arr_st, 10);

    /*********************************************/
    size_t size = 0;
    std::cout << "Enter array size:";
    std::cin >> size;

    if (!std::cin)
    {
      throw std::invalid_argument("Array size must be unsigned integer");
    }
    std::cout << "Received array size:" << size << "\n";

    const unsigned int srand_arg = 5;
    std::srand(srand_arg);
    int* arr_dyn = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      arr_dyn[i] = rand() % 200 - 100;
    }
    process_array("Dynamic array", arr_dyn, size);
    delete[] arr_dyn;

    /*********************************************/
    int* arr = nullptr;
    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
      throw std::runtime_error("File is not found");
    }
    while (!input.eof())
    {
      input >> size;
      if (!input)
      {
        throw std::runtime_error("Error while reading size of array");
      }
      arr = new int[size];
      for (size_t i = 0; i < size; i++)
      {
        input >> arr[i];
        if (!input)
        {
          delete[] arr;
          throw std::runtime_error("Error while reading array elements");
        }
      }
      process_array("File array", arr, size);
      delete[] arr;
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}

void print_array(std::ostream& out, std::string prefix, int* arr, size_t size)
{
  out << prefix;
  for (size_t j = 0; j < size; j++)
  {
    out << arr[j] << " ";
  }
  out << "\n";
}

void process_array(std::string prefix, int* arr, size_t size)
{
  std::cout << prefix << " with size " << size << "\n";
  if (size == 0)
  {
    std::cout << "Array is empty... skipped\n";
    return;
  }

  int maximum = 0;
  size_t count_maximum = 0;
  count_of_maxes(arr, size, maximum, count_maximum);
  std::cout << "Max value=" << maximum << " count of max: " << count_maximum << "\n";

  print_array(std::cout, "before: ", arr, size);
  shift_part_to_end(arr, size, 0, static_cast< size_t >(std::ceil(size / 2)));
  print_array(std::cout, "after:  ", arr, size);
}
