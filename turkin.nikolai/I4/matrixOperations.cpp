#include "matrixOperations.h"
#include <algorithm>
#include <cmath>

size_t turkin::getNotZeroLines(const int * matrix, size_t mx, size_t my)
{
  size_t amount = 0;
  for (size_t i = 0; i < mx; i++)
  {
    for (size_t q = 0; q < my; q++)
    {
      if (matrix[i * mx + q] == 0)
      {
        amount++;
        break;
      }
    }
  }
  return my - amount;
}

size_t turkin::getSameSumLines(const int * matrix, size_t mx, size_t my)
{
  size_t amount = 0;
  int sum = 0;
  for (size_t i = 0; i < mx; i++)
  {
    sum = getSumOfLine(matrix, mx, my, i);
    for (size_t q = 0; q < mx; q++)
    {
      if (sum == getSumOfLine(matrix, mx, my, q) && i != q)
      {
        amount++;
      }
    }
  }
  return amount;
}

int turkin::getSumOfLine(const int *matrix, size_t mx, size_t my, size_t line)
{
  int sum = 0;
  for (size_t q = 0; q < my; q++)
  {
    sum = sum + matrix[line * mx + q];
  }
  return sum;
}

size_t turkin::getSaddlePoints(const turkin::Matrix & matrix)
{
  size_t amount = 0;
  int element = 0;
  for (size_t i = 0; i < matrix.mx; i++)
  {
    for (size_t q = 0; q < matrix.my; q++)
    {
      element = turkin::get(matrix, i, q);
      int * row = turkin::getRow(matrix, i);
      int * column = turkin::getColumn(matrix, q);
      if (element == *std::min_element(row, row + matrix.my) && element == *std::max_element(column, column + matrix.mx))
      {
        amount++;
      }
      delete [] row;
      delete [] column;
    }
  }
  return amount;
}

size_t turkin::getSumOfModules(const turkin::Matrix & matrix)
{
  turkin::Matrix smoothedMatrix = turkin::getSmoothedMatrix(matrix);
  size_t sum = 0;
  for (size_t i = 0; i < smoothedMatrix.mx; i++)
  {
    for (size_t q = 0; q < i; q++)
    {
      sum = sum + std::abs(turkin::get(smoothedMatrix, i, q));
    }
  }
  return sum;
}

turkin::Matrix turkin::getSmoothedMatrix(const turkin::Matrix &matrix)
{
  turkin::Matrix result(matrix.mx, matrix.my);
  size_t amount = 0;
  int sum = 0;
  for (size_t i = 0; i < matrix.mx; i++)
  {
    for (size_t q = 0; q < matrix.my; q++)
    {
      sum = 0;
      amount = 0;
      for (size_t k = (i == 0) ? i : i - 1; k <= i + 1; k++)
      {
        for (size_t l = (q == 0) ? q : q - 1; l <= q + 1; l++)
        {
          if ((k != i && l != q) && k < matrix.mx && l < matrix.my)
          {
            sum = sum + turkin::get(matrix, k, l);
            amount++;
          }
        }
      }
      turkin::set(result, i, q, sum / amount);
    }
  }
  return result;
}
