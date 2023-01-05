#ifndef CSTRFNC_H
#define CSTRFNC_H
#include <cstddef>
#include <iostream>

std::pair< char*, size_t > getCString(std::istream& stream);

#endif
