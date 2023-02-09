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
  size_t i = 0;
  char ind[3] = {0};
  size_t mx[3] = {0};

  while (src[i] != '\0') {
    char curr = src[i];
    bool isUnique = true;
    for (size_t j = 0; j < i; ++j) {
      if (src[j] == curr) {
        isUnique = false;
        break;
      }
    }
    if (!isUnique) {
      i++;
      continue;
    }
    i++;
    size_t j = i;
    size_t cnt = 1;

    while (src[j] != '\0') {
      if (src[j] == curr) {
        cnt++;
      }
      j++;
    }

    size_t mnInd = minIndex(mx, 3);
    if (cnt > mx[mnInd]) {
      mx[mnInd] = cnt;
      ind[mnInd] = curr;
      while (true) {
        if (mnInd < 2 && curr > ind[++mnInd]) {
          std::swap(mx[mnInd], mx[mnInd - 1]);
          std::swap(ind[mnInd], ind[mnInd - 1]);
        } else if (mnInd > 0 && curr < ind[--mnInd]) {
          std::swap(mx[mnInd], mx[mnInd + 1]);
          std::swap(ind[mnInd], ind[mnInd + 1]);
        } else {
          break;
        }
      }
    }
  }

  unsigned short shift = 0;
  for (i = 0; i < 3; ++i) {
    if (mx[i] == 0) {
      shift++;
      continue;
    }
    dest[i - shift] = ind[i];
  }
  dest[i - shift] = '\0';
}
