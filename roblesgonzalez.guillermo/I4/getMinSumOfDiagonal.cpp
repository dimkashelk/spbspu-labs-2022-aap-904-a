#include "getMinSumOfDiagonal.h"
#include <stdexcept>

long long calcSumOfMainDiagonal(const int* arr, size_t rows, size_t cols)
{
    long long summ = 0;
    for (size_t i = 0; i < rows; ++i)
    {
        summ += arr[i * (cols + 1)]; // add element from main diagonal
    }
    return summ;
}

long long calcSumOfUpperDiagonal(const int* arr, size_t rows, size_t cols)
{
    long long summ = 0;
    for (size_t i = 0; i < rows - 1; ++i)
    {
        summ += arr[(i + 1) * cols + i]; // add element from upper diagonal
    }
    return summ;
}

long long calcSumOfLowerDiagonal(const int* arr, size_t rows, size_t cols)
{
    long long summ = 0;
    for (size_t i = 0; i < rows - 1; ++i)
    {
        summ += arr[i * cols + (i + 1)]; // add element from lower diagonal
    }
    return summ;
}

long long calcMinSummSecondaryDiagonal(double * arr, size_t rows, size_t cols)
{
    const int* intArr = reinterpret_cast<const int *>(static_cast<double *>(arr));
    if (rows != cols)
    {
        throw std::invalid_argument("Matrix is not square\n");
    }
    long long max_summ = 0;
    max_summ = std::max(max_summ, calcSumOfMainDiagonal(intArr, rows, cols));
    max_summ = std::max(max_summ, calcSumOfUpperDiagonal(intArr, rows, cols));
    max_summ = std::max(max_summ, calcSumOfLowerDiagonal(intArr, rows, cols));
    return max_summ;
}
