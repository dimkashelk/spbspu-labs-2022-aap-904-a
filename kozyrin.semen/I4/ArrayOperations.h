#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H
#include <cstddef>
#include <iostream>
#include <fstream>

void inputArray(int* arr, size_t size, std::istream& stream = std::cin);
size_t sortedRowsCount(const int* arr, size_t rows, size_t cols);
bool isTriangular(const int* arr, size_t rows, size_t cols);

#endif //ARRAYOPERATIONS_H
