#ifndef STRINGOPERATIONS_H
#define STRINGOPERATIONS_H
#include <iostream>

char* inputString(std::istream& stream, size_t& size);
void switchCase(const char* src, char* dest);
void threeMostCommon(const char* src, char* dest);

#endif //STRINGOPERATIONS_H
