#include "cStrFtomInput.h"
#include <cstring>

char* createCStrFromInput(char* cStr, size_t& size, size_t& capacity, std::istream& inp)
{
  char chInp = '\0';
  inp >> std::noskipws;

  for (inp >> chInp; (inp && chInp) && (chInp != '\n'); inp >> chInp)
  {
    if (size == capacity)
    {
      capacity = capacity + 10;
      char* dupStr = new char[capacity];
      dupStr = strcpy(dupStr, cStr);
      delete[] cStr;
      cStr = dupStr;
      dupStr = nullptr;
    }
    cStr[size++] = chInp;
  }

  return cStr;
}
