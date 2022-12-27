#include <iostream>
#include <string>
#include <cstddef>
#include "polygon.hpp"
#include "iso-scale.hpp"
#include "print-summ-area-and-frames.hpp"

int main()
{
  std::string line;
  size_t shp_cap = 3;
  size_t shp_size = 0;
  chemodurov::Shape ** shp = new chemodurov::Shape*[shp_cap];
  for (size_t i = 0; i < shp_size; ++i)
  {
    shp[i] = nullptr;
  }
  chemodurov::point_t iso_scale_center;
  double iso_scale_coeff = 0;
  do
  {
    if (shp_size == shp_cap)
    {
      shp_cap += 3;
      chemodurov::Shape ** new_shp = new chemodurov::Shape*[shp_cap];
      for (size_t i = 0; i < shp_cap; ++i)
      {
        if (i < shp_size)
        {
          new_shp[i] = shp[i];
        }
        else
        {
          new_shp[i] = nullptr;
        }
      }
      for (size_t i = 0; i < shp_size; ++i)
      {
        delete shp[i];
      }
      delete [] shp;
      shp = new_shp;
    }
    std::getline(std::cin, line);
    if (!line.compare(0, 7, "POLYGON"))
    {
      size_t capacity = 5;
      chemodurov::point_t * arr = nullptr;
      try
      {
        arr = new chemodurov::point_t[capacity];
      }
      catch (...)
      {
        delete [] shp;
        std::cerr << "Error...\n";
        return 1;
      }
      size_t arr_size = 0;
      std::string::size_type size = 7;
      do
      {
        try
        {
          if (arr_size == capacity)
          {
            capacity += 5;
            chemodurov::point_t * new_arr = new chemodurov::point_t[capacity];
            for (size_t i = 0; i < arr_size; ++i)
            {
              new_arr[i] = arr[i];
            }
            delete [] arr;
            arr = new_arr;
          }
          std::string::size_type size1 = size;
          std::string::size_type size2;
          double x = std::stod(line.substr(size1), &size2);
          size2 += size1;
          double y = std::stod(line.substr(size2), &size1);
          size1 += size2;
          chemodurov::point_t temp{x, y};
          arr[arr_size++] = temp;
          size = size1;
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
      }
      while (size < line.size());

      try
      {
        shp[shp_size++] = new chemodurov::Polygon(arr, arr_size);
        delete [] arr;
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
      if (!iso_scale_coeff)
      {
        std::cerr << "Error...\n";
        return 1;
      }
      continue;
    }
  }
  while (std::cin && line.compare(0, 5, "SCALE"));

  if (!std::cin || !shp_size)
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
