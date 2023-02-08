#include "readMatrix.h"

int* readMatrixFromFile(int* matrix, const size_t rows, const size_t columns, std::ifstream& inputFile)
{
  for (size_t i = 0; i < rows * columns; i++)
  {
    inputFile >> matrix[i];
    if (!inputFile)
    {
      throw std::runtime_error("Error! An error occurred when reading matrix elements");
    }
  }
  return matrix;
}
