#include <iostream>
#include "shape.h"
#include "make_output.h"
#include "read_correct_figures.h"
#include "isotropic_scale.h"

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
      Shape* rectangle = nullptr;
      try
      {
        rectangle = correctFigures::readCorrectRectangle(std::cin);
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
      Shape* ring = nullptr;
      try
      {
        ring = correctFigures::readCorrectRing(std::cin);
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
      Shape* ellipse = nullptr;
      try
      {
        ellipse = correctFigures::readCorrectEllipse(std::cin);
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
  makeOutput::makeOutputSumm(std::cout, array_figures, size);
  for (size_t i = 0; i < size; i++)
  {
    delete array_figures[i];
  }
  delete[] array_figures;
  return 0;
}
