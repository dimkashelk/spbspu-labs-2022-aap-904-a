#include <iostream>

int main()
{
  size_t capacity1 = 10;
  char* cstring1 = new char[capacity1];
  cstring1[0] = '\0';
  try
  {
    cstring1 = inputString(cstring1, capacity1, std::cin);
    if (cstring1[0] == '\0')
    {
      std::cout << "ERROR: empty string";
      delete[] cstring1;
      return 1;
    }
    cstring1[capacity1 - 1] = '\0';
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    delete[] cstring1;
    return 1;
  }
}
