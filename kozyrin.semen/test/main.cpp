#include <iostream>

void taskOne(int a, int b)
{
  std::cout << " - " << a * b;
}

void taskTwo(int a, int b)
{
  std::cout << " - " << a + b;
}

int main(int argc, char* argv[])
{
  int a = 3;
  int b = argc;
  int c = argv[1][0] - 49;
  std::cout << c;

  void (*choose[2])(int a, int b) = {taskOne, taskTwo};
  choose[c](a, b);
}
