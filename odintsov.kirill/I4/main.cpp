#include <iostream>
#include <fstream>
#include <cstring>
#include "threerepeats.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "Error: Invalid arguments\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0) {
    int arr[1000];
    std::ifstream infile(argv[2]);
    if (!infile.is_open()) {
      std::cout << "Error: File could not opened\n";
      return 1;
    }
    unsigned rows = 0;
    unsigned cols = 0;
    infile >> rows >> cols;
    if (!infile) {
      std::cout << "Error: File read error\n";
      return 1;
    }
    if (rows * cols > 1000) {
      std::cout << "Error: Array too large\n";
      return 1;
    }
    for (unsigned i = 0; i < rows * cols; i++) {
      infile >> arr[i];
      if (!infile) {
        std::cout << "Error: File read error\n";
        return 1;
      }
    }
    std::cout << odintsov::countRowsWithThreeRepeats(arr, rows, cols) << '\n';
    std::cout << odintsov::countColsWithThreeRepeats(arr, rows, cols) << '\n';
  }
}
