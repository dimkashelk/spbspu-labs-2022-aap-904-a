#include <iostream>

class Shape
{
public:
  Shape()
  {
    std::cout << "Shape" << '\n';
  }
};

class Rectangle: public Shape
{
public:
  Rectangle()
  {
    std::cout << "rectangle" << '\n';
  }
};

class Triangle: public Shape
{
public:
  Triangle()
  {
    std::cout << "Triangle" << '\n';
  }
};

class Complexquad: virtual public Shape
{
public:
  Complexquad()
  {
    std::cout << "Complexquad" << '\n';
  }
};

class Сircle: virtual public Shape
{
public:
  Сircle()
  {
    std::cout << "Сircle" << '\n';
  }
};

class multipleInheritance: public Rectangle, public Triangle
{
public:
  multipleInheritance()
  {
    std::cout << "Multiple Inheritance";
  }
};

class virtualiInheritance: public Complexquad, public Сircle
{
public:
  virtualiInheritance()
  {
    std::cout << "Virtual inheritance";
  }
};

int main()
{
  multipleInheritance multipleInheritance_;
  virtualiInheritance virtualiInheritance_;
}

// Multiple Inheritance
// output: Shape
//        rectangle
//        Shape
//        Triangle
//        Multiple Inheritance

//virtual inheritance
//output: Shape
//       Complexquad
//       Сircle
//       Virtual inheritance
