#ifndef ARRAYS_H
#define ARRAYS_H
#include <fstream>
#include <iostream>

void fillArray(int* arr, size_t rows, size_t cols, std::ifstream* in);
size_t getPositiveRowsCount(int* arr, size_t rows, size_t cols);
int getMaxSumDiag(int* arr, size_t size);

#endif
