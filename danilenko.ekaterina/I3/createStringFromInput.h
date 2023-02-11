#ifndef CREATESTRINGFROMINPUT_H
#define CREATESTRINGFROMINPUT_H

#include <cstddef>
#include <istream>

char* createStringFromInput(std::istream& input, size_t size, size_t capacity);

#endif
