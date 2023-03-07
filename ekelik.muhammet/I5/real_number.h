#ifndef REAL_NUMBER_H
#define REAL_NUMBER_H

#include <cstddef>

bool UnsignedInteger(const char* data, size_t& shift);
bool Sign(const char* data, size_t& shift);
bool Mantissa(const char* data, size_t& shift);
bool InOrder(const char* data, size_t& shift);
bool RealNumber(const char* data);

#endif
