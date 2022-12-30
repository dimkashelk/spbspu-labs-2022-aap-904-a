#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>

void fillArray(std::ostream& out, int* arr, size_t rows, size_t cols, std::ifstream* in)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      *in >> arr[i * cols + j];
      if (!in)
      {
        out << "Error";
        return;
      }
      out << "row: " << i << " col: " << j << " index= " << i * cols + j << " = " << arr[i * cols + j] << "\n";
    }
  }
}

void printArray(std::ostream& out, int* arr, size_t rows, size_t cols)
{
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < cols; col++)
    {
      std::cout << arr[row * cols + col];
      if (col == (cols - 1))
      {
        out << "\n";
      }
      else
      {
        out << " ";
      }
    }
  }
}

size_t getPositiveRowsCount(int* arr, size_t rows, size_t cols)
{
  size_t count = 0;
  for (size_t row = 0; row < rows; row++)
  {
    bool foundNegative = false;
    for (size_t col = 0; col < cols; col++)
    {
      if (arr[row * cols + col] < 0)
      {
        foundNegative = true;
        break;
      }
    }
    if (!foundNegative)
    {
      count++;
    }
  }
  return count;
}

int getMaxSumDiag(int* arr, size_t size)
{
  size_t rows = size;
  size_t cols = size;
  int* sums = new int[2 * rows - 1] { 0 };
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < cols; col++)
    {
      size_t diagNum = row + col;
      sums[diagNum] += arr[row * cols + rows - 1 - col];
    }
  }
  size_t maxDiag = 0;
  for (size_t i = 1; i < rows * 2 - 1; i++)
  {
    if (i + 1 != rows && sums[i] > sums[maxDiag])
    {
      maxDiag = i;
    }
  }
  int maxSum = sums[maxDiag];
  delete[] sums;
  return maxSum;
}

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of parameters\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream in(argv[2]);
  in >> rows >> cols;
  if (!in)
  {
    std::cerr << "Error while rading from file\n";
    return 1;
  }
  if (rows * cols > 1000)
  {
    std::cerr << "Too many rows or columns. Max is 1000 elements\n";
    return 1;
  }
  if (!strcmp(argv[1], "3"))
  {
    int arr[1000];
    fillArray(std::cout, arr, rows, cols, &in);
    printArray(std::cout, arr, rows, cols);
    size_t positiveRowsCount = getPositiveRowsCount(( int* )&arr, rows, cols);
    std::cout << "Found positive rows count: " << positiveRowsCount << "\n";
  }
  else if (!strcmp(argv[1], "14"))
  {
    if (rows != cols)
    {
      std::cerr << "Square matrix is supported only\n";
      return 1;
    }
    int* arr = new int[rows * cols];
    fillArray(std::cout, arr, rows, cols, &in);
    printArray(std::cout, arr, rows, cols);
    int maxSumDiag = getMaxSumDiag(arr, rows);
    std::cout << "Max sum in diagonals except main one: " << maxSumDiag << "\n";
    delete[] arr;
  }
  else
  {
    std::cerr << "Unexpected task number. #3, #14 are supported\n";
    return 1;
  }

  return 0;
}
