#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle: public Shape
{
 public:
  Trinagle(const point_t &point1, const point_t &point2, const point_t &point3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &pos) override;
  void scale(double k);
  virtual ~Triangle() = default;
 private:
  point_t p1_, p2_, p3_;
};
#endif
