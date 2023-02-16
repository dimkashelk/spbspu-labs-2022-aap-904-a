#include <cstring>
#include "ArrayOperations.h"

int taskOne(std::ifstream& fin, std::ofstream& fout)
{
  int arr[1000]{0};
  size_t rows = 0;
  size_t cols = 0;
  fin >> rows;
  fin >> cols;

  if (rows * cols > 1000) {
    std::cerr << "Error: array too big";
    return 1;
  }

  if (!inputArray(arr, rows * cols, fin)) {
    std::cerr << "Error: Unexpected eof";
    return 2;
  }

  fout << "Number of sorted rows: " << sortedRowsCount(arr, rows, cols);
  return 0;
}

int taskTwo(std::ifstream& fin, std::ofstream& fout)
{
  int* arr = nullptr;
  size_t rows = 0;
  size_t cols = 0;
  fin >> rows;
  fin >> cols;

  try {
    arr = new int[rows * cols];
  }
  catch (const std::bad_alloc& err) {
    std::cerr << "Error: " << err.what();
    return 1;
  }

  if (!inputArray(arr, rows * cols, fin)) {
    std::cerr << "Error: Unexpected eof";
    delete[] arr;
    return 2;
  }

  fout << "The matrix is " << (isTriangular(arr, rows, cols) ? "indeed" : "not") << " triangular";
  delete[] arr;
  return 0;
}

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Incorrect amount of arguments";
    return 1;
  }
  std::ifstream fin(argv[2]);
  if (!fin.is_open()) {
    std::cerr << "Input file could not be opened";
    return 2;
  }
  std::ofstream fout(argv[3]);
  if (!fout.is_open()) {
    std::cerr << "Output file could not be opened";
    return 2;
  }
  fin.peek();
  if (fin.eof()) {
    std::cerr << "Input file is empty";
    return 3;
  }

  if (strcmp(argv[1], "1\0") == 0) {
    return taskOne(fin, fout);
  } else if (strcmp(argv[1], "2\0") == 0) {
    return taskTwo(fin, fout);
  } else {
    std::cerr << "Incorrect task number";
    return 4;
  }
}
