#include <iostream>
#include "shape.h"
#include "base_types.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"

int main()
{
  kryuchkova::point_t lb(1.0, 2.0);
  kryuchkova::point_t ru(9.0, 5.0);
  kryuchkova::Shape* rectangle = new kryuchkova::Rectangle(lb, ru);
  kryuchkova::Shape* square = new kryuchkova::Square(lb, 5);
  kryuchkova::Shape* circle = new kryuchkova::Circle(lb, 5);
  std::cout << *rectangle << '\n' << *square << '\n' << *circle << '\n';
}
