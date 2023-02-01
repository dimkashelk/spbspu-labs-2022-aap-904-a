#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:
  virtual std::string getName() const = 0;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(point_t point) = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void scale(double k) = 0;
  virtual Shape* clone() const = 0;
};

#endif
