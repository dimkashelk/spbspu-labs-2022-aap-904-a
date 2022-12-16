#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
struct point_t
{
  double x;
  double y;
};
struct rectangle_t
{
  point_t point;
  double width;
  double height;
  rectangle_t(point_t point, double width, double height);
  point_t getLeftDownPoint() const;
};
struct vector_t
{
  double x;
  double y;
  double getLength() const;
}
#endif
