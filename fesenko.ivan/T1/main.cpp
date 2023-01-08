#include <iostream>
#include <iomanip>
#include "shape.h"
#include "workWithArray.h"
#include "rectangle.h"
#include "concave.h"
#include "complexquad.h"

int main()
{
  bool badShape = false;
  bool isScale = false;
  size_t size = 0;
  double sumArea = 0.0;
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
        sumArea += shapes[size]->getArea();
        size++;
      }
      catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        badShape = true;
      }
      catch (...) {
        std::cerr << "Error while work with rectangle\n";
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
        sumArea += shapes[size]->getArea();
        size++;
      }
      catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        badShape = true;
      }
      catch (...) {
        std::cerr << "Error while work with concave\n";
        deleteArray(shapes, size);
        return 2;
      }
    }
    if (figureName == "COMPLEXQUAD") {
      try {
        point_t point1, point2, point3, point4;
        std::cin >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y >> point4.x >> point4.y;
        expandArray(shapes, size);
        shapes[size] = new Complexquad(point1, point2, point3, point4);
        sumArea += shapes[size]->getArea();
        size++;
      }
      catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
        badShape = true;
      }
      catch (...) {
        std::cerr << "Error while work with complexquad\n";
        deleteArray(shapes, size);
        return 2;
      }
    }
    if (figureName == "SCALE") {
      try {
        point_t center;
        double ratio;
        std::cin >> center.x >> center.y >> ratio;
        if (size > 0) {
          isScale = true;
        }
      }
      catch (...) {
        std::cerr << "Error while work with scale\n";
        deleteArray(shapes, size);
        return 2;
      }
      break;
    }
  }
  if (isScale) {
    if (badShape) {
      std::cerr << "Incorrect shape\n";
    }
    double leftBottomX = 0.0;
    double leftBottomY = 0.0;
    double rightTopX = 0.0;
    double rightTopY = 0.0;
    std::cout << std::fixed << std::setprecision(1) << sumArea << " ";
    for (size_t i = 0; i < size; i++) {
      leftBottomX = shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2;
      leftBottomY = shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2;
      rightTopX = shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2;
      rightTopY = shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
      std::cout << std::fixed << std::setprecision(1) << leftBottomX << " " << leftBottomY << " " << rightTopX << " " << rightTopY << " ";
    }
    std::cout << "\n";
  } else {
    std::cerr << "No scale?\n";
    deleteArray(shapes, size);
    return 2;
  }
}
