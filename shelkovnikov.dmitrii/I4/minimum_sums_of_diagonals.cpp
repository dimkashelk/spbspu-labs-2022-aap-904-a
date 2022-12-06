#include "minimum_sums_of_diagonals.h"
#include <algorithm>
#include <stdexcept>
//int sum_of_diagonal_down(const int *arr, const size_t size)
//{
//  int sum = 0;
//  for (size_t i = 0; i < size; i++)
//  {
//    for (size_t j = i; j < size; j++)
//    {
//      sum += arr[j * size + (j - i)];
//    }
//  }
//  return sum;
//}
//int sum_of_diagonal_up(const int *arr, const size_t size)
//{
//  int sum = 0;
//  for (size_t i = 0; i < size; i++)
//  {
//    for (size_t j = i; j < size; j++)
//    {
//      sum += arr[(j + i) * size + j];
//    }
//  }
//  return sum;
//}
int minimum_sums_of_diagonals(const int *arr, const size_t n, const size_t m)
{
  size_t size = std::min(n, m);
  if (size == 0)
  {
    throw std::runtime_error("There is no matrix");
  }
  int minimum = arr[size - 1];
  for (size_t i = 0; i < size; i++)
  {
    int sum_of_diagonal_down = 0;
    int sum_of_diagonal_up = 0;
    for (size_t j = i; j < size; j++)
    {
      sum_of_diagonal_down += arr[j * size + (j - i)];
    }
    for (size_t j = 0; j < size - i; j++)
    {
      sum_of_diagonal_up += arr[(j + i) * size + j];
    }
    if (minimum > sum_of_diagonal_up)
    {
      minimum = sum_of_diagonal_up;
    }
    if (minimum > sum_of_diagonal_down)
    {
      minimum = sum_of_diagonal_down;
    }
  }
  return minimum;
}
