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
    std::cout << "Size < 0";
  }


  size_t file_arr_size = 0;
  std::ifstream in(argv[1]);
  if (!in.is_open()) {
    std::cerr << "Can not open the file\n";
    return 2;
  }
  in >> file_arr_size;
  if (!in) {
    std::cerr << "Can not read from file\n";
    return 2;
  }
  int *file_arr = new int[file_arr_size];
  for (size_t i = 0; i < file_arr_size; i++) {
    in >> file_arr[i];
    if (!in) {
      std::cerr << "Error while reading\n";
      return 2;
    }
  }
  if (file_arr_size == 0) {
    std::cout << "Array size must not be 0\n";
  } else {
    std::cout << get_count_max_element(file_arr, file_arr_size) << "\n";
  }
  sort_by_even(file_arr, file_arr_size);
  for (size_t i = 0; i < file_arr_size; i++) {
    std::cout << file_arr[i] << " ";
  }
  std::cout << "\n";
  delete[] file_arr;
}
