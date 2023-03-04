#include </Users/ivanzhuravlev/CLionProjects/spbspu-labs-2022-aap-904-a/zhuravlev.ivan/common/make_string.h>
#include <iostream>

int main()
{
  char* cstring = nullptr;
  try
  {
    cstring = makeCstring(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  return 0;
}

