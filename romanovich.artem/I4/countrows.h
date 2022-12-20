#ifndef I4_COUNTROWS_H
#define I4_COUNTROWS_H
#include <cstddef>
size_t countDiverseElements(const int *array, size_t rows, size_t columns);
size_t countEqualSum(const int *array, size_t rows, size_t columns);
size_t countSuccessionEqualElements(const int *matrix, size_t matrixSize);
const int smoothMatrix(const int *matrix, size_t matrixSize);
int sumClose(const int *matrix, size_t row, size_t column, size_t matrixSize);
#endif
