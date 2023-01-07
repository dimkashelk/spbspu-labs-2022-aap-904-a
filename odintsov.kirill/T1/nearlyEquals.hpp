#ifndef NEARLYEQUALS_HPP
#define NEARLYEQUALS_HPP

namespace odintsov {
  bool nearlyEquals(double a, double b, double epsilon);
  bool nearlyEquals(const point_t& a, const point_t& b, double epsilon);
}

#endif
