#include <iostream>
#include <fstream>
#include "SortEvenOddNumbers.hpp"
#include "FindChainOfNumbers.hpp"
#include "PrintArray.hpp"

int main(int argc, char* argv[])
{
  std::srand(time(nullptr));

  if (argc > 2)
  {
    std::cerr << "Too much parametres" << '\n';
    return 1;
  }
  if (argc == 1)
  {
    std::cerr << "File name not found" << '\n';
    return 1;
  }

  //first task
  int first_array[] = { -1,0,1,2,2,-3,7,5,-4,8 };

  try
  {
    std::cout << "Count of chain numbers: " << find_chain(first_array, 10) << '\n';
    sort_numbers(first_array, 10);
    print_array(first_array, 10, std::cout);
  }
  catch (const std::overflow_error& e)
  {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  //Second task

  size_t value = 0;

  std::cin >> value;
  if (value != 0)
  {
    int* second_array = new int[value];
    for (size_t i = 0; i < value; i++)
    {
      second_array[i] = std::rand();
    }
    try
    {
      std::cout << "Count of chain numbers: " << find_chain(second_array, value) << '\n';
      sort_numbers(second_array, value);
      print_array(second_array, value, std::cout);
      std::cout << '\n';
    }
    catch (const std::overflow_error& e)
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
    std::cerr << "Error with opening file." << '\n';
    return 1;
  }
  size_t third_array_size = 0;
  file >> third_array_size;
  if (!file)
  {
    std::cerr << "Error with reading file" << '\n';
    return 1;
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
        sort_numbers(third_array, third_array_size);
        print_array(third_array, third_array_size, std::cout);
      }
      catch (const std::overflow_error& e)
      {
        std::cerr << "Error: " << e.what() << '\n';
        delete[] third_array;
        return 1;
      }
      delete[] third_array;
    }
  }

}