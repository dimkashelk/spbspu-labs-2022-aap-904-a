#include "ArrayOperations.h"

void output(int* arr, size_t rows, size_t cols) //For debug
{
  int j = 0;
  for (size_t i = 0; i < rows * cols; ++i) {
    if (j == cols) {
      j = 0;
      std::cout << '\n';
    }
    std::cout << arr[i] << ' ';
    j++;
  }
  std::cout << '\n';
}

void taskOne(std::ifstream& fin, std::ofstream& fout)
{
  int arr[1000]{0};
  size_t rows = 0;
  size_t cols = 0;
  fin >> rows;
  fin >> cols;

  if (rows * cols > 1000) {
    std::cerr << "Error: array too big";
    return;
  }
  inputArray(arr, rows * cols, fin);

  output(arr, rows, cols);
  fout << "Number of sorted rows: " << sortedRowsCount(arr, rows, cols);
}

void taskTwo(std::ifstream& fin, std::ofstream& fout)
{

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
    std::cerr << "output file could not be opened";
    return 2;
  }

  void (*choose[2])(std::ifstream& fin, std::ofstream& fout) = {taskOne, taskTwo};
  choose[argv[1][0] - 49](fin, fout);
}
