#include <iostream>
#include "rectangle.h"
#include "parallelogram.h"
#include "triangle.h"
#include "CompositeShape.h"
#include "base-types.h"
#include "shape.h"
#include "printShapes.h"
#include "isoScale.h"

int main()
{
  CompositeShape compositeShape;
  bool correctFigure = false;
  bool correctScale = false;
  bool correctComposite = false;
  std::string figureName = "";
  while (std::cin)
  {
    std::cin >> figureName;
    if (!std::cin)
    {
    //  std::cerr << "ERROR: invalid input\n";
      //correctFigure = false;
      break;
    }//+
    if (figureName == "RECTANGLE" || figureName == "PARALLELOGRAM" || figureName == "TRIANGLE")
    {
      Shape* shape = nullptr;
      try
      {
        if (figureName == "RECTANGLE")
        {
          point_t A{}, B{};
          std::cin >> A.x >> A.y >> B.x >> B.y;
          Shape* shape = new Rectangle(A, B);
          compositeShape.push_back(shape);
          correctFigure = true;
          /*}
          catch (...)
          {
            correctFigure = false;
            std::cerr << "invalid rectangle\n";
          }*/
        }
        else if (figureName == "PARALLELOGRAM")
        {
          /*try
          {*/
          point_t A{}, B{}, C{};
          std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
          Shape* shape = new Parallelogram(A, B, C);
          compositeShape.push_back(shape);
          correctFigure = true;
            /*}
          catch (...)
          {
            correctFigure = false;
            std::cerr << "invalid parallelogram\n";
          }*/
        }
        else if (figureName == "TRIANGLE")
        {
         /* try
          {*/
          point_t A{}, B{}, C{};
          std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
          Shape* shape = new Triangle(A, B, C);
          compositeShape.push_back(shape);
          correctFigure = true;
            /*}
          catch (...)
          {
            correctFigure = false;
            std::cerr << "invalid triangle\n";
          }*/
        }
      }
      catch (const std::invalid_argument& e)
      {
        correctFigure = false;
        //std::cerr << "Invalid figure\n";
      }
      catch (...)
      {
        correctComposite = false;
     //   std::cerr << "Invalid figure\n";
        delete[] shape;
        //break;
      }
      //delete[] shape;
    }
    else if (figureName == "SCALE")
    {
      correctScale = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      point_t pos{ x, y };
      double k = 0.0;
      std::cin >> k;
      if (!std::cin || k < 0)
      {
        correctScale = false;
        //std::cerr << "ERROR: invalid input k\n";
        break;
      }
      printShapes(std::cout, compositeShape);
      std::cout << '\n';
      try
      {
        //compositeShape.scale(k);
        for (size_t i = 0; i < compositeShape.size(); ++i)
        {
          isoScale(compositeShape[i], pos, k);
        }
        correctScale = true;
      }
      catch (...)
      {
        //std::cerr << "invalid scale\n";
        correctScale = false;
      }
      printShapes(std::cout, compositeShape);
      std::cout << '\n';
    }
    else
    {
      correctFigure = true;
     // std::cerr << "ERROR: no such figure\n";
      continue;
    }
  }
  if (!correctFigure)
  {
    std::cerr << "ERROR: invalid figure\n";
    return 1;
  }
  if (!correctScale)
  {
    std::cerr << "ERROR: invalid scaling\n";
    return 1;
  }
  if (!correctComposite)
  {
    std::cerr << "ERROR: invalid composite\n";
  }
  return 0;
}
