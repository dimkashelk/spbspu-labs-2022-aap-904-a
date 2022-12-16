#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "methods.h"

void process_static_array();
void process_dynamic_array(size_t size);
void process_file_array(char* filename);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong number of parameters. Should be 1";
    return 1;
  }
  try
  {
    process_static_array();
    process_dynamic_array(10);
    process_file_array(argv[1]);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}

void print_array(std::string prefix, int* arr, size_t size)
{
  std::cout << prefix;
  std::ostringstream os;
  for (size_t j = 0; j < size; j++)
  {
    os << arr[j] << " ";
  }
  std::cout << os.str() << "\n";
}

void process_array(std::string prefix, int* arr, size_t size)
{
  std::cout << prefix << " with size " << size << "\n";
  if (size == 0)
  {
    std::cout << "Array is empty... skipped\n";
    return;
  }

  int maximum;
  size_t count_maximum;
  count_of_maxes(arr, size, maximum, count_maximum);
  std::cout << "Max value=" << maximum << " count of max: " << count_maximum << "\n";

  print_array("before: ", arr, size);
  shift_part_to_end(arr, size, 0, 5);
  print_array("after:  ", arr, size);

  std::cout << "-----------------\n";
}

void process_static_array()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 10 };

  process_array("Static array", arr, 10);
}

void process_dynamic_array(size_t size)
{
  const unsigned int srand_arg = 5;
  std::srand(srand_arg);
  int* arr = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    arr[i] = rand() % 200 - 100;
  }

  process_array("Dynamic array", arr, size);
}

void process_file_array(char* filename)
{
  std::ifstream input(filename);
  if (!input.is_open())
  {
    throw std::runtime_error("Error while opening file");
  }
  size_t size = 0;
  int* arr = NULL;
  while (!input.eof())
  {
    input >> size;
    if (size == 0)
    {
      std::cout << "Array is empty... size=0\n";
      break;
    }
    if (!input)
    {
      throw std::runtime_error("Error while reading file 1");
    }

    arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      input >> arr[i];
      if (!input)
      {
        delete[] arr;
        throw std::runtime_error("Error while reading file 2");
      }
    }
    process_array("File array", arr, size);
    delete[] arr;
  }
}
