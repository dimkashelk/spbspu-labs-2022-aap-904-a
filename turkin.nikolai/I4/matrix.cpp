#include "matrix.h"

turkin::Matrix::Matrix(size_t mx, size_t my):
  data(new int[mx * my]()),
  mx(mx),
  my(my),
  size(mx * my)
{}

turkin::Matrix::~Matrix()
{
  delete [] data;
}

void turkin::set(turkin::Matrix & matrix, std::ifstream & input)
{
  for (size_t i = 0; i < matrix.size; i++)
  {
    input >> matrix.data[i];
  }
}

void turkin::set(turkin::Matrix & matrix, size_t mx, size_t my, int data)
{
  matrix.data[mx * mx + my] = data;
}

int turkin::get(const turkin::Matrix & matrix, size_t mx, size_t my)
{
  return matrix.data[mx * mx + my];
}

int * turkin::getRow(const turkin::Matrix & matrix, size_t row) {
  int * result = new int[matrix.my]();
  for (size_t i = 0; i < matrix.my; i++)
  {
    result[i] = turkin::get(matrix, row, i);
  }
  return result;
}

int * turkin::getColumn(const turkin::Matrix & matrix, size_t column) {
  int * result = new int[matrix.mx]();
  for (size_t i = 0; i < matrix.mx; i = i + matrix.my)
  {
    result[i] = turkin::get(matrix, i, column);
  }
  return result;
}
