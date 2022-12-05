#include <iostream>
#include <fstream>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrect amount of command line args\n";
    return 2;
  }
  if (argv[1] != 1 || argv[1] != 2)
  {
    std::cerr << "Incorrect variant of task\n";
    return 2;
  }

  std::fstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Error while reading\n";
    return 1;
  }
  size_t rows = 0;
  input >> rows;
  if (!input)
  {
    std::cerr << "Error while reading rows\n";
    return 1;
  }
  size_t columns = 0;
  input >> columns;
  if (!input)
  {
    std::cerr << "Error while reading columns\n";
    return 1;
  }
  size_t size = rows * columns;

  if (argv[1] == 1)
  {
    constexpr size_t max_size = 1000;
    if (size > max_size)
    {
      std::cerr << "Too much elements\n";
      return 1;
    }
    int arr[max_size];
    for (size_t i = 0; i < size; ++i)
    {
      input >> arr[i];
      if (!input)
      {
        std::cerr << "Error while reading elements\n";
        return 1;
      }
    }
  }
  else if (argv[1] == 2)
  {
    int * arr = new int[rows*columns];
    delete [] arr;
  }
}
