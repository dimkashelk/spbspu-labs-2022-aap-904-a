#include "workWithIO.h"
#include "getMostCommonSyms.h"

int main()
{
  const char* const input_str = stdinGetLine();

  char* most_common_syms;

  try
  {
    most_common_syms = new char[4];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }

  std::cout << getMostCommonSyms(most_common_syms, input_str) << '\n';

  delete[] input_str;
  delete[] most_common_syms;

  return 0;
}
