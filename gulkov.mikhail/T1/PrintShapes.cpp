#include "PrintShapes.hpp"
#include <iomanip>

void printShapesArea(std::ostream &out, const CompositeShape &compositeShape)
{
  out << std::setprecision(1) << std::fixed << compositeShape.getArea() << " ";
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    rectangle_t temp = compositeShape.at(i)->getFrameRect();
    out << temp.pos.x - (temp.width / 2.0) << " ";
    out << temp.pos.y - (temp.height / 2.0) << " ";
    out << temp.pos.x + (temp.width / 2.0) << " ";
    out << temp.pos.y + (temp.height / 2.0);

    if (i + 1 != compositeShape.size())
    {
      out << " ";
    }
  }

  out << "\n";
}
