#ifndef SPBSPU_LABS_2022_AAP_904_A_SCANMATRIX_H
#define SPBSPU_LABS_2022_AAP_904_A_SCANMATRIX_H
#include <iostream>
#include <cstddef>
std::istream& scanSize(std::istream &in_stream, size_t &n, size_t &m);
std::istream& scanMatrix(int *matrix, std::istream &in_stream, size_t n, size_t m);
#endif
