#include <iostream>
#include "expandcstring.h"
#include "deleteextraspaces.h"

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do {
    if (size == capacity) {
      try {
        cstring = expandCString(cstring, size, capacity);
      }
      catch (const std::exception &e) {
        delete [] cstring;
        std::cerr << e.what() << "\n";
        return 2;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == "\0" || cstring[0] == '\n') {
    std::cerr << "Error while reading\n";
    delete [] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  char *task1 = new char [size];
  task1[0] = '\0';
  deleteExtraSpaces(task1, cstring);
  std::cout << task1 << "\n";
  delete [] task1;
  delete [] cstring;
}
