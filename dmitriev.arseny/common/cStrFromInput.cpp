#include "cStrFromInput.h"
#include "string.h"

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
      cStr[size] = '\0';
      dupStr = strcpy(dupStr, cStr);
      delete[] cStr;
      cStr = dupStr;
      dupStr = nullptr;
    }
    cStr[size++] = chInp;
  }

  cStr[size] = '\0';

  return cStr;
}
