#include <iostream>
#include <string>
#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "iso-scale.hpp"
#include "print-summ-area-and-frames.hpp"
#include "make-polygon-from-string.hpp"
#include "is-repeating-points-in-array.hpp"
#include "check-command-in-string.hpp"
#include "composite-shape.hpp"

int main()
{
  std::string line;
  size_t shp_cap = 10;
  chemodurov::CompositeShape shapes(shp_cap);
  chemodurov::point_t iso_scale_center;
  double iso_scale_coeff = 0;
  const size_t polygon_size = 7;
  const size_t square_size = 6;
  const size_t rectangle_size = 9;
  const size_t parallelogram_size = 13;
  const size_t scale_size = 5;
  const size_t precision = 1;

  do
  {
    std::getline(std::cin, line);
    if (chemodurov::checkCommand(line, "POLYGON"))
    {
      chemodurov::point_t * arr = nullptr;
      size_t arr_size = 0;
      chemodurov::Shape * polygon = nullptr;
      try
      {
        arr = chemodurov::getArrayOfPoints(line, polygon_size, arr_size);
        if (arr_size < 3 || chemodurov::isRepeatingPointsInArray(arr, arr_size))
        {
          std::cerr << "Error in description of shape\n";
          delete[] arr;
          continue;
        }
        polygon = new chemodurov::Polygon(arr, arr_size);
      }
      catch (...)
      {
        std::cerr << "Error...\n";
        delete[] arr;
        return 1;
      }
      shapes.push_back(polygon);
      continue;
    }

    if (chemodurov::checkCommand(line, "SQUARE"))
    {
      std::string::size_type size1 = square_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t temp{x, y};
      double length = std::stod(line.substr(size1));
      if (length <= 0)
      {
        std::cerr << "Error in description of shape\n";
        continue;
      }
      shapes.push_back(new chemodurov::Square(temp, length));
      continue;
    }

    if (chemodurov::checkCommand(line, "RECTANGLE"))
    {
      std::string::size_type size1 = rectangle_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t left_down{x, y};
      x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      y = std::stod(line.substr(size2), std::addressof(size1));
      chemodurov::point_t right_up{x, y};
      if (left_down.x >= right_up.x || left_down.y >= right_up.y)
      {
        std::cerr << "Error in description of shape\n";
        continue;
      }
      shapes.push_back(new chemodurov::Rectangle(left_down, right_up));

      continue;
    }

    if (chemodurov::checkCommand(line, "PARALLELOGRAM"))
    {
      std::string::size_type size1 = parallelogram_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t fst{x, y};
      x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t sec{x, y};
      x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      chemodurov::point_t trd{x, y};
      if ((fst.y != sec.y && sec.y != trd.y) || fst == sec || sec == trd)
      {
        std::cerr << "Error in description of shape\n";
        continue;
      }
      shapes.push_back(new chemodurov::Parallelogram(fst, sec, trd));
      continue;
    }

    if (chemodurov::checkCommand(line, "SCALE"))
    {
      std::string::size_type size1 = scale_size;
      std::string::size_type size2 = 0;
      double x = std::stod(line.substr(size1), std::addressof(size2));
      size2 += size1;
      double y = std::stod(line.substr(size2), std::addressof(size1));
      size1 += size2;
      iso_scale_coeff = std::stod(line.substr(size1));
      iso_scale_center = {x, y};
      break;
    }
  } while (std::cin);

  if (!std::cin || !shapes.size() || iso_scale_coeff <= 0)
  {
    std::cerr << "Error...\n";
    return 1;
  }
  chemodurov::printSummAreaAndFrames(std::cout, precision,  shapes, shapes.size());
  std::cout << "\n";

  for (size_t i = 0; i < shapes.size(); ++i)
  {
    isoScale(shapes[i], iso_scale_center, iso_scale_coeff);
  }
  chemodurov::printSummAreaAndFrames(std::cout, precision, shapes, shapes.size());
  std::cout << "\n";
  return 0;
}
