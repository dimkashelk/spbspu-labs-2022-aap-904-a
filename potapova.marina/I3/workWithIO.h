#ifndef WORKWITHIO_H
#define WORKWITHIO_H

#include <iostream>
#include "workWithStrs.h"

char* getLineFromFile(size_t* result_size_ptr = nullptr, std::istream& in = std::cin);

#endif
