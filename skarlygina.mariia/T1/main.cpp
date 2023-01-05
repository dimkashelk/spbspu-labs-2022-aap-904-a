#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "ring.h"

int main()
{
  std::string figure = "";
  size_t size = 0;
  Shape** array_figures = new Shape* [7];
  do
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      point_t left_down_point{}, right_up_point{};
      Shape* rectangle = nullptr;
      try
      {
        std::cin >> left_down_point.x >> left_down_point.y >> right_up_point.x >> right_up_point.y;
        rectangle = new Rectangle(left_down_point, right_up_point);
        array_figures[size] = rectangle;
        size++;
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        delete rectangle;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error while reading the rectangle\n";
        return 2;
      }
    }

    if (figure == "RING")
    {
      point_t center{};
      double radius_small, radius_big;
      Shape* ring = nullptr;
      try
      {
        std::cin >> center.x >> center.y >> radius_small >> radius_big;
        ring = new Ring(center, radius_small, radius_big);
        array_figures[size] = ring;
        size++;
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        delete ring;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error while reading the ring\n";
        return 2;
      }
    }

    if (figure == "ELLIPSE")
    {
      double radius_vertical, radius_horizontal;
      point_t center;
      Shape* ellipse = nullptr;
      try
      {
        std::cin >> center.x >> center.y >> radius_vertical >> radius_horizontal;
        ellipse = new Ellipse(center, radius_vertical, radius_horizontal);
        array_figures[size] = ellipse;
        size++;
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        delete ellipse;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error while reading the ellipse\n";
        return 2;
      }
    }

    if (figure == "SCALE")
    {
      point_t point{};
      double coefficient = 0;
      try
      {
        std::cin >> point.x >> point.y >> coefficient;
        if (coefficient <= 0)
        {
          std::cerr << "Error: coefficient could not be under zero\n";
          return 2;
        }
      }
      catch (...)
      {
        std::cerr << "Error: wrong parameters of the point, coefficient\n";
        for (size_t i = 0; i < size; i++)
        {
          delete array_figures[i];
        }
        delete[] array_figures;
        return 2;
      }
      break;
    }
  }
  while (std::cin);
  for (size_t i = 0; i < size; i++)
  {
    delete array_figures[i];
  }
  delete[] array_figures;
  return 0;
}
