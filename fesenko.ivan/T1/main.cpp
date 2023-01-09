#include <iostream>
#include <iomanip>
#include "shape.h"
#include "workWithArray.h"
#include "rectangle.h"
#include "concave.h"
#include "complexquad.h"
#include "supportFunctions.h"

int main()
{
  bool isScale = false;
  size_t size = 0;
  double sumArea = 0.0;
  point_t zoomCenter = {0, 0};
  double ratio = 0.0;
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
      }
      catch (...) {
        std::cerr << "Error while work with complexquad\n";
        deleteArray(shapes, size);
        return 2;
      }
    }
    if (figureName == "SCALE") {
      try {
        std::cin >> zoomCenter.x >> zoomCenter.y >> ratio;
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
    double leftBottomX = 0.0;
    double leftBottomY = 0.0;
    double rightTopX = 0.0;
    double rightTopY = 0.0;
    std::cout << std::fixed << std::setprecision(1) << sumArea << " ";
    sumArea = 0.0;
    for (size_t i = 0; i < size; i++) {
      leftBottomX = shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2;
      leftBottomY = shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2;
      rightTopX = shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2;
      rightTopY = shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
      std::cout << std::fixed << std::setprecision(1) << leftBottomX << " " << leftBottomY << " " << rightTopX << " " << rightTopY;
      if (i == size - 1) {
        std::cout << "\n";
      } else {
        std::cout << " ";
      }
      try {
        fullScale(shapes[i], zoomCenter, ratio);
      }
      catch (const std::invalid_argument &e) {
        std::cerr << e.what() << "\n";
      }
      sumArea += shapes[i]->getArea();
    }
    std::cout << std::fixed << std::setprecision(1) << sumArea << " ";
    for (size_t i = 0; i < size; i++) {
      leftBottomX = shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2;
      leftBottomY = shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2;
      rightTopX = shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2;
      rightTopY = shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
      std::cout << std::fixed << std::setprecision(1) << leftBottomX << " " << leftBottomY << " " << rightTopX << " " << rightTopY;
      if (i == size - 1) {
        std::cout << "\n";
      } else {
        std::cout << " ";
      }
    }
    deleteArray(shapes, size);
  } else {
    std::cerr << "No scale?\n";
    deleteArray(shapes, size);
    return 2;
  }
}
