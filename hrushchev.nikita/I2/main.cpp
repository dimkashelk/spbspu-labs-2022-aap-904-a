#include <iostream>
#include <fstream>
#include "getcountmaxelement.hpp"
#include "sortbyeven.hpp"
#include "printarray.hpp"

int main(int argc, char* argv[])
{
  if (argc == 1)
  {
    std::cerr << "No file";
    return 1;
  }
  else if (argc > 2)
  {
    std::cerr << "Too many parameters";
    return 1;
  }


  const size_t size1 = 10;
  int arr1 [size1] = {0, 2, 4, 5 ,6, 7 ,-10 ,8 , 9, 9};
  std::cout << get_count_max_element(arr1, size1) << std::endl;
  sort_by_even(arr1, size1);
  print_array(arr1, size1);
  std::cout << std::endl;


  size_t size2 = 0;
  std::cin >> size2;
  if (!std::cin)
  {
    std::cout << "Input error" << std::endl;
    return 1;
  }
  if (size2 > 0)
  {
    srand(time(0));
    int* arr2 = new int[size2];
    for (size_t i = 0; i < size2; i++)
    {
      arr2[i] = std::rand() % 10;
    }
    std::cout << get_count_max_element(arr2, size2) << std::endl;
    sort_by_even(arr2, size2);
    print_array(arr2, size2);
    delete[] arr2;
    std::cout << std::endl;
  }
  else
  {
    std::cout << "Size < 0" << std::endl;
  }


  size_t size3 = 0;
  std::ifstream input_file(argv[1]);
  if (!input_file.is_open()) {
    std::cerr << "File not open" << std::endl;
    return 1;
  }
  input_file >> size3;
  if (!input_file) {
    std::cerr << "Error while reading" << std::endl;
    return 1;
  }
  int* arr3 = new int[size3];
  for (size_t i = 0; i < size3; i++) {
    input_file >> arr3[i];
    if (!input_file) {
      std::cerr << "Error while reading" << std::endl;
      return 1;
    }
  }
  if (size3 == 0)
  {
    std::cout << "Empty array" << std::endl;
  }
  else
  {
    std::cout << get_count_max_element(arr3, size3) << "\n";
    sort_by_even(arr3, size3);
    print_array(arr3, size3);
  }
  std::cout << std::endl;
  delete[] arr3;
}
