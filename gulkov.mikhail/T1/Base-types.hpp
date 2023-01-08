#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x, y;
};

struct rectangle_t
{
  point_t pos;
  double width, height;
};

struct scale_t
{
  point_t pos;
  double scale;
};


double calcVectorLength(const point_t &p1, const point_t &p2);
bool validateConcave(const point_t &one, const point_t &two, const point_t &three, const point_t &four);
point_t addVector(point_t dot, double dx, double dy);

#endif
