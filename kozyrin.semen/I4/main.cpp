#include <iostream>
#include <fstream>

void taskOne(std::ifstream& fin, std::ofstream& fout)
{
}

void taskTwo(std::ifstream& fin, std::ofstream& fout)
{
}

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "Incorrect amount of arguments";
    return 1;
  }
  std::ifstream fin(argv[2]);
  if (!fin.is_open()) {
    std::cerr << "Input file could not be opened";
    return 2;
  }
  std::ofstream fout(argv[2]);
  if (!fin.is_open()) {
    std::cerr << "output file could not be opened";
    return 2;
  }

  void (*choose[2])(std::ifstream& fin, std::ofstream& fout) = {taskOne, taskTwo};
  choose[argv[1][0] - 49](fin, fout);
}
