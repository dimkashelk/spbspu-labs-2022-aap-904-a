#ifndef I4_COUNTARRAYS_H
#define I4_COUNTARRAYS_H
#include <cstddef>
size_t countDiverseElements(const int *array, size_t rows, size_t columns);
size_t countEqualSum(const int *array, size_t rows, size_t columns);
size_t countSuccessionEqualElements(const int *matrix, size_t matrixN);
int countUpperMainDiagonal(const int *matrix, size_t matrixN);
void smoothMatrix(const int *matrix, int *smoothedMatrix, size_t matrixN);
#endif
