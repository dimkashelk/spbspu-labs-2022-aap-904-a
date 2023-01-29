#include <iostream>

int main() {
  size_t capasity = 10;
  char * cstring = new char[capasity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do {
    if (size == capasity) {
      try {
        char * newstr = new char[capasity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j) {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capasity += 20;
      } catch {
        
      }
      delete [] cstring;
      return 1;
    }
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  cstring[size - 1] = '\0';

  std::cout << cstring << "\n";
  delete [] cstring;
}
