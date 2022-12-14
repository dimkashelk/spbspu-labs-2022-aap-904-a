#include <iostream>
#include <cstddef>
#include "defCountDiffLett.h"
#include "createMassAllLettStrs.h"

int main()
{
  size_t capacity = 10;
  size_t size1 = 0;
  char* cStr1 = new char[capacity];
  char inp;

  std::cin >> std::noskipws;

  for (std::cin >> inp; (std::cin && inp) && (inp != '\n'); std::cin >> inp)
  {
    if (size1 == capacity)
    {
      capacity = capacity + 10;
      try
      {
        char* dupStr = new char[capacity];
        for (size_t i = 0; i < size1; i++)
        {
          dupStr[i] = cStr1[i];
        }
        delete[] cStr1;
        cStr1 = new char[capacity];
        cStr1 = dupStr;
        dupStr = nullptr;
      }
      catch (const std::bad_alloc& e)
      {
        std::cout << e.what() << '\n';
        delete[] cStr1;
        return 1;
      }
    }
    cStr1[size1++] = inp;
  }

  if ((inp == '\n') && (size1 == 0))
  {
    std::cerr << "Empty string" << '\n';
    delete[] cStr1;
    return 1;
  }

  cStr1[size1] = '\0';

  char* cStrAllLett = new char[27];
  char cStr2[] = "az";

  cStrAllLett = createMassAllLettStrs(cStrAllLett, cStr1, cStr2);
  std::cout << cStrAllLett << '\n';

  std::cout << defCountDiffLett(cStr1) << '\n';

  delete[] cStr1;
  delete[] cStrAllLett;

  return 0;
}