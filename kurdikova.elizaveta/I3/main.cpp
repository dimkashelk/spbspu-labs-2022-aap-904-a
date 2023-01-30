#include <iostream>
#include "DeleteVowelLetters.h"
#include "TakeSimilarLettersInOrder.h"

int main() {
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do {
    if (size == capacity) {
      try {
        char *newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; i++, j++) {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...) {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  cstring[size - 1] = '\0';

  size_t size2 = 20;
  char *cstring2 = new char[size2];
  size_t index = 0;
  for (char i : {'G', 'o', 'o', 'd', 'm', 'o', 'r', 'n', 'i', 'n', 'g', '!', '\0'}) {
    cstring2[index++] = i;
  }

  char *cstringWithoutVowels = new char[size];
  deleteVowels(cstringWithoutVowels, cstring);

  size_t sizeArraySimLet = 26;
  char *arraySimilarLetters = new char[sizeArraySimLet];
  lettersInOrder(arraySimilarLetters, cstring, cstring2);

  std::cout << "Array without vowel letters: ";
  for (size_t i = 0; i < size; i++) {
    std::cout << cstringWithoutVowels[i] << " ";
  }
  std::cout << "\n" << "Similar letters in two arrays: ";
  for (size_t i = 0; i < sizeArraySimLet; i++) {
    std::cout << arraySimilarLetters[i] << " ";
  }

  delete[] cstring;
  delete[] cstring2;
  delete[] cstringWithoutVowels;
  delete[] arraySimilarLetters;
  return 0;
}
