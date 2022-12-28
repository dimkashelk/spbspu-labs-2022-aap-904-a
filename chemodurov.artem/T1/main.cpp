#include <iostream>
#include <string>
#include "polygon.hpp"
#include "square.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "iso-scale.hpp"
#include "print-summ-area-and-frames.hpp"
#include "extend-shape-ptr-array.hpp"
#include "make-polygon-from-string.hpp"
#include "is-repeating-points-in-array.hpp"

int main()
{
  std::string line;
  size_t shp_cap = 3;
  size_t shp_size = 0;
  chemodurov::Shape ** shp = new chemodurov::Shape*[shp_cap];
  for (size_t i = 0; i < shp_cap; ++i)
  {
    shp[i] = nullptr;
  }
  chemodurov::point_t iso_scale_center;
  double iso_scale_coeff = 0;
  do
  {
    if (shp_size == shp_cap)
    {
      try
      {
        chemodurov::Shape ** new_shp = chemodurov::extendShapePtrArray(shp, shp_cap, shp_cap + 3);
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        shp_cap += 3;
        shp = new_shp;
      }
      catch (...)
      {
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        std::cerr << "Error...\n";
        return 1;
      }
    }

    std::getline(std::cin, line);
    if (!line.compare(0, 7, "POLYGON"))
    {
      chemodurov::point_t * arr = nullptr;
      try
      {
        size_t arr_size = 0;
        arr = chemodurov::getArrayOfPoints(line, arr_size);
        if (arr_size < 3 || chemodurov::isRepeatingPointsInArray(arr, arr_size))
        {
          std::cerr << "Error in description of shape\n";
          delete [] arr;
          continue;
        }
        shp[shp_size++] = chemodurov::makePolygonFromPoints(arr, arr_size);
        arr = nullptr;
      }
      catch (...)
      {
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        delete [] arr;
        std::cerr << "Error...\n";
        return 1;
      }
      continue;
    }

    if (!line.compare(0, 6, "SQUARE"))
    {
      try
      {
        std::string::size_type size1 = 6;
        std::string::size_type size2;
        double x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        double y = std::stod(line.substr(size2), &size1);
        size1 += size2;
        chemodurov::point_t temp{x, y};
        double length = std::stod(line.substr(size1));
        if (length <= 0)
        {
          std::cerr << "Error in description of shape\n";
          continue;
        }
        shp[shp_size++] = new chemodurov::Square(temp, length);
      }
      catch (...)
      {
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        std::cerr << "Error...\n";
        return 1;
      }
      continue;
    }

    if (!line.compare(0, 9, "RECTANGLE"))
    {
      try
      {
        std::string::size_type size1 = 9;
        std::string::size_type size2;
        double x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        double y = std::stod(line.substr(size2), &size1);
        size1 += size2;
        chemodurov::point_t left_down{x, y};
        x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        y = std::stod(line.substr(size2), &size1);
        chemodurov::point_t right_up{x, y};
        if (left_down.x >= right_up.x || left_down.y >= right_up.y)
        {
          std::cerr << "Error in description of shape\n";
          continue;
        }
        shp[shp_size++] = new chemodurov::Rectangle(left_down, right_up);
      }
      catch (...)
      {
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        std::cerr << "Error...\n";
        return 1;
      }
      continue;
    }

    if (!line.compare(0, 13, "PARALLELOGRAM"))
    {
      try
      {
        std::string::size_type size1 = 13;
        std::string::size_type size2;
        double x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        double y = std::stod(line.substr(size2), &size1);
        size1 += size2;
        chemodurov::point_t fst{x, y};
        x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        y = std::stod(line.substr(size2), &size1);
        size1 += size2;
        chemodurov::point_t sec{x, y};
        x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        y = std::stod(line.substr(size2), &size1);
        size1 += size2;
        chemodurov::point_t trd{x, y};
        if (fst.y != sec.y && sec.y != trd.y)
        {
          std::cerr << "Error in description of shape\n";
          continue;
        }
        shp[shp_size++] = new chemodurov::Parallelogram(fst, sec, trd);
      }
      catch (...)
      {
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        std::cerr << "Error...\n";
        return 1;
      }
      continue;
    }

    if (!line.compare(0, 5, "SCALE"))
    {
      try
      {
        std::string::size_type size1 = 5;
        std::string::size_type size2 = 0;
        double x = std::stod(line.substr(size1), &size2);
        size2 += size1;
        double y = std::stod(line.substr(size2), &size1);
        size1 += size2;
        iso_scale_coeff = std::stod(line.substr(size1));
        iso_scale_center = {x, y};
      }
      catch (...)
      {
        for (size_t i = 0; i < shp_cap; ++i)
        {
          delete shp[i];
        }
        delete [] shp;
        std::cerr << "Error...\n";
        return 1;
      }
      break;
    }
  }
  while (std::cin);

  if (!std::cin || !shp_size || !iso_scale_coeff)
  {
    for (size_t i = 0; i < shp_cap; ++i)
    {
      delete shp[i];
    }
    delete [] shp;
    std::cerr << "Error...\n";
    return 1;
  }

  try
  {
    chemodurov::printSummAreaAndFrames(std::cout, shp, shp_size);
    std::cout << "\n";
  }
  catch (...)
  {
    for (size_t i = 0; i < shp_cap; ++i)
    {
      delete shp[i];
    }
    delete [] shp;
    std::cerr << "Error...\n";
    return 1;
  }

  for (size_t i = 0; i < shp_size; ++i)
  {
    isoScale(shp[i], iso_scale_center, iso_scale_coeff);
  }

  try
  {
    chemodurov::printSummAreaAndFrames(std::cout, shp, shp_size);
    std::cout << "\n";
  }
  catch (...)
  {
    for (size_t i = 0; i < shp_cap; ++i)
    {
      delete shp[i];
    }
    delete [] shp;
    std::cerr << "Error...\n";
    return 1;
  }

  for (size_t i = 0; i < shp_cap; ++i)
  {
    delete shp[i];
  }
  delete [] shp;
  return 0;
}
