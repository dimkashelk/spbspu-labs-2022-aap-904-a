#include <iostream>
#include <fstream>
#include "Partition.hpp"
#include "FindChainOfNumbers.hpp"
#include "PrintArray.hpp"

int main (int argc, char* argv[])
{
  std::srand(time(nullptr));

  if (argc == 1 || argc > 2)
  {
    std::cerr << "Too much parametres" << '\n';
    return 1;
  }

  //first task

  int first_array[] = { -1, 0, 1, 2, 2, -3, 7, 5, -4, 8 };

  try
  {
    std::cout << "Count of chain numbers: " << find_chain(first_array, 10) << '\n';
    partition(first_array,10);
    print_array(std::cout, first_array, 10);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  //Second task

  size_t value = 0;

  std::cin >> value;
  if (std::cin.fail() || value == 0)
  {
    std::cout << "Error with input" << '\n';
    return 0;
  }
  else
  {
    int* second_array = new int[value];
    for (size_t i = 0; i < value; i++)
    {
      second_array[i] = std::rand();
    }
    try
    {
      std::cout << "Count of chain numbers: " << find_chain(second_array, value) << '\n';
      partition(second_array, value);
      print_array(std::cout, second_array, value);
      std::cout << '\n';
    }
    catch (const std::invalid_argument& e)
    {
      std::cerr << "Error: " << e.what() << '\n';
      return 1;
    }
    delete[] second_array;
  }

  //third task

  std::ifstream file(argv[1]);

  if (!file.is_open())
  {
    std::cerr << "Error with opening file" << '\n';
    return 1;
  }

  size_t third_array_size = 0;
  file >> third_array_size;
  if (!file)
  {
    std::cerr << "Error with reading file" << '\n';
    return 1;
  }
  if (third_array_size == 0)
  {
    std::cout << "Empty array" << '\n';
    return 0;
  }
  else
  if (third_array_size)
  {
    while (!file.eof())
    {
      int* third_array = new int[third_array_size];
      for (size_t i = 0; i < third_array_size; i++)
      {
        file >> third_array[i];
        if (!file)
        {
          std::cerr << "Error with reading file" << '\n';
          delete[] third_array;
          return 1;
        }
      }
      try
      {
        std::cout << "Count of chain numbers: " << find_chain(third_array, third_array_size) << '\n';
        partition(third_array, third_array_size);
        print_array(std::cout, third_array, third_array_size);
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        delete[] third_array;
        return 1;
      }
      delete[] third_array;
    }
  }
}
