#include "readMatrix.h"

void readMatrix(std::ifstream& inputFile, int* matrix, size_t numRows, size_t numCols)
{
  for (size_t i = 0; i < numRows; i++)
  {
    for (size_t j = 0; j < numCols; j++)
    {
      inputFile >> matrix[numCols * i + j];
    }
  }
}
