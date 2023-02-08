#include "StringOperations.h"
#include <cctype>

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
    if (std::isalpha(src[i])) {
      std::islower(src[i]) ? dest[i] = std::toupper(src[i]) : dest[i] = std::tolower(src[i]);
    } else {
      dest[i] = src[i];
    }
    i++;
  }
  dest[i] = '\0';
}

size_t minIndex(const size_t* arr, size_t size)
{
  size_t mn = arr[0];
  size_t ind = 0;
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] < mn) {
      mn = arr[i];
      ind = i;
    }
  }
  return ind;
}

void threeMostCommon(const char* src, char* dest)
{
  size_t dict[94]{0};
  unsigned short i = 0;

  while (src[i] != '\0') {
    dict[src[i] - 32]++;
    i++;
  }

  unsigned short ind[3] = {0};
  size_t mx[3] = {0};

  for (i = 0; i < 94; ++i) {
    size_t mnInd = minIndex(mx, 3);
    if (dict[i] > mx[mnInd]) {
      for (unsigned short n = mnInd; n < 3; ++n) {
        mx[n] = mx[n + 1];
        ind[n] = ind[n + 1];
      }
      mx[2] = dict[i];
      ind[2] = i;
    }
  }

  unsigned short shift = 0;
  for (i = 0; i < 3; ++i) {
    if (mx[i] == 0) {
      shift++;
      continue;
    }
    dest[i - shift] = ind[i] + 32;
  }
  dest[i - shift] = '\0';
}
