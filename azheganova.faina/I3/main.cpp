#include <iostream>
#include <cstddef>
#include <inputstring.h>
#include "countdifferentletters.h"
#include "findrepeatedsymbols.h"

int main()
{
  char *cstring = inputString(std::cin);
  std::cout << cstring << "\n";
  std::cout << countDifferentLetters(cstring) << '\n';
  std::cout << findRepeatedSymbols(cstring) << '\n';
  delete [] cstring;
}
