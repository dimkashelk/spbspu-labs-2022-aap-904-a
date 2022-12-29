#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>

void initArray(std::ostream& out, int* arr, size_t rows, size_t cols, std::ifstream* in)
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

size_t doTest03(std::ostream& out, int* arr, size_t rows, size_t cols, std::ifstream* in)
{
  initArray(out, arr, rows, cols, in);
  printArray(out, arr, rows, cols);
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

void doTest14(std::ostream& out, int* arr, size_t rows, size_t cols, std::ifstream* in)
{
  /*14) Максимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы.*/

  initArray(out, arr, rows, cols, in);
  printArray(out, arr, rows, cols);

  /*
  std::ofstream out(argv[3]);
  out << count_lines_with_unique_elements(arr, n, m) << "\n";
  try
  {
    out << minimum_sums_of_diagonals(arr, n, m) << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cout << e.what();
  }
  */
}

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "Wrong number of parameters\n";
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
    size_t positiveRowsCount = doTest03(std::cout, ( int* )&arr, rows, cols, &in);
    std::cout << "Found positive rows: " << positiveRowsCount << "\n";
  }
  else if (!strcmp(argv[1], "14"))
  {
    int* arr = new int[rows * cols];
    doTest14(std::cout, arr, rows, cols, &in);
    delete[] arr;
  }
  else
  {
    std::cout << "Unexpected test number\n";
    return 1;
  }


  return 0;
}
