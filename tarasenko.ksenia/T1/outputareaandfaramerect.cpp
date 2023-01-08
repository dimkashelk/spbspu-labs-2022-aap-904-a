#include "outputareaandfaramerect.hpp"
#include <iomanip>
#include "outputframerect.hpp"

void tarasenko::outputArea(std::ostream & output, tarasenko::CompositeShape & c_shp)
{
  double area = 0.0;
  for (size_t i = 0; i < c_shp.size(); i++)
  {
    area += c_shp[i]->getArea();
  }
  output << area;
}
void tarasenko::outputFrameRect(std::ostream & output, CompositeShape & c_shp)
{
  for (size_t i = 0; i < c_shp.size(); i++)
  {
    tarasenko::outputFrameRect(output, c_shp[i]->getFrameRect());
    std::cout << " ";
  }
}
void tarasenko::outputAreaAndFrameRect(std::ostream & output, tarasenko::CompositeShape & c_shp)
{
  output << std::setprecision(1) << std::fixed;
  tarasenko::outputArea(output, c_shp);
  output << " ";
  tarasenko::outputFrameRect(output, c_shp);
}
