#ifndef READMATRIX_H
#define READMATRIX_H
#include <fstream>

int* readMatrixFromFile(int* matrix, const size_t rows, const size_t columns, std::ifstream& inputFile);
#endif
