#include <iostream>
#include <string>
#include <cstddef>
#include <iomanip>
#include <stdexcept>
#include "inputrectangle.h"
#include "compositeshape.h"
#include "inputtriangle.h"
#include "inputcomplexquad.h"

int main()
{
  std::string line;
  CompositeShape rhs;
  bool wrongfigure = false;
  while(std::cin)
  {
    if (wrongfigure)
    {
      wrongfigure = false;
      std::cerr << "error";
    }
    std::string name = "";
    std::cin >> name;
    if (name == "RECTANGLE")
    {
      try
      {
        shape *shape = inputRectangle(std::cin);
        rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        wrongfigure = true;
      }
    }
    else if (name == "TRIANGLE")
    {
      try
      {
        shape *shape = inputTriangle(std::cin);
        rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        wrongfigure = true;
      }
    }
    else if (name == "COMPLEXQUAD")
    {
      try
      {
      shape *shape = inputComplexquad(std::cin);
      rhs.push_back(shape);
      }
      catch(const std::logic_error &e)
      {
        wrongfigure = true;
      }
    }
    else
    {
      std::cerr << "not a figure";
    }
  }
}
