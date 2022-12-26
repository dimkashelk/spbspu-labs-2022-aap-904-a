#include <iostream>
#include <fstream>
#include <cstring>
#include "drawMatrix.hpp"
#include "threeRepeats.hpp"
#include "diagonalSum.hpp"
#include "fillMatrix.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cout << "Error: Invalid arguments\n";
    return 1;
  }
  std::ifstream infile(argv[2]);
  if (!infile.is_open()) {
    std::cout << "Error: File could not be opened\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  infile >> rows >> cols;
  if (!infile) {
    std::cout << "Error: File read error\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0) {
    int arr[1000];
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
  } else if(std::strcmp(argv[1], "2") == 0) {
    int** arr = new int*[rows];
    for (size_t r = 0; r < rows; r++) {
      arr[r] = new int[cols];
      for (size_t c = 0; c < cols; c++) {
        infile >> arr[r][c];
        if (!infile) {
          std::cout << "Error: File read error\n";
          return 1;
        }
      }
    }
    std::cout << odintsov::getMinOffDiagonalSum(arr, rows, cols) << '\n';
    odintsov::rippleFromPointFill(arr, rows, cols, 0, 0);
    odintsov::drawMatrix(std::cout, arr, rows, cols) << '\n';
  }
}
