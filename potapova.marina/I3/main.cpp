#include "workWithIO.h"
#include "getMostCommonSyms.h"

int main()
{
  const char* input_str;
  try
  {
    input_str = getLineFromFile();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    return 1;
  }
  if (input_str == nullptr)
  {
    std::cerr << "Empty input\n";
    return 1;
  }
  char most_common_syms[4];
  std::cout << getMostCommonSyms(most_common_syms, input_str) << '\n';
  delete[] input_str;
  return 0;
}
