#include <iostream>

int main()
{
  size_t size = 0;
  size_t capacity = 10;
  char* cstr = new char[capacity];
  std::cin >> std::noskipws;
  do {
    if (size == capacity) {
      try {
        char* newstr = new char[capacity + 20];
        for (auto i = newstr, j = cstr; j != cstr + size; i++, j++) {
          *i = *j;
        }
        delete [] cstr;
        cstr = newstr;
        capacity += 20;
      } catch (...) {
         delete [] cstr;
         return 1;
      }
    }
    std::cin >> cstr[size];
  } while (std::cin && cstr[size++] != '\n');
  cstr[size - 1] = '\0';
  std::cout << cstr << '\n';
  delete [] cstr;
}
