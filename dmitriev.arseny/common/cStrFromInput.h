#ifndef CSTRFROMINPUT_H
#define CSTRFROMINPUT_H

#include <cstddef>
#include <istream>

char* createCStrFromInput(char* cStr, size_t& size, size_t& capacity, std::istream& inp);

#endif
