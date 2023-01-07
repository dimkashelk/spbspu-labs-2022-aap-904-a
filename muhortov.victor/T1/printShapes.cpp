#include "printShapes.hpp"
#include <iomanip>
#include "rectangle.hpp"

void printRectangle(std::ostream &output, Shape *shape)
{
  rectangle_t temp = shape->getFrameRect();
  output << temp.pos.x - (temp.width / 2.0) << " ";
  output << temp.pos.y - (temp.height / 2.0) << " ";
  output << temp.pos.x + (temp.width / 2.0) << " ";
  output << temp.pos.y + (temp.height / 2.0);
}

void printAreaSum(std::ostream &output, const CompositeShape &compositeShape)
{
  output << std::setprecision(1) << std::fixed << compositeShape.getArea() << " ";
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    printRectangle(output, compositeShape.at(i));
    if (i + 1 != compositeShape.size())
    {
      output << " ";
    }
  }

  output << "\n";
}
