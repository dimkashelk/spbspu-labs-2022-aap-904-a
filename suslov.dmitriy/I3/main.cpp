#include <iostream>
#include "formNewStringVarFiveteen.h"
#include "formNewStringVarFive.h"
int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  if (size > 0)
  {
    cstring[size - 1] = '\0';
  }
  if (size == 0 or size == 1)
  {
    std::cerr << "Empty input" << '\n';
    delete[] cstring;
    return 2;
  }
  size_t capacity2 = 10;
  char *cstring2 = new char[capacity2];
  size_t size2 = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size2 == capacity2)
    {
      try
      {
        char *newstr = new char[capacity2 + 20];
        for (auto i = cstring2, j = newstr; i != cstring2 + size2; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring2;
        cstring2 = newstr;
        capacity2 += 20;
      }
      catch (...)
      {
        delete[] cstring2;
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring2[size2];
  } while (std::cin && cstring2[size2++] != '\n');
  if (size2 > 0)
  {
    cstring2[size2 - 1] = '\0';
  }
  if (size2 == 0)
  {
    cstring2[0] = '\0';
  }
  char *result1;
  try
  {
    result1 = new char[size + size2 + 1];
  } catch (std::bad_alloc &e)
  {
    std::cerr << "Fail" << "\n";
    return 3;
  }
  std::cout << varFiveFunction(result1, cstring, cstring2) << "\n";
  delete[] result1;
  char *result2;
  try
  {
    result2 = new char[size + 1];
  } catch (std::bad_alloc &e)
  {
    std::cerr << "Fail" << "\n";
    return 3;
  }
  std::cout << varFiveteenFunction(result2, cstring, cstring2) << "\n";
  delete[] result2;
  delete[] cstring;
  delete[] cstring2;
  return 0;
}
