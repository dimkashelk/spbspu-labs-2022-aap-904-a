#include <iostream>

// Multiple Inheritance
// output: Shape
//        rectangle
//        Shape
//        Triangle
//        Figures

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

class Figures : public Rectangle, public Triangle
{
public:
  Figures()
  {
    std::cout << "Figures";
  }
};

int main()
{
  Figures figures_;
}

//virtual inheritance
//output: Shape
//       rectangle
//       Triangle
//       Figures

class Shape
{
public:
  Shape()
  {
    std::cout << "Shape" << '\n';
  }
};

class Rectangle: virtual public Shape
{
public:
  Rectangle()
  {
    std::cout << "rectangle" << '\n';
  }
};

class Triangle: virtual public Shape
{
public:
  Triangle()
  {
    std::cout << "Triangle" << '\n';
  }
};

class Figures : public Rectangle, public Triangle
{
public:
  Figures()
  {
    std::cout << "Figures";
  }
};

int main()
{
  Figures figures_;
}
