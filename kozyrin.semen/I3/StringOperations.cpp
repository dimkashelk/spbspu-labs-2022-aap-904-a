#include "StringOperations.h"

char* inputString(std::istream& stream, size_t& size)
{
  stream >> std::noskipws;
  size_t capacity = 20;
  char* str = new char[capacity];

  while (str[size - 1] != '\n') {
    if (size == capacity) {
      capacity += 20;
      char* temp = new char[capacity];
      for (size_t i = 0; i < size; ++i) {
        temp[i] = str[i];
      }
      delete[] str;
      str = temp;
    }
    stream >> str[size];
    size++;
  }
  str[size - 1] = '\0';
  return str;
}

void switchCase(const char* src, char* dest)
{
  size_t i = 0;
  while (src[i] != '\0') {
    if (src[i] >= 65 && src[i] <= 90) {
      dest[i] = src[i] + 32;
    }
    else if (src[i] >= 97 && src[i] <= 122) {
      dest[i] = src[i] - 32;
    }
    else {
      dest[i] = src[i];
    }
    i++;
  }
  dest[i] = '\0';
}


