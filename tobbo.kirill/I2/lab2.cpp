#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "methods.h"

void processStaticArray();
void processDynamicArray();
void processFileArray(char* filename);

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Wrong number of parameters. Should be one";
    return 1;
  }
  try
  {
    processStaticArray();
    processDynamicArray();
    processFileArray(argv[1]);
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

void do_test(std::string prefix, int* arr, size_t size)
{
  std::cout << prefix << "\n";
  int maximum;
  size_t count_maximum;
  count_of_maxes(arr, size, maximum, count_maximum);
  std::cout << "Max value=" << maximum << " count of max: " << count_maximum << "\n";

  print_array("before: ", arr, size);
  shift_part_to_end(arr, size, 0, 5);
  print_array("after:  ", arr, size);

  std::cout << "-----------------\n";
}

void processStaticArray()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 10, 10 };

  do_test("Static array", arr, 10);
}

void processDynamicArray()
{
  size_t size = 0;

  std::cout << "Enter array size:";
  std::cin >> size;

  if (std::cin.fail() || std::cin.peek() != 10 || size < 1)
  {
    throw std::invalid_argument("Array size must be integer greater than 0.");
  }

  srand((unsigned)time(NULL));

  int* arr = new int[size];
  int count = 0;

  for (size_t i = 0; i < size; ++i)
  {
    arr[i] = rand() % 200 - 100;
  }

  do_test("Dynamic array", arr, size);
}

void processFileArray(char* filename)
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
    if (!input)
    {
      throw std::runtime_error("Error while reading file");
    }

    arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      input >> arr[i];
      if (!input)
      {
        delete[] arr;
        throw std::runtime_error("Error while reading file");
      }
    }
    do_test("File array", arr, size);
    delete[] arr;
  }
}
