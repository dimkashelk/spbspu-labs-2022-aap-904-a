#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "ring.h"

int main()
{
  std::string name = "";
  double x = 0.0;
  double y = 0.0;
  std::cin >> name >> x >> y;
  if (!std::cin)
  {
    std::cerr << "Error: wrong input";
    return 1;
  }
  if (name == "RECTANGLE")
  {
    Shape* rectangle = new Rectangle();
  }
  else if (name == "RING")
  {
    Shape* ring = new Ring();
  }
  else if (name == "Ellipse")
  {
    Shape* ellipse = new Ellipse();
  }
  else
  {
    std::cerr << "Error: wrong name of the figure";
	return 1;
  }
  return 0;
}
