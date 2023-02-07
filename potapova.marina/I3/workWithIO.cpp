#include "workWithIO.h"

void inputStr(size_t& size, char*& str, const char* const file_name)
{
  std::ifstream in(file_name);

  if (!in.is_open())
  {
    std::cerr << "Can't open " << file_name << '\n';
    std::exit(1);
  }

  if (!(in >> size))
  {
    std::cerr << "Input error\n";
    std::exit(1);
  }

  try
  {
    str = new char[size + 1];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Allocation failed: " << e.what() << '\n';
    std::exit(1);
  }

  if (!(in >> str))
  {
    std::cerr << "Input error\n";
    std::exit(1);
  }
}

void printAnswer(char* ans, const char* const file_name)
{
  std::ofstream out(file_name);

  if (!out.is_open())
  {
    std::cerr << "Can't open " << file_name << '\n';
    std::exit(1);
  }

  out << ans << '\n';
}
