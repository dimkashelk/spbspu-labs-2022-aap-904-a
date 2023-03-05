#include "getMinSumOfDiagonal.h"
#include <stdexcept>
long long calcSummSecDiagonal(const int * arr, size_t rows, size_t cols, size_t summ_of_index)
{
    long long summ = 0;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            if ((i + j) == summ_of_index)
            {
                summ += arr[(i * cols) + j];
            }
        }
    }
    return summ;
}
long long calcMinSummSecondaryDiagonal(const int * arr, size_t rows, size_t cols)
{
    if (rows != cols)
    {
        throw std::invalid_argument("No diagonal in not square matrix\n");
    }
    long long max_summ = 0;
    for (size_t i = 0; i < (2 * rows) - 1; ++i)
    {
        long long summ = calcSummSecDiagonal(arr, rows, cols, i);
        if (max_summ < summ)
        {
            max_summ = summ;
        }
    }
    return max_summ;
}
