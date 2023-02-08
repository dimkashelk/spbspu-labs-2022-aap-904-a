#include <iostream>

// множественное наследование 
// вывод: Shape
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

//виртульаное наследование
//вывод: Shape
//       rectangle
//       Triangle
//       Figures
// изначально идея была в том, чтобы класс shape не дублировался как в прошлом варианте,
// но я уже поняла, что для данной работы это не играет особой роли 

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
