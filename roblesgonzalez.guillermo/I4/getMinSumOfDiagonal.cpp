#include "getMinSumOfDiagonal.h"
#include <stdexcept>
long long calcMinSummSecondaryDiagonal(double * arr, size_t rows, size_t cols) {
    const int* intArr = reinterpret_cast<const int *>(static_cast<double *>(arr));

    if (rows != cols) {
        throw std::invalid_argument("Matrix is not square\n");
    }

    long long max_summ = 0;

    // Calculate sum of main diagonal
    long long summ = 0;
    for (size_t i = 0; i < rows; ++i) {
        summ += intArr[i * (cols + 1)]; // add element from main diagonal
    }
    max_summ = summ;

    // Calculate sum of upper diagonal
    summ = 0;
    for (size_t i = 0; i < rows - 1; ++i) {
        summ += intArr[(i + 1) * cols + i]; // add element from upper diagonal
    }
    if (max_summ < summ) {
        max_summ = summ;
    }

    // Calculate sum of lower diagonal
    summ = 0;
    for (size_t i = 0; i < rows - 1; ++i) {
        summ += intArr[i * cols + (i + 1)]; // add element from lower diagonal
    }
    if (max_summ < summ) {
        max_summ = summ;
    }

    return max_summ;
}
