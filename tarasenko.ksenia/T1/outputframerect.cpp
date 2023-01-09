#include "outputframerect.hpp"
#include "base-func.hpp"

void tarasenko::outputFrameRect(std::ostream & output, const tarasenko::rectangle_t & rect)
{
  tarasenko::point_t * points = getPointRect(rect);
  output << points[0].x_ << " " << points[0].y_ << " " << points[1].x_ << " " << points[1].y_;
}
