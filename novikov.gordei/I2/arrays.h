#ifndef ARRAYS_H
#define ARRAYS_H

#include <string>

void shiftArray(int* array, size_t N, size_t k);
int getPositiveAvg(const int* array, size_t N);
std::ostream& printArray(std::ostream& out, const int* array, size_t N);
std::istream& inputArray(std::istream& in, int** array, size_t& N);
void processArray(int* array, size_t N, size_t k);

#endif
