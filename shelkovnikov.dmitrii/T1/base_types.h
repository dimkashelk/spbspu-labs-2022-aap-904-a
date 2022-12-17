#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
struct point_t
{
  double x;
  double y;
  point_t(double x, double y);
  point_t(const point_t &point);
};
struct rectangle_t
{
  point_t point;
  double width;
  double height;
  rectangle_t(double x1, double y1, double x2, double y2);
  rectangle_t(point_t point, double width, double height);
  point_t getLeftDownPoint() const;
};
struct vector_t
{
  double x;
  double y;
  vector_t(double x, double y);
  vector_t(point_t point_1, point_t point_2);
  vector_t& operator*=(double k);
  double getLength() const;
}
#endif
