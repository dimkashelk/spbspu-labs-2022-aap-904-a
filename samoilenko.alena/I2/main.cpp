#include <iostream>
#include <cstddef>
#include <fstream>
#include "negative_elements.h"
#include "shifted_array.h"
int main(int argc, char* argv[])
{
  if (argc == 1 || argc > 2)
  {
    std::cout << "File or parameters are incorrect";
    return 1;
  }
  const size_t array_shift = 3;
  int array[10] = {6, 9, -11, 4, 1, 26, 73, -38, -45, -21};
  std::cout << countNegativeElementsAfterMax(array, 10) << std::endl;
  size_t size_arr = 10;
  moveTheArray(array, 10, array_shift);
  for(size_t i = 0; i < size_arr; i++)
  {
    std::cout << array[i] << ' ';
  }
  size_t num_of_elem = 0;
  std::cin >> num_of_elem;
  int *dynamic_array = new int[num_of_elem];
  const size_t r = 5;
  std::srand(r);
  for(size_t i = 0; i < num_of_elem; i++)
  {
    dynamic_array[i] = std::rand();
  }
  std::cout << countNegativeElementsAfterMax(dynamic_array, num_of_elem) << std::endl;
  for (size_t i = 0; i < num_of_elem; i++)
  {
    std::cout << dynamic_array[i] << ' ';
  }
  std::cout << std::endl;
  moveTheArray(dynamic_array, num_of_elem, array_shift);
  for(size_t i = 0; i < num_of_elem; i++)
  {
    std::cout << dynamic_array[i] << ' ';
  }
  delete [] dynamic_array;
  std::cout << '\n';
  std::ifstream input(argv[1]);
  if (!input)
  {
    std::cout << "Error during opening the file input.txt";
    return 1;
  }
  size_t size_of_mas = 0;
  input >> size_of_mas;
  int* arr_from_file = new int[size_of_mas];
  for(size_t i = 0; i < size_of_mas; i++)
  {
    input >> arr_from_file[i];
  }
  std::cout << countNegativeElementsAfterMax(arr_from_file, size_of_mas);
  for (size_t i = 0; i < size_of_mas; i++)
  {
    std::cout << arr_from_file << ' ';
  }
  std::cout << std::endl;
  moveTheArray(arr_from_file, size_of_mas, array_shift);
  for(size_t i = 0; i < size_of_mas; i++)
  {
    std::cout << arr_from_file[i] << ' ';
  }
  delete [] arr_from_file;

  return 0;
}
