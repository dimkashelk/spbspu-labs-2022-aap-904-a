#include "outputframerect.hpp"
#include "base-func.hpp"

void tarasenko::outputFrameRect(std::ostream & output, const tarasenko::rectangle_t & rect)
{
  tarasenko::point_t point_ld = getPointLDRect(rect);
  tarasenko::point_t point_ru = getPointRURect(rect);
  output << point_ld.x_ << " " << point_ld.y_ << " " << point_ru.x_ << " " << point_ru.y_;
}
