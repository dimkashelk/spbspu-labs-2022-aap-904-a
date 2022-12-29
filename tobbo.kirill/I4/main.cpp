#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>

void read_array(int* arr, size_t rows, size_t cols, std::ifstream* in)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      *in >> arr[i * cols + j];
      if (!in)
      {
        std::cout << "Error";
        return;
      }
      std::cout << "row: " << i << " col: " << j << " index= " << i * cols + j << " = " << arr[i * cols + j] << "\n";
    }
  }
}

void print_array(int* arr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      std::cout << arr[i * cols + j];
      if (j == (cols - 1))
      {
        std::cout << "\n";
      }
      else
      {
        std::cout << " ";
      }
    }
  }
}

void do_test_3(int* arr, size_t rows, size_t cols, std::ifstream* in)
{
}
void do_test_14(int* arr, size_t rows, size_t cols, std::ifstream* in)
{
  read_array(arr, rows, cols, in);
  print_array(arr, rows, cols);

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
    std::cout << "Error";
    return 1;
  }

  if (!strcmp(argv[1], "3"))
  {
    int arr[1000];
    do_test_3((int*)&arr, rows, cols, &in);
  }
  else if (!strcmp(argv[1], "14"))
  {
    int* arr = new int[rows * cols];
    do_test_14(arr, rows, cols, &in);
    delete[] arr;
  }
  else
  {
    std::cout << "Unexpected test number\n";
    return 1;
  }


  return 0;
}
