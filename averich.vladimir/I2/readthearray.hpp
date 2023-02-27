#ifndef READTHEARRAY_HPP
#define READTHEARRAY_HPP
#include <fstream>
#include <cstddef>
int* readTheArray(std::istream& in, size_t& sizeOfFileArray, int* fileArray, const size_t maxSize);
#endif
