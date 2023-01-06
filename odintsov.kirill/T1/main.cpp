#include <iostream>
#include "processInput.hpp"
#include "compositeshape.hpp"

int main()
{
  odintsov::CompositeShape composite;
  processInput(std::cin, std::cout, composite);
}
