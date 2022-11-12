#include "dynamicArray.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char * argv[]) 
{
  if (argc != 2)
  {
    std::cerr << "invalid amount of arguments\n";
    return 1;
  }
  if (argv[1] == std::string("-const"))
  {
    int data[10] = {4, 3, 2, 1, 5, 2, 1, 9, 9, 9};
    //work
  }
  if (argv[1] == std::string("-dynamic"))
  {
    int capacity = 0;
    std::cin >> capacity;
    if (!std::cin)
    {
      std::cerr << "incorrect input\n";
      return 2;
    }
    turkin::Array * array = new turkin::Array(capacity);
    for (size_t i = 0; i < capacity; i++)
    {
      array->size++;
      array->data[i] = std::rand();
    }
    std::cout << array->size << "\n";
    delete array;
  }
  if (argv[1] == std::string("-file"))
  {
    std::fstream input("/home/lagushka/CLionProjects/lab6/data.txt");
    if (!input.is_open())
    {
      std::cerr << "cannot open file\n";
      return 3;
    }
    std::string line;
    getline(input, line);
    size_t capacity = std::stoi(line);
    turkin::Array * array = new turkin::Array(capacity);
    for (size_t i = 0; i < capacity; i++)
    {
      getline(input, line);
      array->size++;
      array->data[i] = std::stoi(line);
    }
    //work
    std::cout << array->size << "\n";
    delete array;
  }
  return 0;
}
