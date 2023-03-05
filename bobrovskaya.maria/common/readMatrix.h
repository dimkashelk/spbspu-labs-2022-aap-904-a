#ifndef I4_READMATRIX_H
#define I4_READMATRIX_H
#include <cstddef>
#include <fstream>

int* readMatrixFromFile(int* matrix, const size_t size, std::ifstream& inputFile);

#endif
