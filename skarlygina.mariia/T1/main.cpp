#include <iostream>
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
    return 0;
  }
  else if (name == "RING")
  {
    return 0;
  }
  else if (name == "Ellipse")
  {
    return 0;
  }
  else
  {
    std::cerr << "Error: wrong name of the figure";
	return 1;
  }
  return 0;
}
