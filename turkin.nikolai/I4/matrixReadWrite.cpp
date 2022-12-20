#include "matrixReadWrite.h"

void turkin::set(int * matrix, size_t size, std::ifstream & input)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> matrix[i];
  }
}

void turkin::set(int * matrix, size_t mx, size_t my, int data)
{
  matrix[mx * mx + my] = data;
}

int turkin::get(const int * matrix, size_t mx, size_t my)
{
  return matrix[mx * mx + my];
}

int * turkin::getRow(const int * matrix, size_t my,  size_t row) {
  int * result = new int[my]();
  for (size_t i = 0; i < my; i++)
  {
    result[i] = turkin::get(matrix, row, i);
  }
  return result;
}

int * turkin::getColumn(const int * matrix, size_t mx, size_t my, size_t column) {
  int * result = new int[mx]();
  for (size_t i = 0; i < mx; i = i + my)
  {
    result[i] = turkin::get(matrix, i, column);
  }
  return result;
}
