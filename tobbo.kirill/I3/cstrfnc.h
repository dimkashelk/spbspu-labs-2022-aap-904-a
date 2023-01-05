#ifndef CSTRFNC_H
#define CSTRFNC_H
#include <cstddef>
#include <iostream>

std::pair< char*, size_t > getCString(std::istream& stream);
bool isIntersectedStrings(const char* str1, const char* str2);
char* removeLatinVowelSymbols(char* destination, const char* source);

#endif
