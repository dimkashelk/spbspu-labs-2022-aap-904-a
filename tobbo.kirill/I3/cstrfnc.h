#ifndef CSTRFNC_H
#define CSTRFNC_H
#include <cstddef>
#include <iostream>

char* getCString(std::istream& stream);
size_t strLength(const char* str);

bool isIntersectedStrings(char* str1, char* str2);
char* removeLatinVowelSymbols(char* destination, const char* source);

#endif
