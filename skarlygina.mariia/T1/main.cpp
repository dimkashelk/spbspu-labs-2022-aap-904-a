#include <iostream>
#include "shape.h"
#include "make_output.h"
#include "read_correct_figures.h"
#include "figure_array.h"
#include "isotropic_scale.h"

int main()
{
  std::string figure = "";
  size_t size = 0;
  point_t point{};
  double coefficient = 0;
  bool isScale = false;
  bool isCommand = true;
  Shape** array_figures = new Shape*[size];
  do
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      Shape* rectangle = nullptr;
      try
      {
        rectangle = correctFigures::readCorrectRectangle(std::cin);
        if (rectangle)
        {
          FigureArray::ExtendArray(array_figures, rectangle, size);
          size++;
        }
        else
        {
          delete rectangle;
          isCommand = false;
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        delete rectangle;
        isCommand = false;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error while reading the rectangle\n";
        FigureArray::DeleteArray(size, array_figures);
        return 2;
      }
    }

    if (figure == "RING")
    {
      Shape* ring = nullptr;
      try
      {
        ring = correctFigures::readCorrectRing(std::cin);
        if (ring)
        {
          FigureArray::ExtendArray(array_figures, ring, size);
          size++;
        }
        else
        {
          delete ring;
          isCommand = false;
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        delete ring;
        isCommand = false;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error while reading the ring\n";
        FigureArray::DeleteArray(size, array_figures);
        return 2;
      }
    }

    if (figure == "ELLIPSE")
    {
      Shape* ellipse = nullptr;
      try
      {
        ellipse = correctFigures::readCorrectEllipse(std::cin);
        if (ellipse)
        {
          FigureArray::ExtendArray(array_figures, ellipse, size);
          size++;
        }
        else
        {
          delete ellipse;
          isCommand = false;
        }
      }
      catch (const std::invalid_argument& e)
      {
        std::cerr << e.what() << "\n";
        delete ellipse;
        isCommand = false;
        continue;
      }
      catch (...)
      {
        std::cerr << "Error while reading the ellipse\n";
        FigureArray::DeleteArray(size, array_figures);
        return 2;
      }
    }

    if (figure == "SCALE")
    {
      try
      {
        std::cin >> point.x >> point.y >> coefficient;
        if (coefficient <= 0)
        {
          std::cerr << "Error: coefficient could not be under zero\n";
          FigureArray::DeleteArray(size, array_figures);
          return 2;
        }
        else if (size > 0 && coefficient > 0)
        {
          isScale = true;
        }
      }
      catch (...)
      {
        std::cerr << "Error: wrong parameters of the point, coefficient\n";
        FigureArray::DeleteArray(size, array_figures);
        return 2;
      }
      break;
    }
  }
  while (std::cin);

  if (size > 0 && isScale)
  {
    makeOutput(std::cout, array_figures, size);
    for (size_t i = 0; i < size; i++)
    {
      makeIsotropicScaling(array_figures[i], point, coefficient);
    }
    makeOutput(std::cout, array_figures, size);
    if (!isCommand)
    {
      std::cerr << "Some figures are not correct\n";
    }
  }
  else if (!isScale)
  {
    FigureArray::DeleteArray(size, array_figures);
    std::cerr << "Error: the final figure could be SCALE and size bigger than zero";
    return 2;
  }
  FigureArray::DeleteArray(size, array_figures);
  return 0;
}
