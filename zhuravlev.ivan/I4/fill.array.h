#ifndef INC_4_FILL_ARRAY_H
#define INC_4_FILL_ARRAY_H
#include <fstream>
#include <cstddef>

void fillDynArray(int array_for_filling, size_t nRows, size_t nColomns, std::ifstream& input);
void fillIntegratedArray(int *arr, size_t nRow, size_t nColomn, std::ifstream& input);
#endif
