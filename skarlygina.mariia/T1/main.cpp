#include <iostream>
#include "shape.h"
#include "make_output.h"
#include "read_correct_figures.h"
#include "isotropic_scale.h"

int main()
{
  std::string figure = "";
  size_t size = 0;
  point_t point{};
  double coefficient = 0;
  bool isCorrectFigure = true;
  bool isScale = false;
  bool isCommand = true;
  Shape** array_figures = new Shape*[10];
  do
  {
    std::cin >> figure;
    if (figure == "RECTANGLE")
    {
      Shape* rectangle = nullptr;
      isCorrectFigure = true;
      try
      {
        rectangle = correctFigures::readCorrectRectangle(std::cin);
        if (rectangle)
        {
          array_figures[size] = rectangle;
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
        if (size > 0)
        {
          for (size_t i = 0; i < size; i++)
          {
            delete array_figures[i];
          }
        }
        delete[] array_figures;
        return 2;
      }
    }

    if (figure == "RING")
    {
      Shape* ring = nullptr;
      isCorrectFigure = true;
      try
      {
        ring = correctFigures::readCorrectRing(std::cin);
        if (ring)
        {
          array_figures[size] = ring;
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
        if (size > 0)
        {
          for (size_t i = 0; i < size; i++)
          {
            delete array_figures[i];
          }
        }
        delete[] array_figures;
        return 2;
      }
    }

    if (figure == "ELLIPSE")
    {
      Shape* ellipse = nullptr;
      isCorrectFigure = true;
      try
      {
        ellipse = correctFigures::readCorrectEllipse(std::cin);
        if (ellipse)
        {
          array_figures[size] = ellipse;
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
        if (size > 0)
        {
          for (size_t i = 0; i < size; i++)
          {
            delete array_figures[i];
          }
        }
        delete[] array_figures;
        return 2;
      }
    }

    if (figure == "SCALE")
    {
      try
      {
        std::cin >> point.x >> point.y >> coefficient;
        if (coefficient <= 0 && size >= 1)
        {
          std::cerr << "Error: coefficient could not be under zero\n";
          for (size_t i = 0; i < size; i++)
          {
            delete array_figures[i];
          }
          delete[] array_figures;
          return 2;
        }
        else if (coefficient <= 0 && size < 1)
        {
          std::cerr << "Error: coefficient and number of figures could not be under zero\n";
          delete[] array_figures;
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
  else if (size > 0 && !isScale)
  {
    for (size_t i = 0; i < size; i++)
    {
      delete array_figures[i];
    }
    delete[] array_figures;
    std::cerr << "Error: the final figure could be SCALE";
    return 2;
  }
  else if (!size && !isScale)
  {
    delete[] array_figures;
    std::cerr << "Error: size could not be under zero";
    return 2;
  }
  for (size_t i = 0; i < size; i++)
  {
    delete array_figures[i];
  }
  delete[] array_figures;
  return 0;
}
