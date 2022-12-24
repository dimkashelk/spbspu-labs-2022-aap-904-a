#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

void shiftArray(int *array, int N, int k);
int getPositiveAvg(const int *array, int N);
void printArray(const int *array, int N);
bool inputArray(std::string filename, int* &array, int &N);
void processArray(int *array, int N, int k);
bool inputInteger(std::string msg, int &n);

#endif
