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
  size_t capacity = 10;
  double sumArea = 0.0;
  point_t zoomCenter = {0, 0};
  double ratio = 0.0;
  bool isAdded = false;
  std::string figureName = "";
  Shape **shapes = new Shape*[capacity];
  while (std::cin) {
    std::cin >> figureName;
    try {
      if (size == capacity) {
        expandArray(shapes, capacity);
        Shape **newShapes = expandArray(shapes, capacity);
        delete [] shapes;
        shapes = newShapes;
      }
      if (figureName == "RECTANGLE") {
        point_t point1, point2;
        std::cin >> point1.x >> point1.y >> point2.x >> point2.y;
        if (!std::cin) {
          std::cerr << "Error while reading";
          continue;
        }
        shapes[size] = new Rectangle(point1, point2);
        isAdded = true;
      }
      if (figureName == "CONCAVE") {
        point_t point1, point2, point3, point4;
        std::cin >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y >> point4.x >> point4.y;
        if (!std::cin) {
          std::cerr << "Error while reading";
          continue;
        }
        shapes[size] = new Concave(point1, point2, point3, point4);
        isAdded = true;
      }
      if (figureName == "COMPLEXQUAD") {
        point_t point1, point2, point3, point4;
        std::cin >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y >> point4.x >> point4.y;
        if (!std::cin) {
          std::cerr << "Error while reading";
          continue;
        }
        shapes[size] = new Complexquad(point1, point2, point3, point4);
        isAdded = true;
      }
      if (isAdded) {
        sumArea += shapes[size]->getArea();
        size++;
        isAdded = false;
      }
      if (figureName == "SCALE") {
        std::cin >> zoomCenter.x >> zoomCenter.y >> ratio;
        if (!std::cin) {
          std::cerr << "Error while reading";
          break;
        }
        if (size > 0) {
          isScale = true;
        }
        break;
      }
    }
    catch (const std::invalid_argument &e) {
      std::cerr << e.what();
    }
    catch (...) {
      std::cerr << "Error while work with figures";
      deleteArray(shapes, size);
      return 2;
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
        std::cerr << e.what();
        deleteArray(shapes, size);
        return 2;
      }
      sumArea += shapes[i]->getArea();
    }
    std::cout << std::fixed << std::setprecision(1) << sumArea << " ";
    for (size_t i = 0; i < size; i++) {
      leftBottomX = shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2;
      leftBottomY = shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2;
      rightTopX = shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2;
      rightTopY = shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
      std::cout << std::fixed << std::setprecision(1) << leftBottomX << " " << leftBottomY << " " << rightTopX << " " << rightTopY << " ";
    }
    deleteArray(shapes, size);
  } else {
    std::cerr << "No scale?";
    deleteArray(shapes, size);
    return 2;
  }
}
