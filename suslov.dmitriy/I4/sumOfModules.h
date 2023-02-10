#ifndef SUMOFMODULES_H
#define SUMOFMODULES_H
#include <iostream>
int *scanMatrixTwo(std::istream& in_stream, size_t &n, size_t &m);
int *smoothedMatrix(int *matrix, size_t n, size_t m);
int sum(int *matrix, size_t n, size_t m);
#endif
