#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include "unique_elements.h"
#include "sum_elements_of_new_matrix.h"

int main()
{
  // if (argc != 4)
  // {
  //   std::cout << "Invalid number of arguments." << '\n';
  //   return 1;
  // }
  // size_t n = 0;
  // size_t m = 0;
  // std::ifstream file(argv[2]);
  // file >> n >> m;
  // if (!file)
  // {
  //   std::cout << "Error";
  //   return 1;
  // }
  int matrix[20] = {0, 1, 2, 3,
                    4, 5, 6, 7,
                    8, 9, 10, 11,
                    12, 13, 14, 15};
  std::cout << unique_elements(matrix, 4, 4) << '\n';
  std::cout << sum_elements_of_new_matrix(matrix, 4, 4) << '\n';
  
}
