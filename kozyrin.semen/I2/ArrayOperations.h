#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H
#include <cstddef>
#include <iostream>

void printArray(std::ostream& stream, const int* arr, size_t size);
void randomizeArray(int* arr, size_t size);
void shiftByIndexes(int* arr, size_t size, size_t n, size_t m);
const int* maxEven(const int* arr, size_t size);

#endif
