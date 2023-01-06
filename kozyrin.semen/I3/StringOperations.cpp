#include "StringOperations.h"
#include <algorithm>

size_t minIndex(const int* arr, size_t size) {
  int mn = arr[0];
  size_t ind = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] < mn) {
      mn = arr[i];
      ind = i;
    }
  }
  return ind;
}

char* inputString(std::istream& stream, size_t& size)
{
  stream >> std::noskipws;
  size_t capacity = 20;
  size = 0;
  char* str = new char[capacity]{0};

  do {
    if (size + 1 == capacity) {
      capacity += 20;
      char* temp = new char[capacity]{0};
      for (size_t i = 0; i <= size; ++i) {
        temp[i] = str[i];
      }
      delete[] str;
      str = temp;
    }
    stream >> str[size];
  } while(str[size++] != '\n' && stream);

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

void threeMostCommon(const char* src, char* dest)
{
  int dict[94]{0};
  int i = 0;

  while (src[i] != '\0') {
    dict[src[i] - 32]++;
    i++;
  }

  int ind[3] = {127, 127, 127};
  int mx[3] = {0};

  for (i = 0; i < 94; ++i) {
    size_t min_ind = minIndex(mx, 3);
    if (dict[i] > mx[min_ind]) {
      mx[min_ind] = dict[i];
      ind[min_ind] = i;
    }
  }

  std::sort(ind, ind + 3);
  for (i = 0; i < 3; ++i) {
    if (ind[i] == 127) {
      break;
    }
    dest[i] = char(ind[i] + 32);
  }
  dest[i] = '\0';
}
