#include <iostream>
#include "shape.h"
#include "workWithArray.h"
#include "rectangle.h"
#include "concave.h"

int main()
{
  bool badShape = false;
  bool isScale = false;
  size_t size = 0;
  std::string figureName = "";
  Shape **shapes = new Shape*[size];
  while (std::cin) {
    std::cin >> figureName;
    if (figureName == "RECTANGLE") {
      try {
        point_t point1, point2;
        std::cin >> point1.x >> point1.y >> point2.x >> point2.y;
        expandArray(shapes, size);
        shapes[size] = new Rectangle(point1, point2);
        size++;
      }
      catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        badShape = true;
      }
      catch (...) {
        std::cerr << "Error with rectangle\n";
        deleteArray(shapes, size);
        return 2;
      }
    }
    if (figureName == "CONCAVE") {
      try {
        point_t point1, point2, point3, point4;
        std::cin >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y >> point4.x >> point4.y;
        expandArray(shapes, size);
        shapes[size] = new Concave(point1, point2, point3, point4);
        size++;
      }
      catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        badShape = true;
      }
      catch (...) {
        std::cerr << "Error with rectangle\n";
        deleteArray(shapes, size);
        return 2;
      }
    }
  }
}
